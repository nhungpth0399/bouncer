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
#ifndef E2SM_HELPER_
#define E2SM_HELPER_

#include <errno.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include "UEID.h"
#include "generic_helpers.hpp"

typedef struct ranparam_helper ranparam_helper;
struct ranparam_helper {
	  long int _param_id;
	  unsigned char* _param_name;
	  size_t _param_name_len;
	  int _param_test;
	  unsigned char* _param_value;
	  size_t _param_value_len;

};
class RANParam_Helper{
private:
	ranparam_helper _ranparam_helper;

public:

	RANParam_Helper(int id, unsigned char *param_name, size_t param_name_len, int param_test, unsigned char* param_value, size_t param_value_len){
		_ranparam_helper._param_id = id;
		_ranparam_helper._param_name = param_name;
		_ranparam_helper._param_name_len = param_name_len;
		_ranparam_helper._param_test = param_test;
		_ranparam_helper._param_value = param_value;
		_ranparam_helper._param_value_len = param_value_len;
	  }

	const ranparam_helper & getran_helper() const {
		return _ranparam_helper;
	}
	void print_ranparam_info(void){
	    std::cout <<"Param ID = " << _ranparam_helper._param_id << std::endl;
	    std::cout << "Parame Name =" << _ranparam_helper._param_name << std::endl;
	    std::cout <<"Param Test = " << _ranparam_helper._param_test << std::endl;
	    std::cout <<"Param Value = " << _ranparam_helper._param_value << std::endl;
	}
};


using ranparam_helper_t = std::vector<RANParam_Helper>;

typedef struct e2sm_subscription_helper e2sm_subscription_helper;
struct e2sm_subscription_helper {
public:


  int triger_nature;
  ranparam_helper_t param;
  void add_param(int id, unsigned char *param_name, size_t param_name_len, int param_test, unsigned char* param_value, size_t param_value_len){
	  RANParam_Helper rparam(id,param_name,param_name_len,param_test,param_value,param_value_len);
      param.push_back(rparam);
    };
  ranparam_helper_t get_paramlist() const {return param;};



};


typedef struct e2sm_indication_helper e2sm_indication_helper;


struct e2sm_indication_helper {
	long int header;
	unsigned char* message;
	size_t message_len;
};

typedef struct e2sm_control_helper e2sm_control_helper;

struct e2sm_control_helper {
	long int header;
	unsigned char* message;
	size_t message_len;
};

typedef struct e2sm_control_rc_helper e2sm_control_rc_helper;

struct e2sm_control_rc_helper {
	int styleType, controlActionID;
	UEID_t* ueid;

	void setType(int x){
		styleType = x;
	}

	void setControlActionID(int x){
		controlActionID = x;
	}

	void setUEID(UEID_t* x){
		ueid = x;
	}

	int getType(void){
		return styleType;
	}

	int getControlActionID(void){
		return controlActionID;
	}

	UEID_t* getUEID(void){
		return ueid;
	}
};

struct control_helper {

private:

  int _req_id, _ins_id, _func_id;
  octet_helper _control_hdr, _control_msg;

public:
	
	//Setter
	void set_request(int id){
		_req_id = id;
	};

	void set_function_id(int id){
		_func_id = id;
	};

	void set_instance_id(int id){
		_ins_id = id;
	};

	void set_control_hdr(const void *ref, size_t size){
		_control_hdr.set_ref(ref);
		_control_hdr.set_size(size);
	};

	void set_control_msg(const void *ref, size_t size){
		_control_msg.set_ref(ref);
		_control_msg.set_size(size);
	};

	// Getter
  	int  get_request_id(void) const{
    	return _req_id;
  	};

	int  get_function_id(void) const{
		return _func_id;
	};

	int get_instance_id(void) const{
		return _ins_id;
	};
	
	const void * get_control_hdr(void)  {
		return _control_hdr.get_ref();
	};

	int get_control_hdr_size(void) const {
		return _control_hdr.get_size();
	};

	const void * get_control_msg(void)  {
		return _control_msg.get_ref();
	};

	int get_control_msg_size(void) const {
		return _control_msg.get_size();
	};


};

#endif
