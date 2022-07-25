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

#ifndef E2SM_INDICATION_RC_HPP_
#define E2SM_INDICATION_RC_HPP_

#include <sstream>
#include <mdclog/mdclog.h>
#include <vector>

#include <E2SM-RC-IndicationHeader.h>
#include <E2SM-RC-IndicationMessage.h>

class e2sm_indication_rc {
public:
    e2sm_indication_rc(void);
    ~e2sm_indication_rc(void);

    bool decode_indication_header(unsigned char *, size_t *);
    bool decode_indication_message(unsigned char *, size_t *);
    
    std::string  get_error (void) const {return error_string ;};

private:
    E2SM_RC_IndicationHeader_t* indication_header;
    E2SM_RC_IndicationMessage_t* indication_message;       

    size_t errbuf_len;
    char errbuf[128];
    std::string error_string;
};

#endif