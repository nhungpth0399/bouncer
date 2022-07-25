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

#ifndef E2SM_CONTROL_RC_HPP_
#define E2SM_CONTROL_RC_HPP_

#include <sstream>
// #include <mdclog/mdclog.h>
#include <vector>

#include "e2sm_helpers.hpp"
#include "E2SM-RC-ControlHeader.h"
#include "E2SM-RC-ControlMessage.h"
#include "E2SM-RC-ControlHeader-Format1.h"

#include "UEID-GNB.h"

class e2sm_control_rc {
public:
    e2sm_control_rc(void);
    ~e2sm_control_rc(void);

    bool set_fields(E2SM_RC_ControlHeader_t *, e2sm_control_rc_helper &);
    bool set_fields(E2SM_RC_ControlMessage_t *, e2sm_control_rc_helper &);

    bool encode_control_header(unsigned char *, size_t *, e2sm_control_rc_helper &);
    bool encode_control_message(unsigned char *, size_t *, e2sm_control_rc_helper &);
    
    std::string  get_error (void) const {return error_string ;};

private:
    E2SM_RC_ControlHeader_t* control_header;
    E2SM_RC_ControlMessage_t* control_message; 

    E2SM_RC_ControlHeader_Format1_t* control_header_format1;
    
    size_t errbuf_len;
    char errbuf[128];
    std::string error_string;
};

#endif