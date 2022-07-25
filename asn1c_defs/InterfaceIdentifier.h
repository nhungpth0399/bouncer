/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "E2SM-COMMON-IEs.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_InterfaceIdentifier_H_
#define	_InterfaceIdentifier_H_


#include "asn_application.h"

/* Including external dependencies */
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum InterfaceIdentifier_PR {
	InterfaceIdentifier_PR_NOTHING,	/* No components present */
	InterfaceIdentifier_PR_nG,
	InterfaceIdentifier_PR_xN,
	InterfaceIdentifier_PR_f1,
	InterfaceIdentifier_PR_e1,
	InterfaceIdentifier_PR_s1,
	InterfaceIdentifier_PR_x2,
	InterfaceIdentifier_PR_w1
	/* Extensions may appear below */
	
} InterfaceIdentifier_PR;

/* Forward declarations */
struct InterfaceID_NG;
struct InterfaceID_Xn;
struct InterfaceID_F1;
struct InterfaceID_E1;
struct InterfaceID_S1;
struct InterfaceID_X2;
struct InterfaceID_W1;

/* InterfaceIdentifier */
typedef struct InterfaceIdentifier {
	InterfaceIdentifier_PR present;
	union InterfaceIdentifier_u {
		struct InterfaceID_NG	*nG;
		struct InterfaceID_Xn	*xN;
		struct InterfaceID_F1	*f1;
		struct InterfaceID_E1	*e1;
		struct InterfaceID_S1	*s1;
		struct InterfaceID_X2	*x2;
		struct InterfaceID_W1	*w1;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} InterfaceIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_InterfaceIdentifier;
extern asn_CHOICE_specifics_t asn_SPC_InterfaceIdentifier_specs_1;
extern asn_TYPE_member_t asn_MBR_InterfaceIdentifier_1[7];
extern asn_per_constraints_t asn_PER_type_InterfaceIdentifier_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _InterfaceIdentifier_H_ */
#include "asn_internal.h"
