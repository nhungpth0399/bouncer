/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "E2SM-KPM-v1.0.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#include "GlobalKPMnode-ID.h"

#include "GlobalKPMnode-gNB-ID.h"
#include "GlobalKPMnode-en-gNB-ID.h"
#include "GlobalKPMnode-ng-eNB-ID.h"
#include "GlobalKPMnode-eNB-ID.h"
asn_per_constraints_t asn_PER_type_GlobalKPMnode_ID_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  3 }	/* (0..3,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_GlobalKPMnode_ID_1[] = {
	{ ATF_POINTER, 0, offsetof(struct GlobalKPMnode_ID, choice.gNB),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GlobalKPMnode_gNB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"gNB"
		},
	{ ATF_POINTER, 0, offsetof(struct GlobalKPMnode_ID, choice.en_gNB),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GlobalKPMnode_en_gNB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"en-gNB"
		},
	{ ATF_POINTER, 0, offsetof(struct GlobalKPMnode_ID, choice.ng_eNB),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GlobalKPMnode_ng_eNB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ng-eNB"
		},
	{ ATF_POINTER, 0, offsetof(struct GlobalKPMnode_ID, choice.eNB),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GlobalKPMnode_eNB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eNB"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_GlobalKPMnode_ID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gNB */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* en-gNB */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ng-eNB */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* eNB */
};
asn_CHOICE_specifics_t asn_SPC_GlobalKPMnode_ID_specs_1 = {
	sizeof(struct GlobalKPMnode_ID),
	offsetof(struct GlobalKPMnode_ID, _asn_ctx),
	offsetof(struct GlobalKPMnode_ID, present),
	sizeof(((struct GlobalKPMnode_ID *)0)->present),
	asn_MAP_GlobalKPMnode_ID_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0,
	4	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_GlobalKPMnode_ID = {
	"GlobalKPMnode-ID",
	"GlobalKPMnode-ID",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_GlobalKPMnode_ID_constr_1, CHOICE_constraint },
	asn_MBR_GlobalKPMnode_ID_1,
	4,	/* Elements count */
	&asn_SPC_GlobalKPMnode_ID_specs_1	/* Additional specs */
};

