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

#include "e2sm_subscription_rc.hpp"

e2sm_subscription_rc::e2sm_subscription_rc(void){
    memset(&event_trigger_rc_fmt1, 0, sizeof(E2SM_RC_EventTrigger_Format1_t));
    memset(&action_def_rc_fmt1, 0, sizeof(E2SM_RC_ActionDefinition_Format1_t));

    event_trigger_rc = 0;
    event_trigger_rc = (E2SM_RC_EventTrigger_t *)calloc(1, sizeof(E2SM_RC_EventTrigger_t));
    assert(event_trigger_rc != 0);

    action_def_rc = 0;
    action_def_rc = (E2SM_RC_ActionDefinition_t *)calloc(1, sizeof(E2SM_RC_ActionDefinition_t));
    assert(action_def_rc != 0);

    action_def_rc_fmt3 = 0;
    action_def_rc_fmt3 = (E2SM_RC_ActionDefinition_Format3_t *)calloc(1, sizeof(E2SM_RC_ActionDefinition_Format3_t));
    assert(action_def_rc_fmt3 != 0);

    event_trigger_rc_fmt1_item = 0;
    event_trigger_rc_fmt1_item = (E2SM_RC_EventTrigger_Format1_Item_t *)calloc(1, sizeof(E2SM_RC_EventTrigger_Format1_Item_t));
    assert(event_trigger_rc_fmt1_item != 0);

    action_def_rc_fmt1_item = 0;
    action_def_rc_fmt1_item = (E2SM_RC_ActionDefinition_Format1_Item_t *)calloc(1, sizeof(E2SM_RC_ActionDefinition_Format1_Item_t));
    assert(action_def_rc_fmt1_item != 0);

    action_def_rc_fmt3_item = 0;
    action_def_rc_fmt3_item = (E2SM_RC_ActionDefinition_Format3_Item_t *)calloc(1, sizeof(E2SM_RC_ActionDefinition_Format3_Item_t));
    assert(action_def_rc_fmt3_item != 0);

    action_def_rc_fmt2 = 0;
    action_def_rc_fmt2 = (E2SM_RC_ActionDefinition_Format2_t *)calloc(1, sizeof(E2SM_RC_ActionDefinition_Format2_t));
    assert(action_def_rc_fmt2 != 0);

    action_def_rc_fmt2_item = 0;
    action_def_rc_fmt2_item = (E2SM_RC_ActionDefinition_Format2_Item_t *)calloc(1, sizeof(E2SM_RC_ActionDefinition_Format2_Item_t));
    assert(action_def_rc_fmt2_item != 0);

    event_trigger_rc_fmt2 = 0;
    event_trigger_rc_fmt2 = (E2SM_RC_EventTrigger_Format2_t *)calloc(1, sizeof(E2SM_RC_EventTrigger_Format2_t) );
    assert(event_trigger_rc_fmt2 != 0);


    event_trigger_rc_fmt1_item->messageType.choice.messageType_Choice_RRC = 0;
    event_trigger_rc_fmt1_item->messageType.choice.messageType_Choice_RRC = (MessageType_Choice_RRC_t *)calloc(1, sizeof(MessageType_Choice_RRC_t));
    assert(event_trigger_rc_fmt1_item->messageType.choice.messageType_Choice_RRC != 0);

    errbuf_len = 128;
};

