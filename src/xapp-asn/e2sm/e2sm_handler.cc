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

#include "e2sm_handler.hpp"

 //initialize
 e2sm_handler::e2sm_handler(void){

 };

 e2sm_handler::~e2sm_handler(void){

 };

bool e2sm_handler::handleServiceModel(int typeOfSM, \
                                      unsigned char *buf_event, \
                                      unsigned char *buf_action, \
                                      size_t *size_event, \
                                      size_t *size_action)
{
  bool res = false;
  bool res_event = false;
  bool res_action = false;
    
  switch (typeOfSM) 
  {
	case e2sm_kpm:
		    {
          // Encode E2SM_KPM event trigger and action definition
          e2sm_subscription_kpm sub_kpm;
          e2sm_kpm_helper din_kpm;

          din_kpm.addPeriod(RT_Period_IE_ms10);
          din_kpm.addPeriod(RT_Period_IE_ms20);
          din_kpm.addPeriod(RT_Period_IE_ms32);
          din_kpm.addPeriod(RT_Period_IE_ms40);
          din_kpm.addPeriod(RT_Period_IE_ms60);

          din_kpm.addPeriod(RT_Period_IE_ms64);
          din_kpm.addPeriod(RT_Period_IE_ms70);
          din_kpm.addPeriod(RT_Period_IE_ms80);
          din_kpm.addPeriod(RT_Period_IE_ms128);
          din_kpm.addPeriod(RT_Period_IE_ms160);

          din_kpm.addPeriod(RT_Period_IE_ms256);
          din_kpm.addPeriod(RT_Period_IE_ms320);
          din_kpm.addPeriod(RT_Period_IE_ms512);
          din_kpm.addPeriod(RT_Period_IE_ms640);
          din_kpm.addPeriod(RT_Period_IE_ms1024);

          din_kpm.addRicStyle(2022);

          mdclog_write(MDCLOG_INFO,"Encode event trigger KPM in file= %s, line=%d",__FILE__,__LINE__);
          res_event = sub_kpm.encode_event_trigger( buf_event, size_event, din_kpm);
          if(!res_event)
          {
            break;
          }
          
          mdclog_write(MDCLOG_INFO,"Encode action definition KPM in file= %s, line=%d",__FILE__,__LINE__);
          res_action = sub_kpm.encode_action_defn( buf_action, size_action, din_kpm);
          if(!res_action)
          {
            break;
          }

        }
		break;
	
    case e2sm_rc:
		    {
            // Encode E2SM_RC event trigger and action definition
            e2sm_subscription_rc e2sm_rc;
            e2sm_eve_rc_helper eve_in;
            e2sm_act_rc_helper act_in;
            int mess_id = 0;
            int con_id = 1;

            mdclog_write(MDCLOG_INFO,"Encode event trigger RC in file= %s, line=%d",__FILE__,__LINE__);
            eve_in.add_event_rc(mess_id, con_id);
            int event_trigger_format = 2;
            res_event = e2sm_rc.encode_event_trigger( buf_event, size_event, eve_in, event_trigger_format);
            if(!res_event)
            {
              break;
            }

            mdclog_write(MDCLOG_INFO,"Encode action definition RC in file= %s, line=%d",__FILE__,__LINE__);
            act_in.ric_style_type = 1;
            act_in.add_param_rc(1);
            int action_definition_format = 2;
            res_action = e2sm_rc.encode_action_def( buf_action, size_action, act_in, action_definition_format);
            if(!res_action)
            {
              break;
            }

        }
		break;
	
    default:
		    mdclog_write(MDCLOG_INFO, "Invalid E2SM");
        break;
 	}

    return res;
}