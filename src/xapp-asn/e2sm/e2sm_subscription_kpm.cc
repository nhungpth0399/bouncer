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

/* Classes to handle E2 service model based on e2sm-Bouncer-v001.asn */

#include "e2sm_subscription_kpm.hpp"

 //initialize
e2sm_subscription_kpm::e2sm_subscription_kpm(void){
    
    event_trigger = 0;
    event_trigger = ( E2SM_KPM_EventTriggerDefinition_t *)calloc(1, sizeof( E2SM_KPM_EventTriggerDefinition_t));
    assert(event_trigger != 0);
    
    action_defn = 0;
    action_defn = (E2SM_KPM_ActionDefinition_t*)calloc(1, sizeof(E2SM_KPM_ActionDefinition_t));
    assert(action_defn !=0);

    event_fmt1 = 0;
    event_fmt1 = ( E2SM_KPM_EventTriggerDefinition_Format1_t *)calloc(1, sizeof( E2SM_KPM_EventTriggerDefinition_Format1_t));
    assert(event_fmt1 != 0);

    IE_array = 0;
    IE_array = (Trigger_ConditionIE_Item_t *)calloc(NUM_TRIGGER_CONDITIONIE_ITEM, sizeof(Trigger_ConditionIE_Item_t));
    assert(IE_array != 0);

    policy_list = 0;
    policy_list = (E2SM_KPM_EventTriggerDefinition_Format1__policyTest_List_t *)calloc(1, sizeof(E2SM_KPM_EventTriggerDefinition_Format1__policyTest_List_t));
    assert(policy_list != 0);
    // event_fmt1->policyTest_List = (E2SM_KPM_EventTriggerDefinition_Format1__policyTest_List *)

    event_trigger->present = E2SM_KPM_EventTriggerDefinition_PR_eventDefinition_Format1;
    event_trigger->choice.eventDefinition_Format1 = event_fmt1;
    event_fmt1->policyTest_List = policy_list;
    errbuf_len = 128;
  };

e2sm_subscription_kpm::~e2sm_subscription_kpm(void){

    mdclog_write(MDCLOG_DEBUG, "Freeing event trigger object memory");

    for(int i=0; i < policy_list->list.size; i++){
        policy_list->list.array[i] = 0;
    }

    if (policy_list->list.size > 0){
        free(policy_list->list.array);
        policy_list->list.size = 0;
        policy_list->list.count = 0;
        policy_list->list.array = 0;
    }

    free(policy_list);

    free(event_fmt1);
    free(event_trigger);

    action_defn->ric_Style_Type = 0;
    free(action_defn);
    // ASN_STRUCT_FREE(asn_DEF_E2SM_KPM_ActionDefinition, action_defn);
    // ASN_STRUCT_FREE(asn_DEF_E2SM_KPM_EventTriggerDefinition_Format1, event_fmt1);
    
    free(IE_array);

    mdclog_write(MDCLOG_DEBUG, "Freed event trigger object memory");
};