e2sm_subscription_rc::~e2sm_subscription_rc(void){
    event_trigger_rc ->ric_eventTrigger_formats.choice.eventTrigger_Format1 = 0;
    action_def_rc ->ric_actionDefinition_formats.choice.actionDefinition_Format1 = 0;

    if (event_trigger_rc_fmt1.message_List.list.size > 0){
        free(event_trigger_rc_fmt1.message_List.list.array);
        event_trigger_rc_fmt1.message_List.list.size = 0;
        event_trigger_rc_fmt1.message_List.list.count = 0;
        event_trigger_rc_fmt1.message_List.list.array = 0;
    }

    if (action_def_rc_fmt1.ranP_ToBeReported_List.list.size > 0){
        free(action_def_rc_fmt1.ranP_ToBeReported_List.list.array);
        action_def_rc_fmt1.ranP_ToBeReported_List.list.size = 0;
        action_def_rc_fmt1.ranP_ToBeReported_List.list.count = 0;
        action_def_rc_fmt1.ranP_ToBeReported_List.list.array = 0;
    }

    if (action_def_rc_fmt3->ranP_InsertIndication_List.list.size > 0){
        free(action_def_rc_fmt3->ranP_InsertIndication_List.list.array);
        action_def_rc_fmt3->ranP_InsertIndication_List.list.size = 0;
        action_def_rc_fmt3->ranP_InsertIndication_List.list.count = 0;
        action_def_rc_fmt3->ranP_InsertIndication_List.list.array = 0;
    }

    free(event_trigger_rc_fmt1_item->messageType.choice.messageType_Choice_RRC);
    free(event_trigger_rc_fmt1_item);
    free(action_def_rc_fmt1_item);
    action_def_rc_fmt3_item->ranParameter_ID = 0;
    free(action_def_rc_fmt3_item);
    action_def_rc_fmt3->ric_InsertIndication_ID = 0;
    free(action_def_rc_fmt3);


    free(event_trigger_rc);
    free(action_def_rc);
    // ASN_STRUCT_FREE(asn_DEF_E2SM_RC_EventTrigger, event_trigger_rc);
    // ASN_STRUCT_FREE(asn_DEF_E2SM_RC_ActionDefinition, action_def_rc);
};

bool e2sm_subscription_rc::encode_event_trigger(unsigned char *buf, size_t *size, e2sm_eve_rc_helper &helper, int format){
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_EventTrigger, event_trigger_rc);
    
    bool res;
    res = set_fields(event_trigger_rc, helper, format);
    if (!res){
        mdclog_write(MDCLOG_INFO,"Set fields false in file= %s, line=%d",__FILE__,__LINE__);
        return false;
    }
    int ret_constr_eve = asn_check_constraints(&asn_DEF_E2SM_RC_EventTrigger, event_trigger_rc, errbuf, &errbuf_len);
    if(ret_constr_eve){
        mdclog_write(MDCLOG_INFO,"Check constraints false in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(&errbuf[0], errbuf_len);
        error_string = "Constraints failed for encoding subscription request. Reason = " + error_string;
        return false;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_RC_EventTrigger, event_trigger_rc);

    asn_enc_rval_t e2sm_eve_rc = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_EventTrigger, event_trigger_rc, buf, *size);

    if(e2sm_eve_rc.encoded == -1){
        mdclog_write(MDCLOG_INFO,"Encode false 1 in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(strerror(errno));
        error_string = "Error encoding Subscription  Request. Reason = " + error_string;
        return false;
    }
    else if (e2sm_eve_rc.encoded > *size){
        mdclog_write(MDCLOG_INFO,"Encode false 2 in file= %s, line=%d",__FILE__,__LINE__);
        std::stringstream ss;
        ss  <<"Error encoding event trigger . Reason =  encoded pdu size " << e2sm_eve_rc.encoded << " exceeds buffer size " << *size << std::endl;
        error_string = ss.str();
        return false;
    }
    else {
        *size = e2sm_eve_rc.encoded;
    }
    return true;
}

bool e2sm_subscription_rc::encode_action_def(unsigned char *buf, size_t *size, e2sm_act_rc_helper &helper, int format){
    ASN_STRUCT_RESET(asn_DEF_E2SM_RC_ActionDefinition, action_def_rc);
    
    bool res;
    res = set_fields(action_def_rc, helper, format);
    if (!res){
        mdclog_write(MDCLOG_INFO,"Set fields false in file= %s, line=%d",__FILE__,__LINE__);
        return false;
    }
    int ret_constr_act = asn_check_constraints(&asn_DEF_E2SM_RC_ActionDefinition, action_def_rc, errbuf, &errbuf_len);
    if(ret_constr_act){
        mdclog_write(MDCLOG_INFO,"Check constraints false in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(&errbuf[0], errbuf_len);
        error_string = "Constraints failed for encoding subscription request. Reason = " + error_string;
        return false;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_RC_ActionDefinition, action_def_rc);

    asn_enc_rval_t e2sm_act_rc = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_ActionDefinition, action_def_rc, buf, *size);

    if(e2sm_act_rc.encoded == -1){
        mdclog_write(MDCLOG_INFO,"Encode false 1 in file= %s, line=%d",__FILE__,__LINE__);
        error_string.assign(strerror(errno));
        error_string = "Error encoding Subscription Request. Reason = " + error_string;
        return false;
    }
    else if (e2sm_act_rc.encoded > *size){
        mdclog_write(MDCLOG_INFO,"Encode false 2 in file= %s, line=%d",__FILE__,__LINE__);
        std::stringstream ss;
        ss  <<"Error encoding event trigger . Reason =  encoded pdu size " << e2sm_act_rc.encoded << " exceeds buffer size " << *size << std::endl;
        error_string = ss.str();
        return false;
    }
    else {
        *size = e2sm_act_rc.encoded;
    }
    return true;
}

