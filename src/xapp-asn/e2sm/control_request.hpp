/*
==================================================================================
        Copyright (c) 2019-2020 AT&T Intellectual Property.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
==================================================================================
*/

#pragma once

#ifndef CONTROL_REQUEST_
#define CONTROL_REQUEST_

#include <mdclog/mdclog.h>
#include <vector>
#include <sstream>

#include <asn_application.h>
#include <E2AP-PDU.h>
#include <InitiatingMessage.h>
#include <RICcontrolRequest.h>
#include <ProtocolIE-Field.h>
#include "e2sm_helpers.hpp"


#define BUFFER_SIZE 1024
#define SM_BUFFER_SIZE 16
#define NUM_CONTROL_REQUEST_IES 5
  
class control_request{   
public:

  control_request(std::string name);
  control_request(void);
  ~control_request(void);
  
  bool encode_e2ap_control(unsigned char *, size_t *,  control_helper &);
  bool set_fields(InitiatingMessage_t *, control_helper &);
  void start_control_request(unsigned char *, size_t *);
     
  std::string get_error(void) const{
    return error_string;
  }
    
private:
    
  InitiatingMessage_t *initMsg;
  E2AP_PDU_t * e2ap_pdu_obj;

  RICcontrolRequest_IEs_t * IE_array;
  
  char errbuf[128];
  size_t errbuf_len = 128;
  std::string _name;
  std::string error_string;
};



#endif