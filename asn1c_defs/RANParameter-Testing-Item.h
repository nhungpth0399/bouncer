/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_RANParameter_Testing_Item_H_
#define	_RANParameter_Testing_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RANParameter-ID.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANParameter_Testing_Item__ranParameter_Type_PR {
	RANParameter_Testing_Item__ranParameter_Type_PR_NOTHING,	/* No components present */
	RANParameter_Testing_Item__ranParameter_Type_PR_ranP_Choice_List,
	RANParameter_Testing_Item__ranParameter_Type_PR_ranP_Choice_Structure,
	RANParameter_Testing_Item__ranParameter_Type_PR_ranP_Choice_ElementTrue,
	RANParameter_Testing_Item__ranParameter_Type_PR_ranP_Choice_ElementFalse
	/* Extensions may appear below */
	
} RANParameter_Testing_Item__ranParameter_Type_PR;

/* Forward declarations */
struct RANParameter_Testing_Item_Choice_List;
struct RANParameter_Testing_Item_Choice_Structure;
struct RANParameter_Testing_Item_Choice_ElementTrue;
struct RANParameter_Testing_Item_Choice_ElementFalse;

/* RANParameter-Testing-Item */
typedef struct RANParameter_Testing_Item {
	RANParameter_ID_t	 ranParameter_ID;
	struct RANParameter_Testing_Item__ranParameter_Type {
		RANParameter_Testing_Item__ranParameter_Type_PR present;
		union RANParameter_Testing_Item__ranParameter_Type_u {
			struct RANParameter_Testing_Item_Choice_List	*ranP_Choice_List;
			struct RANParameter_Testing_Item_Choice_Structure	*ranP_Choice_Structure;
			struct RANParameter_Testing_Item_Choice_ElementTrue	*ranP_Choice_ElementTrue;
			struct RANParameter_Testing_Item_Choice_ElementFalse	*ranP_Choice_ElementFalse;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ranParameter_Type;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANParameter_Testing_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANParameter_Testing_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_RANParameter_Testing_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_RANParameter_Testing_Item_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _RANParameter_Testing_Item_H_ */
#include "asn_internal.h"
