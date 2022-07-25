/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "E2SM-COMMON-IEs.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_CGI_H_
#define	_CGI_H_


#include "asn_application.h"

/* Including external dependencies */
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CGI_PR {
	CGI_PR_NOTHING,	/* No components present */
	CGI_PR_nR_CGI,
	CGI_PR_eUTRA_CGI
	/* Extensions may appear below */
	
} CGI_PR;

/* Forward declarations */
struct NR_CGI;
struct EUTRA_CGI;

/* CGI */
typedef struct CGI {
	CGI_PR present;
	union CGI_u {
		struct NR_CGI	*nR_CGI;
		struct EUTRA_CGI	*eUTRA_CGI;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CGI_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CGI;
extern asn_CHOICE_specifics_t asn_SPC_CGI_specs_1;
extern asn_TYPE_member_t asn_MBR_CGI_1[2];
extern asn_per_constraints_t asn_PER_type_CGI_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _CGI_H_ */
#include "asn_internal.h"
