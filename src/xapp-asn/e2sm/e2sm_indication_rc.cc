/*
# ==================================================================================
# Copyright (c) 2020 HCL Technologies Limited.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==================================================================================
*/


/* 
Author : Chu Hieu, Cuong Nguyen
Classes to handle E2SM Indication RC service model based on E2SM-RC-v1.0.asn 
*/

#include "e2sm_indication_rc.hpp"

e2sm_indication_rc::e2sm_indication_rc(void){
    /*Set up memory allocations for each IE for encoding*/
    indication_header = 0;
    indication_header = (E2SM_RC_IndicationHeader_t *)calloc(1, sizeof(E2SM_RC_IndicationHeader_t));
    assert(indication_header != 0);

    indication_message = 0;
    indication_message = (E2SM_RC_IndicationMessage_t *)calloc(1, sizeof(E2SM_RC_IndicationMessage_t));
    assert(indication_message !=0);

    errbuf_len = 128;
}

e2sm_indication_rc::~e2sm_indication_rc(void){
    /*Clear assigned protocolIE list from RIC indication IE container*/
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_IndicationHeader, indication_header);
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_IndicationMessage, indication_message);

    free(indication_header);
    free(indication_message);
}

bool e2sm_indication_rc::decode_indication_header(unsigned char *buf, size_t *size){
    /*decode control request header*/
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_IndicationHeader, indication_header);
    
    bool res = true;
    asn_dec_rval_t decode_val;

    decode_val = asn_decode(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_IndicationHeader, (void**)&indication_header, buf, *size);
    switch (decode_val.code)
    {
        case RC_OK:
            mdclog_write(MDCLOG_INFO, "RC_OK");
            // printf("RC OK\n");
            break;

        case RC_WMORE:
            mdclog_write(MDCLOG_ERR, "RC_WMORE");
            // printf("RC WMORE\n");
            res = false;
            break;

        case RC_FAIL:
            mdclog_write(MDCLOG_ERR, "RC_FAIL");
            // printf("RC FAIL\n");
			res = false;
            break;

        default:
            break;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_RC_IndicationHeader, indication_header);
    return res;
}

bool e2sm_indication_rc::decode_indication_message(unsigned char *buf, size_t *size){
    /*decode control request header*/
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_IndicationMessage, indication_message);
    
    bool res = true;
    asn_dec_rval_t decode_val;

    decode_val = asn_decode(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_IndicationMessage, (void**)&indication_message, buf, *size);
    switch (decode_val.code)
    {
        case RC_OK:
            mdclog_write(MDCLOG_INFO, "RC_OK");
            // printf("RC OK\n");
            break;

        case RC_WMORE:
            mdclog_write(MDCLOG_ERR, "RC_WMORE");
            // printf("RC WMORE\n");
            res = false;
            break;

        case RC_FAIL:
            mdclog_write(MDCLOG_ERR, "RC_FAIL");
            // printf("RC FAIL\n");
			res = false;
            break;

        default:
            break;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_RC_IndicationMessage, indication_message);
    return res;
}

// bool e2sm_indication_rc::get_fields(E2SM_RC_IndicationHeader_t * ref_indictaion_header, e2sm_indication_rc_helper &helper){

//     return true;
// }

// bool e2sm_indication_rc::get_fields(E2SM_RC_IndicationMessage_t * ref_indication_message, e2sm_indication_rc_helper &helper){
    
// 	return true;
// }