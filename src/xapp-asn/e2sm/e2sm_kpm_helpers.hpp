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
#ifndef E2SM_KPM_HELPER_
#define E2SM_KPM_HELPER_

#include <iostream>
#include <vector>
#include <queue>
#include <mdclog/mdclog.h>

#define NUM_TRIGGER_CONDITIONIE_ITEM 15

typedef struct e2sm_kpm_helper e2sm_kpm_helper;
struct e2sm_kpm_helper {
public:

	std::queue<int> report_Period_arr;
	std::queue<int> ric_Style_Type_arr;

	bool addPeriod(int x){
		if ( ( x < 0 ) || ( x > 19 ) ){
            mdclog_write(MDCLOG_INFO,"Invalid report period in file= %s, line=%d",__FILE__,__LINE__);
			return false;
		}

		if (report_Period_arr.size() > NUM_TRIGGER_CONDITIONIE_ITEM - 1){
            mdclog_write(MDCLOG_INFO,"Max numbers of report period items in file= %s, line=%d",__FILE__,__LINE__);
			return false;
		}

		report_Period_arr.push(x);
		return true;
	};

	int getPeriod(void ){
		int _element = report_Period_arr.front();
		report_Period_arr.pop();
		return _element;
	};

	bool addRicStyle(int x){
		ric_Style_Type_arr.push(x);
		return true;
	}

	int getRicStyle(void ){
		int _element = ric_Style_Type_arr.front();
		ric_Style_Type_arr.pop();
		return _element;
	}
};


#endif
