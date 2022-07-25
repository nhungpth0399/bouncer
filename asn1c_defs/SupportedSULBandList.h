/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "E2SM-COMMON-IEs.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_SupportedSULBandList_H_
#define	_SupportedSULBandList_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SupportedSULFreqBandItem;

/* SupportedSULBandList */
typedef struct SupportedSULBandList {
	A_SEQUENCE_OF(struct SupportedSULFreqBandItem) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedSULBandList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupportedSULBandList;
extern asn_SET_OF_specifics_t asn_SPC_SupportedSULBandList_specs_1;
extern asn_TYPE_member_t asn_MBR_SupportedSULBandList_1[1];
extern asn_per_constraints_t asn_PER_type_SupportedSULBandList_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _SupportedSULBandList_H_ */
#include "asn_internal.h"
