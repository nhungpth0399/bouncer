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

#ifndef E2SM_RC_HELPER_
#define E2SM_RC_HELPER_

#include <errno.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

// Event Trigger
typedef struct message_rc_helper message_rc_helper;
struct message_rc_helper
{
    long _mess_id;
    long _con_id;
};

class Message_rc_Helper{
private:
    message_rc_helper _message_rc_helper;
public:
    Message_rc_Helper(int mess_id, int con_id){
        _message_rc_helper._mess_id = mess_id;
        _message_rc_helper._con_id = con_id;
    }
    const message_rc_helper &getmess_helper_rc() const {
        return _message_rc_helper;
    }
};

using message_rc_helper_t = std::vector<Message_rc_Helper>;

typedef struct e2sm_eve_rc_helper e2sm_eve_rc_helper;
struct e2sm_eve_rc_helper {
public:
    message_rc_helper_t mess;
    void add_event_rc(int mess_id, int con_id){
        Message_rc_Helper rmess(mess_id, con_id);
        mess.push_back(rmess);
    };
    message_rc_helper_t get_messlist_rc() const {return mess;};
};

// Action Definition
typedef struct ranparam_rc_helper ranparam_rc_helper;
struct ranparam_rc_helper
{
    long _param_id;
};

class RANParam_rc_Helper{
private:
    ranparam_rc_helper _ranparam_rc_helper;
public:
    RANParam_rc_Helper(int id){
        _ranparam_rc_helper._param_id = id;
    }
    const ranparam_rc_helper & getran_helper_rc() const {
        return _ranparam_rc_helper;
    }
};

using ranparam_rc_helper_t = std::vector<RANParam_rc_Helper>;

typedef struct e2sm_act_rc_helper e2sm_act_rc_helper;
struct e2sm_act_rc_helper {
public:
    long ric_style_type;
    ranparam_rc_helper_t param;
    void add_param_rc(int id){
        RANParam_rc_Helper rparam(id);
        param.push_back(rparam);
    };
    ranparam_rc_helper_t get_paramlist_rc() const {return param;};
};

#endif