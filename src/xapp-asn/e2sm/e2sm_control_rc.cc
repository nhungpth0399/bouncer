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
Author : Cuong Nguyen
Classes to handle E2SM Control RC service model based on E2SM-RC-v1.0.asn 
*/

#include "e2sm_control_rc.hpp"

e2sm_control_rc::e2sm_control_rc(void){
    // /*Set up memory allocations for each IE for encoding*/
    control_header = 0;
    control_header = (E2SM_RC_ControlHeader_t *)calloc(1, sizeof(E2SM_RC_ControlHeader_t) );
    assert(control_header != 0);

    control_message = 0;
    control_message = (E2SM_RC_ControlMessage_t *)calloc(1, sizeof(E2SM_RC_ControlMessage_t) );
    assert(control_message !=0);

    control_header_format1 = 0;
    control_header_format1 = (E2SM_RC_ControlHeader_Format1_t *)calloc(1, sizeof(E2SM_RC_ControlHeader_Format1_t) );
    errbuf_len = 128;
}

e2sm_control_rc::~e2sm_control_rc(void){
    /*Clear assigned protocolIE list from RIC indication IE container*/
    // ASN_STRUCT_RESET(asn_DEF_E2SM_RC_IndicationHeader, indication_header);
    // ASN_STRUCT_RESET(asn_DEF_E2SM_RC_IndicationMessage, indication_message);

    // free(indication_header);
    // free(indication_message);
}

bool e2sm_control_rc::encode_control_header(unsigned char *buf, size_t *size, e2sm_control_rc_helper &helper){
    /*encode control header*/
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_ControlHeader, control_header);
    
    bool res = set_fields(control_header, helper);
    if (!res){
        printf("Set fields fail in file= %s, line=%d\n",__FILE__,__LINE__);
        // mdclog_write(MDCLOG_INFO,"Set fields fail in file= %s, line=%d",__FILE__,__LINE__);
        return false;
    }

    int ret_constr = asn_check_constraints(&asn_DEF_E2SM_RC_ControlHeader, control_header, errbuf, &errbuf_len);
    if(ret_constr){
        printf("Check constraints false in file= %s, line=%d\n",__FILE__,__LINE__);
        // mdclog_write(MDCLOG_INFO,"Check constraints false in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(&errbuf[0], errbuf_len);
        error_string = "Constraints failed for encoding subscription request. Reason = " + error_string;
        return false;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_RC_ControlHeader, control_header);

    asn_enc_rval_t ret_val = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_ControlHeader, control_header, buf, *size);

    if(ret_val.encoded == -1){
        // mdclog_write(MDCLOG_INFO,"Encode false 1 in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(strerror(errno));
        error_string = "Error encoding COntrol Header. Reason = " + error_string;
        std::cout << error_string << std::endl;
        return false;
    }
    else if (ret_val.encoded > *size){
        std::cout << "Error encoding control header. Reason =  encoded pdu size " << ret_val.encoded << " exceeds buffer size " << *size << std::endl;
        // mdclog_write(MDCLOG_INFO,"Encode false 2 in file= %s, line=%d",__FILE__,__LINE__);
        std::stringstream ss;
        ss  <<"Error encoding control header. Reason =  encoded pdu size " << ret_val.encoded << " exceeds buffer size " << *size << std::endl;
        error_string = ss.str();
        return false;
    }
    else {
        *size = ret_val.encoded;
    }
    return true;
    
}

bool e2sm_control_rc::encode_control_message(unsigned char *buf, size_t *size, e2sm_control_rc_helper &helper){
    /*encode control message*/
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_ControlMessage, control_message);
    
    bool res = set_fields(control_message, helper);
    if (!res){
        // mdclog_write(MDCLOG_INFO,"Set fields fail in file= %s, line=%d",__FILE__,__LINE__);
        return false;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_RC_ControlMessage, control_message);
    int ret_constr = asn_check_constraints(&asn_DEF_E2SM_RC_ControlMessage, control_message, errbuf, &errbuf_len);
    if(ret_constr){
        // mdclog_write(MDCLOG_INFO,"Check constraints false in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(&errbuf[0], errbuf_len);
        error_string = "Constraints failed for encoding subscription request. Reason = " + error_string;
        return false;
    }


    asn_enc_rval_t ret_val = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_ControlMessage, control_message, buf, *size);

    if(ret_val.encoded == -1){
        // mdclog_write(MDCLOG_INFO,"Encode false 1 in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(strerror(errno));
        error_string = "Error encoding COntrol Header. Reason = " + error_string;
        return false;
    }
    else if (ret_val.encoded > *size){
        // mdclog_write(MDCLOG_INFO,"Encode false 2 in file= %s, line=%d",__FILE__,__LINE__);
        std::stringstream ss;
        ss  <<"Error encoding control header. Reason =  encoded pdu size " << ret_val.encoded << " exceeds buffer size " << *size << std::endl;
        error_string = ss.str();
        return false;
    }
    else {
        *size = ret_val.encoded;
    }
    return true;
}

bool e2sm_control_rc::set_fields(E2SM_RC_ControlHeader_t *ref_control_header, e2sm_control_rc_helper &helper){
    
    if(ref_control_header == 0){
        error_string = "Invalid reference for Event Action Definition set fields";
        return false;
    }
    
    ref_control_header->ric_controlHeader_formats.present = E2SM_RC_ControlHeader__ric_controlHeader_formats_PR_controlHeader_Format1;
    ref_control_header->ric_controlHeader_formats.choice.controlHeader_Format1 = control_header_format1;

    control_header_format1->ric_Style_Type = helper.getType();
    control_header_format1->ric_ControlAction_ID = helper.getControlActionID();
    control_header_format1->ueID = *(helper.getUEID());

    return true;
}

bool e2sm_control_rc::set_fields(E2SM_RC_ControlMessage_t *ref_control_message, e2sm_control_rc_helper &helper){
    
    if(ref_control_message == 0){
        error_string = "Invalid reference for Event Action Definition set fields";
        return false;
    }
    

    return true;
}