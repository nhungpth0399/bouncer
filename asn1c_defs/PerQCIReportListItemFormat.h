/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "E2SM-KPM-v1.0.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_PerQCIReportListItemFormat_H_
#define	_PerQCIReportListItemFormat_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "INTEGER.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PerQCIReportListItemFormat */
typedef struct PerQCIReportListItemFormat {
	long	 qci;
	INTEGER_t	*pDCPBytesDL;	/* OPTIONAL */
	INTEGER_t	*pDCPBytesUL;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PerQCIReportListItemFormat_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PerQCIReportListItemFormat;
extern asn_SEQUENCE_specifics_t asn_SPC_PerQCIReportListItemFormat_specs_1;
extern asn_TYPE_member_t asn_MBR_PerQCIReportListItemFormat_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _PerQCIReportListItemFormat_H_ */
#include "asn_internal.h"
