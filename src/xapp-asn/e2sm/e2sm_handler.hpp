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


/* Classes to handle E2 service model handler */
#ifndef E2SM_HANDLER
#define E2SM_HANDLER

#include <sstream>
#include <mdclog/mdclog.h>
#include <vector>

#include "e2sm_subscription_kpm.hpp"
#include "e2sm_subscription_rc.hpp"

typedef enum E2SM_MESS_TYPE {
	e2sm_test = 0,
    e2sm_kpm = 1,
	e2sm_rc	 = 3
	/*
	 * Enumeration is extensible
	 */
} e_E2SM_MESS_TYPE;

class e2sm_handler {
public:
    e2sm_handler(void);
    ~e2sm_handler(void);

    bool handleServiceModel(int typeOfSM, unsigned char *buf_event, unsigned char *buf_action, size_t *size_event, size_t *size_action);

private:

    // size_t errbuf_len;
    // char errbuf[128];
    // std::string error_string;
};

#endif