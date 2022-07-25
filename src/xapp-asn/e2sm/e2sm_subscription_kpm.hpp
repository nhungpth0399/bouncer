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


/* Classes to handle E2 service model KPM */
#ifndef E2SM_KPM
#define E2SM_KPM

#include <sstream>
#include <e2sm_kpm_helpers.hpp>
#include <mdclog/mdclog.h>
#include <vector>

#include "E2SM-KPM-EventTriggerDefinition.h"
#include "E2SM-KPM-EventTriggerDefinition-Format1.h"
#include "Trigger-ConditionIE-Item.h"
#include "RT-Period-IE.h"
#include "E2SM-KPM-ActionDefinition.h"
#include "RIC-Style-Type.h"

#define NUM_TRIGGER_CONDITIONIE_ITEM 15

struct E2SM_KPM_EventTriggerDefinition_Format1__policyTest_List;
/* builder class for E2SM event trigger definition */

class e2sm_subscription_kpm {
public:
    e2sm_subscription_kpm(void);
    ~e2sm_subscription_kpm(void);

    bool set_fields(E2SM_KPM_EventTriggerDefinition_t *, e2sm_kpm_helper &);
    bool set_fields(E2SM_KPM_ActionDefinition_t *, e2sm_kpm_helper &);

    bool encode_event_trigger(unsigned char *, size_t *, e2sm_kpm_helper &);
    bool encode_action_defn(unsigned char*, size_t *, e2sm_kpm_helper &);

    std::string get_error (void) const {return error_string ;};

private:

    E2SM_KPM_EventTriggerDefinition_t* event_trigger;
    E2SM_KPM_ActionDefinition_t* action_defn;
    E2SM_KPM_EventTriggerDefinition_Format1_t* event_fmt1;
    E2SM_KPM_EventTriggerDefinition_Format1__policyTest_List_t *policy_list;
    Trigger_ConditionIE_Item_t* IE_array;

    size_t errbuf_len;
    char errbuf[128];
    std::string error_string;
};

#endif