/*
 * Copyright (C) 1998-2000  Internet Software Consortium.
 * 
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

/* $Id: result.h,v 1.61 2000/07/13 02:41:20 bwelling Exp $ */

#ifndef DNS_RESULT_H
#define DNS_RESULT_H 1

#include <isc/lang.h>
#include <isc/resultclass.h>

#include <dns/types.h>

/*
 * Nothing in this file truly depends on <isc/result.h>, but the
 * DNS result codes are considered to be publicly derived from
 * the ISC result codes, so including this file buys you the ISC_R_
 * namespace too.
 */
#include <isc/result.h>		/* Contractual promise. */

/*
 * DNS library result codes
 */
#define DNS_R_LABELTOOLONG		(ISC_RESULTCLASS_DNS + 0)
#define DNS_R_BADESCAPE			(ISC_RESULTCLASS_DNS + 1)
#define DNS_R_BADBITSTRING		(ISC_RESULTCLASS_DNS + 2)
#define DNS_R_BITSTRINGTOOLONG		(ISC_RESULTCLASS_DNS + 3)
#define DNS_R_EMPTYLABEL		(ISC_RESULTCLASS_DNS + 4)
#define DNS_R_BADDOTTEDQUAD		(ISC_RESULTCLASS_DNS + 5)
#define DNS_R_INVALIDNS			(ISC_RESULTCLASS_DNS + 6)
#define DNS_R_UNKNOWN			(ISC_RESULTCLASS_DNS + 7)
#define DNS_R_BADLABELTYPE		(ISC_RESULTCLASS_DNS + 8)
#define DNS_R_BADPOINTER		(ISC_RESULTCLASS_DNS + 9)
#define DNS_R_TOOMANYHOPS		(ISC_RESULTCLASS_DNS + 10)
#define DNS_R_DISALLOWED		(ISC_RESULTCLASS_DNS + 11)
#define DNS_R_EXTRATOKEN		(ISC_RESULTCLASS_DNS + 12)
#define DNS_R_EXTRADATA			(ISC_RESULTCLASS_DNS + 13)
#define DNS_R_TEXTTOOLONG		(ISC_RESULTCLASS_DNS + 14)
#define DNS_R_NOTZONETOP		(ISC_RESULTCLASS_DNS + 15)
#define DNS_R_SYNTAX			(ISC_RESULTCLASS_DNS + 16)
#define DNS_R_BADCKSUM			(ISC_RESULTCLASS_DNS + 17)
#define DNS_R_BADAAAA			(ISC_RESULTCLASS_DNS + 18)
#define DNS_R_NOOWNER			(ISC_RESULTCLASS_DNS + 19)
#define DNS_R_NOTTL			(ISC_RESULTCLASS_DNS + 20)
#define DNS_R_BADCLASS			(ISC_RESULTCLASS_DNS + 21)
#define DNS_R_NAMETOOLONG		(ISC_RESULTCLASS_DNS + 22)
#define DNS_R_PARTIALMATCH		(ISC_RESULTCLASS_DNS + 23)
#define DNS_R_NEWORIGIN			(ISC_RESULTCLASS_DNS + 24)
#define DNS_R_UNCHANGED			(ISC_RESULTCLASS_DNS + 25)
#define DNS_R_BADTTL			(ISC_RESULTCLASS_DNS + 26)
#define DNS_R_NOREDATA			(ISC_RESULTCLASS_DNS + 27)
#define DNS_R_CONTINUE			(ISC_RESULTCLASS_DNS + 28)
#define DNS_R_DELEGATION		(ISC_RESULTCLASS_DNS + 29)
#define DNS_R_GLUE			(ISC_RESULTCLASS_DNS + 30)
#define DNS_R_DNAME			(ISC_RESULTCLASS_DNS + 31)
#define DNS_R_CNAME			(ISC_RESULTCLASS_DNS + 32)
#define DNS_R_BADDB			(ISC_RESULTCLASS_DNS + 33)
#define DNS_R_ZONECUT			(ISC_RESULTCLASS_DNS + 34)
#define DNS_R_BADZONE			(ISC_RESULTCLASS_DNS + 35) /* XXX MPA*/
#define DNS_R_MOREDATA			(ISC_RESULTCLASS_DNS + 36)
#define DNS_R_UPTODATE			(ISC_RESULTCLASS_DNS + 37)
#define DNS_R_TSIGVERIFYFAILURE		(ISC_RESULTCLASS_DNS + 38)
#define DNS_R_TSIGERRORSET		(ISC_RESULTCLASS_DNS + 39)
#define DNS_R_SIGINVALID		(ISC_RESULTCLASS_DNS + 40)
#define DNS_R_SIGEXPIRED		(ISC_RESULTCLASS_DNS + 41)
#define DNS_R_SIGFUTURE			(ISC_RESULTCLASS_DNS + 42)
#define DNS_R_KEYUNAUTHORIZED		(ISC_RESULTCLASS_DNS + 43)
#define DNS_R_INVALIDTIME		(ISC_RESULTCLASS_DNS + 44)
#define DNS_R_EXPECTEDTSIG		(ISC_RESULTCLASS_DNS + 45)
#define DNS_R_UNEXPECTEDTSIG		(ISC_RESULTCLASS_DNS + 46)
#define DNS_R_INVALIDTKEY		(ISC_RESULTCLASS_DNS + 47)
#define DNS_R_HINT			(ISC_RESULTCLASS_DNS + 48)
#define DNS_R_DROP			(ISC_RESULTCLASS_DNS + 49)
#define DNS_R_NOTLOADED			(ISC_RESULTCLASS_DNS + 50)
#define DNS_R_NCACHENXDOMAIN		(ISC_RESULTCLASS_DNS + 51)
#define DNS_R_NCACHENXRRSET		(ISC_RESULTCLASS_DNS + 52)
#define DNS_R_WAIT			(ISC_RESULTCLASS_DNS + 53)
#define DNS_R_NOTVERIFIEDYET		(ISC_RESULTCLASS_DNS + 54)
#define DNS_R_NOIDENTITY		(ISC_RESULTCLASS_DNS + 55)
#define DNS_R_NOJOURNAL			(ISC_RESULTCLASS_DNS + 56)
#define DNS_R_ALIAS			(ISC_RESULTCLASS_DNS + 57)
#define DNS_R_USETCP			(ISC_RESULTCLASS_DNS + 58)
#define DNS_R_NOVALIDSIG		(ISC_RESULTCLASS_DNS + 59)
#define DNS_R_NOVALIDNXT		(ISC_RESULTCLASS_DNS + 60)
#define DNS_R_NOTINSECURE		(ISC_RESULTCLASS_DNS + 61)

