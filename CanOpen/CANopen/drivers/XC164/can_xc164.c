#include "can_xc164.h"
#include "canfestival.h"
#include "main.h"




unsigned char canSend(CAN_PORT notused, Message *m) 
{
  unsigned char i;
	TCAN_SWObj SW_MO;
	SW_MO.ulID=m->cob_id;
	SW_MO.ulMask=m->cob_id;
	for(i=0;i<(m->len);i++)
	{
		SW_MO.ubData[i]=m->data[i];
	}
	SW_MO.uwMsgCfg=(SW_MO.uwMsgCfg&0x0000)|((m->len)<<4);
	if(!m->rtr)
	{
		CAN_vConfigMsgObj(0,&SW_MO);
		CAN_vTransmit(0);
  }
	return 1;
}

unsigned char canReceive(CAN_PORT port,Message *m) 
{
	TCAN_SWObj SW_R;
	
	if(CAN_ubNewData(1))
	{
		unsigned char i;
		CAN_vReleaseObj(1);
		CAN_vGetMsgObj(1,&SW_R);
		m->cob_id=SW_R.ulID;
		m->len=(SW_R.uwMsgCfg&0x00f0)>>4;
		m->rtr=CAN_ubRequestMsgObj(1);
		for(i=0;i<(m->len);i++)
		{
			m->data[i]=SW_R.ubData[i];
		}
		return 1;
	}
	return 0;
}


/***************************************************************************/
unsigned char canChangeBaudRate_driver( CAN_HANDLE fd, char* baud)
{

	return 0;
}

