/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "E2SM-KPM-v1.0.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_PlmnID_List_H_
#define	_PlmnID_List_H_


#include "asn_application.h"

/* Including external dependencies */
#include "PLMN-Identity.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct FGC_CUUP_PM_Format;
struct EPC_CUUP_PM_Format;

/* PlmnID-List */
typedef struct PlmnID_List {
	PLMN_Identity_t	 pLMN_Identity;
	struct FGC_CUUP_PM_Format	*cu_UP_PM_5GC;	/* OPTIONAL */
	struct EPC_CUUP_PM_Format	*cu_UP_PM_EPC;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PlmnID_List_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PlmnID_List;
extern asn_SEQUENCE_specifics_t asn_SPC_PlmnID_List_specs_1;
extern asn_TYPE_member_t asn_MBR_PlmnID_List_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _PlmnID_List_H_ */
#include "asn_internal.h"
