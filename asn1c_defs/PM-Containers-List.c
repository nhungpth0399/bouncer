/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "E2SM-KPM-v1.0.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -R`
 */

#include "PM-Containers-List.h"

#include "PF-Container.h"
asn_TYPE_member_t asn_MBR_PM_Containers_List_1[] = {
	{ ATF_POINTER, 2, offsetof(struct PM_Containers_List, performanceContainer),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_PF_Container,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"performanceContainer"
		},
	{ ATF_POINTER, 1, offsetof(struct PM_Containers_List, theRANContainer),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RAN_Container,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"theRANContainer"
		},
};
static const int asn_MAP_PM_Containers_List_oms_1[] = { 0, 1 };
static const ber_tlv_tag_t asn_DEF_PM_Containers_List_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PM_Containers_List_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* performanceContainer */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* theRANContainer */
};
asn_SEQUENCE_specifics_t asn_SPC_PM_Containers_List_specs_1 = {
	sizeof(struct PM_Containers_List),
	offsetof(struct PM_Containers_List, _asn_ctx),
	asn_MAP_PM_Containers_List_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_PM_Containers_List_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PM_Containers_List = {
	"PM-Containers-List",
	"PM-Containers-List",
	&asn_OP_SEQUENCE,
	asn_DEF_PM_Containers_List_tags_1,
	sizeof(asn_DEF_PM_Containers_List_tags_1)
		/sizeof(asn_DEF_PM_Containers_List_tags_1[0]), /* 1 */
	asn_DEF_PM_Containers_List_tags_1,	/* Same as above */
	sizeof(asn_DEF_PM_Containers_List_tags_1)
		/sizeof(asn_DEF_PM_Containers_List_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PM_Containers_List_1,
	2,	/* Elements count */
	&asn_SPC_PM_Containers_List_specs_1	/* Additional specs */
};