bool e2sm_subscription_rc::set_fields(E2SM_RC_EventTrigger_t *ref_event_trigger_rc, e2sm_eve_rc_helper & helper, int format){
    int result = 0;
    if(ref_event_trigger_rc == 0){
        error_string = "Invalid reference for Event Action Definition set fields";
        return false;
    }

    switch(format)
    {
        case 1:
            {
                ref_event_trigger_rc->ric_eventTrigger_formats.present = E2SM_RC_EventTrigger__ric_eventTrigger_formats_PR_eventTrigger_Format1;
                message_rc_helper_t messlst = helper.get_messlist_rc();

                for(Message_rc_Helper item:messlst){
                    event_trigger_rc_fmt1_item->ric_eventTriggerCondition_ID = item.getmess_helper_rc()._con_id;
                    event_trigger_rc_fmt1_item->messageType.present = MessageType_Choice_PR_messageType_Choice_RRC;
                    event_trigger_rc_fmt1_item->messageType.choice.messageType_Choice_RRC->rRC_Message.messageID = item.getmess_helper_rc()._mess_id;
                    event_trigger_rc_fmt1_item->messageType.choice.messageType_Choice_RRC->rRC_Message.rrcType.present = RRC_MessageID__rrcType_PR_lTE;
                    event_trigger_rc_fmt1_item->messageType.choice.messageType_Choice_RRC->rRC_Message.rrcType.choice.lTE = RRCclass_LTE_bCCH_BCH;

                    result = ASN_SEQUENCE_ADD(&(event_trigger_rc_fmt1.message_List.list.array), event_trigger_rc_fmt1_item);
                    if(result == -1){
                        mdclog_write(MDCLOG_INFO,"Add event false in file= %s, line=%d",__FILE__,__LINE__);
                        error_string = "Error : Unable to assign memory to add Event item to set up list";
                        return false;
                    }
                }
                ref_event_trigger_rc->ric_eventTrigger_formats.choice.eventTrigger_Format1 = &event_trigger_rc_fmt1;
            }
            break;
        case 2:
            {
                ref_event_trigger_rc->ric_eventTrigger_formats.present = E2SM_RC_EventTrigger__ric_eventTrigger_formats_PR_eventTrigger_Format2;
                ref_event_trigger_rc->ric_eventTrigger_formats.choice.eventTrigger_Format2 = event_trigger_rc_fmt2;

                event_trigger_rc_fmt2->ric_callProcessType_ID = 1;
                event_trigger_rc_fmt2->ric_callProcessBreakpoint_ID = 1;
            }
            break;
        default:
            mdclog_write(MDCLOG_INFO, "Invalid Format");
            break;

    }

    return true;
};

