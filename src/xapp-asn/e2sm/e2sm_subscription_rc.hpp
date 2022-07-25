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

#ifndef E2SM_SUBSCRIPTION_RC_HPP_
#define E2SM_SUBSCRIPTION_RC_HPP_

#include <sstream>
#include <e2sm_helpers.hpp>
#include <mdclog/mdclog.h>
#include <vector>

#include "E2SM-RC-EventTrigger.h"
#include "E2SM-RC-ActionDefinition.h"
#include "E2SM-RC-EventTrigger-Format1.h"
#include "E2SM-RC-EventTrigger-Format1-Item.h"
#include "E2SM-RC-EventTrigger-Format2.h"
#include "E2SM-RC-ActionDefinition-Format1.h"
#include "E2SM-RC-ActionDefinition-Format1-Item.h"
#include "E2SM-RC-ActionDefinition-Format2.h"
#include "E2SM-RC-ActionDefinition-Format2-Item.h"
#include "E2SM-RC-ActionDefinition-Format3.h"
#include "E2SM-RC-ActionDefinition-Format3-Item.h"
#include "e2sm_rc_helper.hpp"
#include "MessageType-Choice.h"
#include "MessageType-Choice-RRC.h"
#include "RIC-PolicyAction.h"
#include "RIC-PolicyAction-RANParameter-Item.h"
#include "RANParameter-ValueType-Choice-ElementTrue.h"

class e2sm_subscription_rc{
public:
    e2sm_subscription_rc(void);
    ~e2sm_subscription_rc(void);

    bool set_fields(E2SM_RC_ActionDefinition_t *, e2sm_act_rc_helper &, int);
    bool set_fields(E2SM_RC_EventTrigger_t *, e2sm_eve_rc_helper &, int);

    bool encode_action_def(unsigned char *, size_t *, e2sm_act_rc_helper &, int);
    bool encode_event_trigger(unsigned char *, size_t *, e2sm_eve_rc_helper &, int);

    std::string  get_error (void) const {return error_string ;};

private:
    E2SM_RC_EventTrigger_t *event_trigger_rc;
    E2SM_RC_EventTrigger_Format1_t event_trigger_rc_fmt1;
    E2SM_RC_EventTrigger_Format1_Item_t *event_trigger_rc_fmt1_item;
    E2SM_RC_EventTrigger_Format2_t *event_trigger_rc_fmt2;

    E2SM_RC_ActionDefinition_t *action_def_rc;
    E2SM_RC_ActionDefinition_Format1_t action_def_rc_fmt1;
    E2SM_RC_ActionDefinition_Format1_Item_t *action_def_rc_fmt1_item;
    E2SM_RC_ActionDefinition_Format2_t *action_def_rc_fmt2;
    E2SM_RC_ActionDefinition_Format2_Item_t *action_def_rc_fmt2_item;
    E2SM_RC_ActionDefinition_Format3_t *action_def_rc_fmt3;
    E2SM_RC_ActionDefinition_Format3_Item_t *action_def_rc_fmt3_item;
    

    size_t errbuf_len;
    char errbuf[128];
    std::string error_string;
};

#endif