#define DNS_R_NRESULTS			62	/* Number of results */

/*
 * DNS wire format rcodes
 *
 * By making these their own class we can easily convert them into the
 * wire-format rcode value simply by masking off the resultclass 
 */
#define DNS_R_NOERROR			(ISC_RESULTCLASS_DNSRCODE + 0)
#define DNS_R_FORMERR			(ISC_RESULTCLASS_DNSRCODE + 1)
#define DNS_R_SERVFAIL			(ISC_RESULTCLASS_DNSRCODE + 2)
#define DNS_R_NXDOMAIN			(ISC_RESULTCLASS_DNSRCODE + 3)
#define DNS_R_NOTIMP			(ISC_RESULTCLASS_DNSRCODE + 4)
#define DNS_R_REFUSED			(ISC_RESULTCLASS_DNSRCODE + 5)
#define DNS_R_YXDOMAIN			(ISC_RESULTCLASS_DNSRCODE + 6)
#define DNS_R_YXRRSET			(ISC_RESULTCLASS_DNSRCODE + 7)
#define DNS_R_NXRRSET			(ISC_RESULTCLASS_DNSRCODE + 8)
#define DNS_R_NOTAUTH			(ISC_RESULTCLASS_DNSRCODE + 9)
#define DNS_R_NOTZONE			(ISC_RESULTCLASS_DNSRCODE + 10)
#define DNS_R_BADVERS			(ISC_RESULTCLASS_DNSRCODE + 16)

#define DNS_R_NRCODERESULTS		17	/* Number of rcode results */

#define DNS_RESULT_ISRCODE(result) \
	(ISC_RESULTCLASS_INCLASS(ISC_RESULTCLASS_DNSRCODE, (result)))

ISC_LANG_BEGINDECLS

const char *
dns_result_totext(isc_result_t);

void
dns_result_register(void);

dns_rcode_t
dns_result_torcode(isc_result_t result);

ISC_LANG_ENDDECLS

#endif /* DNS_RESULT_H */
