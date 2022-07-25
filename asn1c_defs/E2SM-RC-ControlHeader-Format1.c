/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#include "E2SM-RC-ControlHeader-Format1.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_per_constraints_t asn_PER_type_ric_ControlDecision_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_ric_ControlDecision_value2enum_5[] = {
	{ 0,	6,	"accept" },
	{ 1,	6,	"reject" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_ric_ControlDecision_enum2value_5[] = {
	0,	/* accept(0) */
	1	/* reject(1) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_ric_ControlDecision_specs_5 = {
	asn_MAP_ric_ControlDecision_value2enum_5,	/* "tag" => N; sorted by tag */
	asn_MAP_ric_ControlDecision_enum2value_5,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_ric_ControlDecision_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ric_ControlDecision_5 = {
	"ric-ControlDecision",
	"ric-ControlDecision",
	&asn_OP_NativeEnumerated,
	asn_DEF_ric_ControlDecision_tags_5,
	sizeof(asn_DEF_ric_ControlDecision_tags_5)
		/sizeof(asn_DEF_ric_ControlDecision_tags_5[0]) - 1, /* 1 */
	asn_DEF_ric_ControlDecision_tags_5,	/* Same as above */
	sizeof(asn_DEF_ric_ControlDecision_tags_5)
		/sizeof(asn_DEF_ric_ControlDecision_tags_5[0]), /* 2 */
	{ 0, &asn_PER_type_ric_ControlDecision_constr_5, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ric_ControlDecision_specs_5	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_E2SM_RC_ControlHeader_Format1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_ControlHeader_Format1, ueID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_UEID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ueID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_ControlHeader_Format1, ric_Style_Type),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_Style_Type,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-Style-Type"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_ControlHeader_Format1, ric_ControlAction_ID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_ControlAction_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlAction-ID"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_ControlHeader_Format1, ric_ControlDecision),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ric_ControlDecision_5,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlDecision"
		},
};
static const int asn_MAP_E2SM_RC_ControlHeader_Format1_oms_1[] = { 3 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_ControlHeader_Format1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_ControlHeader_Format1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ueID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ric-Style-Type */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ric-ControlAction-ID */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* ric-ControlDecision */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_ControlHeader_Format1_specs_1 = {
	sizeof(struct E2SM_RC_ControlHeader_Format1),
	offsetof(struct E2SM_RC_ControlHeader_Format1, _asn_ctx),
	asn_MAP_E2SM_RC_ControlHeader_Format1_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_ControlHeader_Format1_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_ControlHeader_Format1 = {
	"E2SM-RC-ControlHeader-Format1",
	"E2SM-RC-ControlHeader-Format1",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_ControlHeader_Format1_tags_1,
	sizeof(asn_DEF_E2SM_RC_ControlHeader_Format1_tags_1)
		/sizeof(asn_DEF_E2SM_RC_ControlHeader_Format1_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_ControlHeader_Format1_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_ControlHeader_Format1_tags_1)
		/sizeof(asn_DEF_E2SM_RC_ControlHeader_Format1_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_ControlHeader_Format1_1,
	4,	/* Elements count */
	&asn_SPC_E2SM_RC_ControlHeader_Format1_specs_1	/* Additional specs */
};

