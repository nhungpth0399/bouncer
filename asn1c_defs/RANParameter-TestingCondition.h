/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_RANParameter_TestingCondition_H_
#define	_RANParameter_TestingCondition_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANParameter_TestingCondition_PR {
	RANParameter_TestingCondition_PR_NOTHING,	/* No components present */
	RANParameter_TestingCondition_PR_ranP_Choice_comparison,
	RANParameter_TestingCondition_PR_ranP_Choice_presence
	/* Extensions may appear below */
	
} RANParameter_TestingCondition_PR;
typedef enum RANParameter_TestingCondition__ranP_Choice_comparison {
	RANParameter_TestingCondition__ranP_Choice_comparison_equal	= 0,
	RANParameter_TestingCondition__ranP_Choice_comparison_difference	= 1,
	RANParameter_TestingCondition__ranP_Choice_comparison_greaterthan	= 2,
	RANParameter_TestingCondition__ranP_Choice_comparison_lessthan	= 3,
	RANParameter_TestingCondition__ranP_Choice_comparison_contains	= 4,
	RANParameter_TestingCondition__ranP_Choice_comparison_starts_with	= 5
	/*
	 * Enumeration is extensible
	 */
} e_RANParameter_TestingCondition__ranP_Choice_comparison;
typedef enum RANParameter_TestingCondition__ranP_Choice_presence {
	RANParameter_TestingCondition__ranP_Choice_presence_present	= 0,
	RANParameter_TestingCondition__ranP_Choice_presence_configured	= 1,
	RANParameter_TestingCondition__ranP_Choice_presence_rollover	= 2,
	RANParameter_TestingCondition__ranP_Choice_presence_non_zero	= 3
	/*
	 * Enumeration is extensible
	 */
} e_RANParameter_TestingCondition__ranP_Choice_presence;

/* RANParameter-TestingCondition */
typedef struct RANParameter_TestingCondition {
	RANParameter_TestingCondition_PR present;
	union RANParameter_TestingCondition_u {
		long	 ranP_Choice_comparison;
		long	 ranP_Choice_presence;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANParameter_TestingCondition_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_ranP_Choice_comparison_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ranP_Choice_presence_10;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_RANParameter_TestingCondition;
extern asn_CHOICE_specifics_t asn_SPC_RANParameter_TestingCondition_specs_1;
extern asn_TYPE_member_t asn_MBR_RANParameter_TestingCondition_1[2];
extern asn_per_constraints_t asn_PER_type_RANParameter_TestingCondition_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _RANParameter_TestingCondition_H_ */
#include "asn_internal.h"
