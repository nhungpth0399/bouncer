/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_EventTrigger_UE_Info_Item_Choice_Individual_H_
#define	_EventTrigger_UE_Info_Item_Choice_Individual_H_


#include "asn_application.h"

/* Including external dependencies */
#include "UEID.h"
#include "RANParameter-Testing.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* EventTrigger-UE-Info-Item-Choice-Individual */
typedef struct EventTrigger_UE_Info_Item_Choice_Individual {
	UEID_t	 ueID;
	RANParameter_Testing_t	 ranParameterTesting;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} EventTrigger_UE_Info_Item_Choice_Individual_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EventTrigger_UE_Info_Item_Choice_Individual;
extern asn_SEQUENCE_specifics_t asn_SPC_EventTrigger_UE_Info_Item_Choice_Individual_specs_1;
extern asn_TYPE_member_t asn_MBR_EventTrigger_UE_Info_Item_Choice_Individual_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _EventTrigger_UE_Info_Item_Choice_Individual_H_ */
#include "asn_internal.h"
