#!/bin/sh -e
#
# Copyright (C) Internet Systems Consortium, Inc. ("ISC")
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

oldid=${1:-00000}
newid=`expr \( ${oldid} + 1000 \) % 65536`
newid=`expr "0000${newid}" : '.*\(.....\)$'`
badid=`expr \( ${oldid} + 7777 \) % 65536`
badid=`expr "0000${badid}" : '.*\(.....\)$'`

SYSTEMTESTTOP=../..
. $SYSTEMTESTTOP/conf.sh

zone=example.
infile=example.db.in
zonefile=example.db

keyname1=`$KEYGEN -q -r $RANDFILE -a DSA -b 768 -n zone $zone`
keyname2=`$KEYGEN -q -r $RANDFILE -a DSA -b 768 -n zone $zone`

cat $infile $keyname1.key $keyname2.key >$zonefile
echo root-key-sentinel-is-ta-$oldid A 10.53.0.1 >> $zonefile
echo root-key-sentinel-not-ta-$oldid A 10.53.0.2 >> $zonefile
echo root-key-sentinel-is-ta-$newid A 10.53.0.3 >> $zonefile
echo root-key-sentinel-not-ta-$newid A 10.53.0.4 >> $zonefile
echo old-is-ta CNAME root-key-sentinel-is-ta-$oldid >> $zonefile
echo old-not-ta CNAME root-key-sentinel-not-ta-$oldid >> $zonefile
echo new-is-ta CNAME root-key-sentinel-is-ta-$newid >> $zonefile
echo new-not-ta CNAME root-key-sentinel-not-ta-$newid >> $zonefile
echo bad-is-ta CNAME root-key-sentinel-is-ta-$badid >> $zonefile
echo bad-not-ta CNAME root-key-sentinel-not-ta-$badid >> $zonefile

$SIGNER -P -g -r $RANDFILE -o $zone -k $keyname1 $zonefile $keyname2 > /dev/null