bool e2sm_subscription_kpm::encode_event_trigger(unsigned char *buf, size_t *size, e2sm_kpm_helper &helper){

    // ASN_STRUCT_RESET(asn_DEF_E2SM_KPM_EventTriggerDefinition, event_trigger);

    bool res;
    res = set_fields(event_trigger, helper);
    if (!res)
    {
        mdclog_write(MDCLOG_INFO, "Set fields failed in file= %s, line=%d",__FILE__,__LINE__);
        return false;
    }

    int ret_constr = asn_check_constraints(&asn_DEF_E2SM_KPM_EventTriggerDefinition,(void *) event_trigger, errbuf, &errbuf_len);
    if(ret_constr){
        mdclog_write(MDCLOG_INFO, "Constraint validation failed %s in file= %s, line=%d", errbuf,__FILE__,__LINE__);
        error_string.assign(&errbuf[0], errbuf_len);
        return false;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_KPM_EventTriggerDefinition, event_trigger);

    asn_enc_rval_t retval;
    retval = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_KPM_EventTriggerDefinition, \
        event_trigger, buf, *size);

    if(retval.encoded == -1){
        mdclog_write(MDCLOG_INFO, "Failed to encode in file= %s, line=%d",__FILE__,__LINE__);
        
        error_string.assign(strerror(errno));
        error_string.assign(&errbuf[0], errbuf_len);
        return false;
    }
    else if (retval.encoded > *size){
        mdclog_write(MDCLOG_INFO, "Buffer of size is too small, need %zu in file= %s, line=%d", retval.encoded,__FILE__,__LINE__);

        std::stringstream ss;
        ss  <<"Error encoding event trigger definition. Reason =  encoded pdu size " << retval.encoded << " exceeds buffer size " << *size << std::endl;
        error_string = ss.str();
        return false;
    }
    else{
        *size = retval.encoded;
    }

    mdclog_write(MDCLOG_INFO,"Encode event trigger successfully in file= %s, line=%d",__FILE__,__LINE__);
    return true;
}

bool e2sm_subscription_kpm::encode_action_defn(unsigned char *buf, size_t *size, e2sm_kpm_helper &helper){

    bool res;
    res = set_fields(action_defn, helper);
    if (!res)
    {
        mdclog_write(MDCLOG_INFO, "Set fields failed in file= %s, line=%d",__FILE__,__LINE__);
        return false;
    }


    int ret_constr = asn_check_constraints(&asn_DEF_E2SM_KPM_ActionDefinition,(void *) action_defn, errbuf, &errbuf_len);
    if(ret_constr)
    {
        mdclog_write(MDCLOG_INFO, "Constraint validation failed %s in file= %s, line=%d", errbuf,__FILE__,__LINE__);
        error_string.assign(&errbuf[0], errbuf_len);
        return false;
    }

    asn_fprint(stdout, &asn_DEF_E2SM_KPM_ActionDefinition, action_defn);

    asn_enc_rval_t retval;
    retval = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_KPM_ActionDefinition, \
        action_defn, buf, *size);

    if(retval.encoded == -1){
        mdclog_write(MDCLOG_INFO, "Failed to encode in file= %s, line=%d",__FILE__,__LINE__);

        error_string.assign(strerror(errno));
        return false;
    }
    else if (retval.encoded > *size){
        mdclog_write(MDCLOG_INFO, "Buffer of size is too small, need %zu in file= %s, line=%d", retval.encoded,__FILE__,__LINE__);
        
        std::stringstream ss;
        ss  <<"Error encoding action definition. Reason =  encoded pdu size " << retval.encoded << " exceeds buffer size " << *size << std::endl;
        error_string = ss.str();
        return false;
    }
    else{
        *size = retval.encoded;
    }
    mdclog_write(MDCLOG_INFO,"Encode action definition successfully in file= %s, line=%d",__FILE__,__LINE__);

    return true;
}

bool e2sm_subscription_kpm::set_fields(E2SM_KPM_EventTriggerDefinition_t * event_trigger, e2sm_kpm_helper & helper){

    policy_list->list.count = 0;
    int res = 0;
    Trigger_ConditionIE_Item_t* pTrigCon;
    for(int ie_index = 0; ie_index < NUM_TRIGGER_CONDITIONIE_ITEM; ie_index++){
        pTrigCon = &IE_array[ie_index];
        pTrigCon->report_Period_IE = helper.getPeriod();
        res = ASN_SEQUENCE_ADD(&(policy_list->list), &IE_array[ie_index]);
        assert(res == 0);
    }
    return true;
};

bool e2sm_subscription_kpm::set_fields(E2SM_KPM_ActionDefinition_t * action_defn, e2sm_kpm_helper & helper){
    action_defn->ric_Style_Type = helper.getRicStyle();

    return true;
};

