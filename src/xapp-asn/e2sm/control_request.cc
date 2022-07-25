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


#include "control_request.hpp"


// Set up memory allocations for each IE for encoding
// We are responsible for memory management for each IE for encoding
// Hence destructor should clear out memory
// When decoding, we rely on asn1c macro (ASN_STRUCT_FREE to be called
// for releasing memory by external calling function)
control_request::control_request(void){
  
   _name = "default";

  e2ap_pdu_obj = 0;
  e2ap_pdu_obj = (E2AP_PDU_t * )calloc(1, sizeof(E2AP_PDU_t));
  assert(e2ap_pdu_obj != 0);

  initMsg = 0;
  initMsg = (InitiatingMessage_t * )calloc(1, sizeof(InitiatingMessage_t));
  assert(initMsg != 0);

  IE_array = 0;
  IE_array = (RICcontrolRequest_IEs_t *)calloc(NUM_CONTROL_REQUEST_IES, sizeof(RICcontrolRequest_IEs_t));
  assert(IE_array != 0);

  e2ap_pdu_obj->choice.initiatingMessage = initMsg;
  e2ap_pdu_obj->present = E2AP_PDU_PR_initiatingMessage;
  
};



// Clear assigned protocolIE list from RIC indication IE container
control_request::~control_request(void){
    

};


bool control_request::encode_e2ap_control(unsigned char *buf, size_t *size,  control_helper &dinput){

  bool res;

  initMsg->procedureCode = ProcedureCode_id_RICcontrol;
  initMsg->criticality = Criticality_reject;
  initMsg->value.present = InitiatingMessage__value_PR_RICcontrolRequest;

  res = set_fields(initMsg, dinput);
  if (!res){
    return false;
  }
  
  int ret_constr = asn_check_constraints(&asn_DEF_E2AP_PDU, (void *) e2ap_pdu_obj, errbuf, &errbuf_len);
  if(ret_constr){
    error_string.assign(errbuf, errbuf_len);
    error_string = "Constraints failed for encoding subscription request. Reason = " + error_string;
    std::cout << error_string << std::endl;
    return false;
  }

  asn_fprint(stdout, &asn_DEF_E2AP_PDU, e2ap_pdu_obj);
  
  asn_enc_rval_t retval = asn_encode_to_buffer(0, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2AP_PDU, e2ap_pdu_obj, buf, *size);
    
  if(retval.encoded == -1){
    error_string.assign(strerror(errno));
    error_string = "Error encoding Control Request. Reason = " + error_string;
    std::cout << error_string << std::endl;
    return false;
  }
  else {
    if(*size < retval.encoded){
        std::stringstream ss;
        ss  <<"Error encoding Control Request . Reason =  encoded pdu size " << retval.encoded << " exceeds buffer size " << *size << std::endl;
        error_string = ss.str();
        retval.encoded = -1;
        std::cout << error_string << std::endl;
        return false;
    }
  }
    
  *size = retval.encoded;
  return true;
    
}


