/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_RANParameter_ValueType_H_
#define	_RANParameter_ValueType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANParameter_ValueType_PR {
	RANParameter_ValueType_PR_NOTHING,	/* No components present */
	RANParameter_ValueType_PR_ranP_Choice_ElementTrue,
	RANParameter_ValueType_PR_ranP_Choice_ElementFalse,
	RANParameter_ValueType_PR_ranP_Choice_Structure,
	RANParameter_ValueType_PR_ranP_Choice_List
	/* Extensions may appear below */
	
} RANParameter_ValueType_PR;

/* Forward declarations */
struct RANParameter_ValueType_Choice_ElementTrue;
struct RANParameter_ValueType_Choice_ElementFalse;
struct RANParameter_ValueType_Choice_Structure;
struct RANParameter_ValueType_Choice_List;

/* RANParameter-ValueType */
typedef struct RANParameter_ValueType {
	RANParameter_ValueType_PR present;
	union RANParameter_ValueType_u {
		struct RANParameter_ValueType_Choice_ElementTrue	*ranP_Choice_ElementTrue;
		struct RANParameter_ValueType_Choice_ElementFalse	*ranP_Choice_ElementFalse;
		struct RANParameter_ValueType_Choice_Structure	*ranP_Choice_Structure;
		struct RANParameter_ValueType_Choice_List	*ranP_Choice_List;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANParameter_ValueType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANParameter_ValueType;
extern asn_CHOICE_specifics_t asn_SPC_RANParameter_ValueType_specs_1;
extern asn_TYPE_member_t asn_MBR_RANParameter_ValueType_1[4];
extern asn_per_constraints_t asn_PER_type_RANParameter_ValueType_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _RANParameter_ValueType_H_ */
#include "asn_internal.h"
