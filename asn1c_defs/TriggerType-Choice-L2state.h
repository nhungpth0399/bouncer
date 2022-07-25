/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_TriggerType_Choice_L2state_H_
#define	_TriggerType_Choice_L2state_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RANParameter-Testing.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TriggerType-Choice-L2state */
typedef struct TriggerType_Choice_L2state {
	RANParameter_Testing_t	 associatedL2variables;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TriggerType_Choice_L2state_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TriggerType_Choice_L2state;
extern asn_SEQUENCE_specifics_t asn_SPC_TriggerType_Choice_L2state_specs_1;
extern asn_TYPE_member_t asn_MBR_TriggerType_Choice_L2state_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _TriggerType_Choice_L2state_H_ */
#include "asn_internal.h"
