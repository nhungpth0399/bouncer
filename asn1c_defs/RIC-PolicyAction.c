/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "E2SM-RC.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#include "RIC-PolicyAction.h"

#include "RIC-PolicyAction-RANParameter-Item.h"
static int
memb_ranParameters_List_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 65535)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_ranParameters_List_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_ranParameters_List_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_ranParameters_List_3[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_RIC_PolicyAction_RANParameter_Item,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_ranParameters_List_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ranParameters_List_specs_3 = {
	sizeof(struct RIC_PolicyAction__ranParameters_List),
	offsetof(struct RIC_PolicyAction__ranParameters_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ranParameters_List_3 = {
	"ranParameters-List",
	"ranParameters-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_ranParameters_List_tags_3,
	sizeof(asn_DEF_ranParameters_List_tags_3)
		/sizeof(asn_DEF_ranParameters_List_tags_3[0]) - 1, /* 1 */
	asn_DEF_ranParameters_List_tags_3,	/* Same as above */
	sizeof(asn_DEF_ranParameters_List_tags_3)
		/sizeof(asn_DEF_ranParameters_List_tags_3[0]), /* 2 */
	{ 0, &asn_PER_type_ranParameters_List_constr_3, SEQUENCE_OF_constraint },
	asn_MBR_ranParameters_List_3,
	1,	/* Single element */
	&asn_SPC_ranParameters_List_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_RIC_PolicyAction_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RIC_PolicyAction, ric_PolicyAction_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_ControlAction_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-PolicyAction-ID"
		},
	{ ATF_POINTER, 1, offsetof(struct RIC_PolicyAction, ranParameters_List),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_ranParameters_List_3,
		0,
		{ 0, &asn_PER_memb_ranParameters_List_constr_3,  memb_ranParameters_List_constraint_1 },
		0, 0, /* No default value */
		"ranParameters-List"
		},
};
static const int asn_MAP_RIC_PolicyAction_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_RIC_PolicyAction_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RIC_PolicyAction_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ric-PolicyAction-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ranParameters-List */
};
asn_SEQUENCE_specifics_t asn_SPC_RIC_PolicyAction_specs_1 = {
	sizeof(struct RIC_PolicyAction),
	offsetof(struct RIC_PolicyAction, _asn_ctx),
	asn_MAP_RIC_PolicyAction_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_RIC_PolicyAction_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RIC_PolicyAction = {
	"RIC-PolicyAction",
	"RIC-PolicyAction",
	&asn_OP_SEQUENCE,
	asn_DEF_RIC_PolicyAction_tags_1,
	sizeof(asn_DEF_RIC_PolicyAction_tags_1)
		/sizeof(asn_DEF_RIC_PolicyAction_tags_1[0]), /* 1 */
	asn_DEF_RIC_PolicyAction_tags_1,	/* Same as above */
	sizeof(asn_DEF_RIC_PolicyAction_tags_1)
		/sizeof(asn_DEF_RIC_PolicyAction_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RIC_PolicyAction_1,
	2,	/* Elements count */
	&asn_SPC_RIC_PolicyAction_specs_1	/* Additional specs */
};