bool e2sm_subscription_rc::set_fields(E2SM_RC_ActionDefinition_t *ref_action_def_rc, e2sm_act_rc_helper & helper, int format){

    int result = 0;
    if(ref_action_def_rc == 0){
        error_string = "Invalid reference for Event Action Definition set fields";
        return false;
    }

    switch(format){
        case 3:
            {
                ref_action_def_rc->ric_actionDefinition_formats.choice.actionDefinition_Format3 = action_def_rc_fmt3;
                ref_action_def_rc->ric_actionDefinition_formats.present = E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format3;
                ref_action_def_rc->ric_Style_Type = helper.ric_style_type;

                // hard coded
                action_def_rc_fmt3->ric_InsertIndication_ID = 1;

                action_def_rc_fmt3_item->ranParameter_ID = 2021;
                result = ASN_SEQUENCE_ADD(&(action_def_rc_fmt3->ranP_InsertIndication_List.list.array), action_def_rc_fmt3_item);
                if(result == -1){
                    mdclog_write(MDCLOG_INFO,"ASN_SEQ_ADD fail in file= %s, line=%d",__FILE__,__LINE__);
                    error_string = "Error : Unable to assign memory to add Action item to set up list";
                    return false;
                }
            }
            break;
        case 1:
            {
                ref_action_def_rc->ric_Style_Type = helper.ric_style_type;

                ref_action_def_rc->ric_actionDefinition_formats.present = E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format1;
                
                ranparam_rc_helper_t paramlst = helper.get_paramlist_rc();

                for(RANParam_rc_Helper item:paramlst){
                    action_def_rc_fmt1_item->ranParameter_ID = item.getran_helper_rc()._param_id;

                    result = ASN_SEQUENCE_ADD(&(action_def_rc_fmt1.ranP_ToBeReported_List.list.array), action_def_rc_fmt1_item);
                    if(result == -1){
                        mdclog_write(MDCLOG_INFO,"Add action false in file= %s, line=%d",__FILE__,__LINE__);
                        error_string = "Error : Unable to assign memory to add Action item to set up list";
                        return false;
                    }
                }

                ref_action_def_rc->ric_actionDefinition_formats.choice.actionDefinition_Format1 = &action_def_rc_fmt1;
            }
            break;
        case 2:
            {
                ref_action_def_rc->ric_Style_Type = 1; // hard coded
                ref_action_def_rc->ric_actionDefinition_formats.present = E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format2;
                ref_action_def_rc->ric_actionDefinition_formats.choice.actionDefinition_Format2 = action_def_rc_fmt2;

                action_def_rc_fmt2_item->ric_PolicyAction.ric_PolicyAction_ID = 1;
                action_def_rc_fmt2_item->ric_PolicyAction.ranParameters_List = (RIC_PolicyAction__ranParameters_List_t *)calloc(1, sizeof(RIC_PolicyAction__ranParameters_List_t) );
                
                RIC_PolicyAction_RANParameter_Item_t* ranparameter_item = (RIC_PolicyAction_RANParameter_Item *)calloc(1, sizeof(RIC_PolicyAction_RANParameter_Item) );
                ranparameter_item->ranParameter_ID = 1; //hard coded
                ranparameter_item->ranParameter_valueType.present = RANParameter_ValueType_PR_ranP_Choice_ElementTrue;
                RANParameter_ValueType_Choice_ElementTrue* pValueType = (RANParameter_ValueType_Choice_ElementTrue *)calloc(1, sizeof(RANParameter_ValueType_Choice_ElementTrue) );
                ranparameter_item->ranParameter_valueType.choice.ranP_Choice_ElementTrue = pValueType;
                pValueType->ranParameter_value.present = RANParameter_Value_PR_valueInt;
                pValueType->ranParameter_value.choice.valueInt = 1; // hard coded
                
                result = ASN_SEQUENCE_ADD( &(action_def_rc_fmt2_item->ric_PolicyAction.ranParameters_List->list.array), ranparameter_item );
                if(result == -1){
                    mdclog_write(MDCLOG_INFO,"ASN_SEQ_ADD fail in file= %s, line=%d",__FILE__,__LINE__);
                    error_string = "Error : Unable to assign memory to add item to set up list";
                    return false;
                }
                
                result = ASN_SEQUENCE_ADD(&(action_def_rc_fmt2->ric_PolicyConditions_List.list.array), action_def_rc_fmt2_item);
                if(result == -1){
                    mdclog_write(MDCLOG_INFO,"ASN_SEQ_ADD fail in file= %s, line=%d",__FILE__,__LINE__);
                    error_string = "Error : Unable to assign memory to add Action item to set up list";
                    return false;
                }
            }   
            break;
        default:
            mdclog_write(MDCLOG_INFO, "Invalid Format");
            break;
    }
    
    
    return true;
}
