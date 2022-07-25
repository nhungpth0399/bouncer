/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#ifndef	_RANParameter_LIST_H_
#define	_RANParameter_LIST_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RANParameter_STRUCTURE;

/* RANParameter-LIST */
typedef struct RANParameter_LIST {
	struct RANParameter_LIST__list_of_ranParameter {
		A_SEQUENCE_OF(struct RANParameter_STRUCTURE) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} list_of_ranParameter;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANParameter_LIST_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANParameter_LIST;
extern asn_SEQUENCE_specifics_t asn_SPC_RANParameter_LIST_specs_1;
extern asn_TYPE_member_t asn_MBR_RANParameter_LIST_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _RANParameter_LIST_H_ */
#include "asn_internal.h"