bool control_request::set_fields( InitiatingMessage_t * init_msg, control_helper &helper){
  
    int ie_index;
    int result = 0;

    if (init_msg == 0){
        error_string = "Error. Invalid reference when getting fields from subscription request";
        std::cout << error_string << std::endl;
        return false;
    }

    RICcontrolRequest_t* ric_control = &(init_msg->value.choice.RICcontrolRequest);
    ric_control->protocolIEs.list.count = 0;

    //RICRequestID
    ie_index = 0;
    RICcontrolRequest_IEs_t *ies_ricreq = &IE_array[ie_index];
    ies_ricreq->criticality = Criticality_reject;
    ies_ricreq->id = ProtocolIE_ID_id_RICrequestID;
    ies_ricreq->value.present = RICcontrolRequest_IEs__value_PR_RICrequestID;
    RICrequestID_t *ricrequest_ie = &ies_ricreq->value.choice.RICrequestID;
    ricrequest_ie->ricRequestorID = helper.get_request_id();
    ricrequest_ie->ricInstanceID = helper.get_instance_id();
    result = ASN_SEQUENCE_ADD(&(ric_control->protocolIEs), &IE_array[ie_index]);
    assert(result == 0);

    // RANFunctionID    
    ie_index = 1;
    RICcontrolRequest_IEs_t *ies_ranfunc = &IE_array[ie_index];
    ies_ranfunc->criticality = Criticality_reject;
    ies_ranfunc->id = ProtocolIE_ID_id_RANfunctionID;
    ies_ranfunc->value.present = RICcontrolRequest_IEs__value_PR_RANfunctionID;
    RANfunctionID_t *ranfunction_ie = &ies_ranfunc->value.choice.RANfunctionID;
    *ranfunction_ie = helper.get_function_id();
    result = ASN_SEQUENCE_ADD(&(ric_control->protocolIEs), &IE_array[ie_index]);
    assert(result == 0);

    // RIC Control Header
    ie_index = 2;
    RICcontrolRequest_IEs_t *ies_controlHdr = &IE_array[ie_index];
    ies_controlHdr->criticality = Criticality_reject;
    ies_controlHdr->id = ProtocolIE_ID_id_RICcontrolHeader;
    ies_controlHdr->value.present = RICcontrolRequest_IEs__value_PR_RICcontrolHeader;
    RICcontrolHeader_t *ricControlHdr_ie = &ies_controlHdr->value.choice.RICcontrolHeader;
    ricControlHdr_ie->buf = (uint8_t *)helper.get_control_hdr();
    ricControlHdr_ie->size = helper.get_control_hdr_size();
    result = ASN_SEQUENCE_ADD(&(ric_control->protocolIEs), &IE_array[ie_index]);
    assert(result == 0);

    // RIC Control Message
    ie_index = 3;
    RICcontrolRequest_IEs_t *ies_controlMsg = &IE_array[ie_index];
    ies_controlMsg->criticality = Criticality_reject;
    ies_controlMsg->id = ProtocolIE_ID_id_RICcontrolMessage;
    ies_controlMsg->value.present = RICcontrolRequest_IEs__value_PR_RICcontrolMessage;
    RICcontrolHeader_t *ricControlMsg_ie = &ies_controlMsg->value.choice.RICcontrolMessage;
    ricControlMsg_ie->buf = (uint8_t *)helper.get_control_msg();
    ricControlMsg_ie->size = helper.get_control_msg_size();
    result = ASN_SEQUENCE_ADD(&(ric_control->protocolIEs), &IE_array[ie_index]);
    assert(result == 0);

    // RIC Control Ack Req
    ie_index = 4;
    RICcontrolRequest_IEs_t *ies_controlAckReq = &IE_array[ie_index];
    ies_controlAckReq->criticality = Criticality_reject;
    ies_controlAckReq->id = ProtocolIE_ID_id_RICcontrolAckRequest;
    ies_controlAckReq->value.present = RICcontrolRequest_IEs__value_PR_RICcontrolAckRequest;
    RICcontrolAckRequest_t *ricControlAckReq = &ies_controlAckReq->value.choice.RICcontrolAckRequest;
    *ricControlAckReq = RICcontrolAckRequest_ack;
    result = ASN_SEQUENCE_ADD(&(ric_control->protocolIEs), &IE_array[ie_index]);
    assert(result == 0);

    return true;

};

void control_request::start_control_request(unsigned char *buf, size_t *size){
  bool res;
  size_t data_size = 4096;
  unsigned char	data[data_size];
	
	mdclog_write(MDCLOG_INFO, "Start sending Control request  <file:%s>", __FILE__);

	control_helper din;
	// e2sm_control_rc con_rc;

	din.set_request(123);
	din.set_function_id(3);
	din.set_instance_id(1);
	std::string control_header = "01";
	din.set_control_hdr(control_header.c_str(), control_header.length());
	std::string control_message = "01";
	din.set_control_msg(control_message.c_str(), control_message.length());

	control_request con_req;
	res = con_req.encode_e2ap_control(buf, size, din);
	if(!res){
		mdclog_write(MDCLOG_INFO, "Encode faild");
	}


};