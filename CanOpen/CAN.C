//****************************************************************************
// @Module        TwinCAN Module (CAN)
// @Filename      CAN.C
// @Project       canopen.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F40
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains functions that use the CAN module.
//
//----------------------------------------------------------------------------
// @Date          2014/9/5 14:48:07
//
//****************************************************************************

// USER CODE BEGIN (CAN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (CAN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CAN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// Structure for a single TwinCAN object
// A total of 31 such object structures exists

struct stCanObj 
{
  ubyte  ubData[8];  // Message Data 0..7
  ulong  ulCANAR;    // Arbitration Register
  ulong  ulCANAMR;   // Acceptance Mask Register
  uword  uwMSGCTR;   // Message Control Register
  uword  uwCounter;  // Frame Counter
  uword  uwMSGCFG;   // Message Configuration Register
  uword  uwINP;      // Interrupt Node Pointer
  uword  uwCANFCR;   // FIFO / Gateway Control Register 
  uword  uwCANPTR;   // FIFO Pointer
  ulong  ulReserved; // Reserved
};

#define CAN_HWOBJ ((struct stCanObj volatile far *) 0x200300)

// USER CODE BEGIN (CAN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CAN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************


// USER CODE BEGIN (CAN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (CAN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (CAN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void CAN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the CAN function 
//                library. It is assumed that the SFRs used by this library 
//                are in its reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void CAN_vInit(void)
{

  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node A:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node A:
  ///  - set INIT and CCE

  CAN_ACR        =  0x0041;      // load global control register
  CAN_AGINP      =  0x0000;      // load global interrupt node pointer 
                                 // register

  ///  Configuration of the Node A Error Counter:
  ///  - the error warning threshold value (warning level) is 96

  CAN_AECNTH     =  0x0060;      // load error counter register high

  ///  Configuration of the used CAN Port Pins:
  ///  - P4.5 is used for CAN Interface Input (RXDCA)
  ///  - P4.6 is used for CAN Interface Output (TXDCA)

  ALTSEL0P4     |=  0x0040;      // select alternate output function
  DP4  = (DP4  & ~(uword)0x0040) | 0x0040;    //set direction register

  ///  Configuration of the Node A Baud Rate:
  ///  - required baud rate = 50.000 kbaud
  ///  - real baud rate     = 50.000 kbaud
  ///  - sample point       = 60.00 %
  ///  - there are 5 time quanta before sample point
  ///  - there are 4 time quanta after sample point
  ///  - the (re)synchronization jump width is 2 time quanta
  ///  - enable the module clock divider (by 8)

  CAN_ABTRL      =  0xB449;      // load bit timing register low

  CAN_ABTRH      =  0x0000;      // load bit timing register high

  CAN_AFCRL      =  0x0000;      // load frame counter timing register low

  CAN_AFCRH      =  0x0000;      // load frame counter timing register high

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node B:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node B:
  ///  - set INIT and CCE

  CAN_BCR        =  0x0041;      // load global control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the CAN Message Objects 0 - 31:
  ///  -----------------------------------------------------------------------

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 0:
  ///  -----------------------------------------------------------------------
  ///  - message object 0 is valid

  ///  - message object is used as transmit object
  ///  - standard 11-bit identifier
  ///  - 8 valid data bytes
  ///  - this message object works with CAN node A
  ///  - remote monitoring is disabled

  CAN_MSGCFGL0   =  0x0088;      // load message configuration register low
  CAN_MSGCFGH0   =  0x0000;      // load message configuration register high

  ///  - acceptance mask 11-bit: 0x7FF
  ///  - identifier 11-bit:      0x000

  CAN_MSGAMRL0   =  0xFFFF;      // load acceptance mask register low
  CAN_MSGAMRH0   =  0xFFFF;      // load acceptance mask register high
  CAN_MSGARL0    =  0x0000;      // load arbitration register low
  CAN_MSGARH0    =  0x0000;      // load arbitration register high
  CAN_MSGDRL00   =  0x0000;      // load data register 0 low
  CAN_MSGDRH00   =  0x0000;      // load data register 0 high
  CAN_MSGDRL04   =  0x0000;      // load data register 4 low
  CAN_MSGDRH04   =  0x0000;      // load data register 4 high

  ///  - functionality of standard message object

  CAN_MSGFGCRL0  =  0x0000;      // load FIFO/gateway control register low
  CAN_MSGFGCRH0  =  0x0000;      // load FIFO/gateway control register high

  CAN_MSGCTRH0   =  0x0000;      // load message control register high
  CAN_MSGCTRL0   =  0x5595;      // load message control register low

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 1:
  ///  -----------------------------------------------------------------------
  ///  - message object 1 is valid

  ///  - message object is used as receive object
  ///  - standard 11-bit identifier
  ///  - 8 valid data bytes
  ///  - this message object works with CAN node A
  ///  - remote monitoring is disabled

  CAN_MSGCFGL1   =  0x0080;      // load message configuration register low
  CAN_MSGCFGH1   =  0x0000;      // load message configuration register high

  ///  - acceptance mask 11-bit: 0x7FF
  ///  - identifier 11-bit:      0x000

  CAN_MSGAMRL1   =  0xFFFF;      // load acceptance mask register low
  CAN_MSGAMRH1   =  0xFFFF;      // load acceptance mask register high
  CAN_MSGARL1    =  0x0000;      // load arbitration register low
  CAN_MSGARH1    =  0x0000;      // load arbitration register high
  CAN_MSGDRL10   =  0x0000;      // load data register 0 low
  CAN_MSGDRH10   =  0x0000;      // load data register 0 high
  CAN_MSGDRL14   =  0x0000;      // load data register 4 low
  CAN_MSGDRH14   =  0x0000;      // load data register 4 high

  ///  - functionality of standard message object

  CAN_MSGFGCRL1  =  0x0000;      // load FIFO/gateway control register low
  CAN_MSGFGCRH1  =  0x0001;      // load FIFO/gateway control register high

  CAN_MSGCTRH1   =  0x0000;      // load message control register high
  CAN_MSGCTRL1   =  0x5595;      // load message control register low


  ///  -----------------------------------------------------------------------
  ///  Configuration of Service Request Nodes 0 - 7:
  ///  -----------------------------------------------------------------------


  // USER CODE BEGIN (Init,3)

  // USER CODE END


  CAN_PISEL      =  0x0000;      // load port input select register

  //   -----------------------------------------------------------------------
  //   Start the CAN Nodes:
  //   -----------------------------------------------------------------------

  CAN_ACR       &= ~(uword)0x0041; // reset INIT and CCE


  // USER CODE BEGIN (Init,4)

  // USER CODE END

} //  End of function CAN_vInit


//****************************************************************************
// @Function      void CAN_vGetMsgObj(ubyte ubObjNr, TCAN_SWObj *pstObj) 
//
//----------------------------------------------------------------------------
// @Description   This function fills the forwarded SW message object with 
//                the content of the chosen HW message object.
//                
//                The structure of the SW message object is defined in the 
//                header file CAN_164.H (see TCAN_SWObj).
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object to be read (0-31)
// @Parameters    *pstObj: 
//                Pointer on a message object to be filled by this function
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (GetMsgObj,1)

// USER CODE END

void CAN_vGetMsgObj(ubyte ubObjNr, TCAN_SWObj *pstObj)
{
  ubyte i;

  for(i = 0; i < (CAN_HWOBJ[ubObjNr].uwMSGCFG & 0x00f0) >> 4; i++)
  {
    pstObj->ubData[i] = CAN_HWOBJ[ubObjNr].ubData[i];
  }

  if(CAN_HWOBJ[ubObjNr].uwMSGCFG & 0x04)  // extended identifier
  {
    pstObj->ulID   = CAN_HWOBJ[ubObjNr].ulCANAR;
    pstObj->ulMask = CAN_HWOBJ[ubObjNr].ulCANAMR;
  }
  else                                    // standard identifier 
  {
    pstObj->ulID   = CAN_HWOBJ[ubObjNr].ulCANAR >> 18;
    pstObj->ulMask = CAN_HWOBJ[ubObjNr].ulCANAMR >> 18;
  }

  pstObj->uwCounter = CAN_HWOBJ[ubObjNr].uwCounter;
  pstObj->uwMsgCfg  = CAN_HWOBJ[ubObjNr].uwMSGCFG;

} //  End of function CAN_vGetMsgObj


//****************************************************************************
// @Function      ubyte CAN_ubRequestMsgObj(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   If a TRANSMIT OBJECT is to be reconfigured it must first be 
//                accessed. The access to the transmit object is exclusive. 
//                This function checks whether the choosen message object is 
//                still executing a transmit request, or if the object can be 
//                accessed exclusively.
//                After the message object is reserved, it can be 
//                reconfigured by using the function CAN_vConfigMsgObj or 
//                CAN_vLoadData.
//                Both functions enable access to the object for the CAN 
//                controller. 
//                By calling the function CAN_vTransmit transfering of data 
//                is started.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 message object is busy (a transfer is active), else 1
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-31)
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (RequestMsgObj,1)

// USER CODE END

ubyte CAN_ubRequestMsgObj(ubyte ubObjNr)
{
  ubyte ubReturn;

  ubReturn = 0;
  if((CAN_HWOBJ[ubObjNr].uwMSGCTR & 0x3000) == 0x1000)  // if reset TXRQ 
  {
    CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xfbff;               // set CPUUPD 
    ubReturn = 1;
  }
  return(ubReturn);

} //  End of function CAN_ubRequestMsgObj


//****************************************************************************
// @Function      ubyte CAN_ubNewData(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function checks whether the selected RECEIVE OBJECT 
//                has received a new message. If so the function returns the 
//                value '1'.
//
//----------------------------------------------------------------------------
// @Returnvalue   1 the message object has received a new message, else 0
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-31)
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (NewData,1)

// USER CODE END

ubyte CAN_ubNewData(ubyte ubObjNr)
{
  ubyte ubReturn;

  ubReturn = 0;
  if((CAN_HWOBJ[ubObjNr].uwMSGCTR & 0x0300) == 0x0200)  // if NEWDAT
  {
    ubReturn = 1;
  }
  return(ubReturn);

} //  End of function CAN_ubNewData


//****************************************************************************
// @Function      void CAN_vTransmit(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function triggers the CAN controller to send the 
//                selected message.
//                If the selected message object is a TRANSMIT OBJECT then 
//                this function triggers the sending of a data frame. If 
//                however the selected message object is a RECEIVE OBJECT 
//                this function triggers the sending of a remote frame.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-31)
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (Transmit,1)

// USER CODE END

void CAN_vTransmit(ubyte ubObjNr)
{
  CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xe7ff;  // set TXRQ, reset CPUUPD

} //  End of function CAN_vTransmit


//****************************************************************************
// @Function      void CAN_vConfigMsgObj(ubyte ubObjNr, TCAN_SWObj *pstObj) 
//
//----------------------------------------------------------------------------
// @Description   This function sets up the message objects. This includes 
//                the 8 data bytes, the identifier (11- or 29-bit), the 
//                acceptance mask (11- or 29-bit), the data number (0-8 
//                bytes), the frame counter value and the XTD-bit (standard 
//                or extended identifier).  The direction bit (DIR), the NODE 
//                bit and the RMM (remote monitoring) bit can not be changed. 
//                The message is not sent; for this the function 
//                CAN_vTransmit must be called.
//                
//                The structure of the SW message object is defined in the 
//                header file CAN_164.H (see TCAN_SWObj).
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object to be configured (0-31)
// @Parameters    *pstObj: 
//                Pointer on a message object
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (ConfigMsgObj,1)

// USER CODE END

void CAN_vConfigMsgObj(ubyte ubObjNr, TCAN_SWObj *pstObj)
{
  ubyte i;

  CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xfb7f;     // set CPUUPD, reset MSGVAL

  if(pstObj->uwMsgCfg & 0x0004)             // extended identifier
  {
    CAN_HWOBJ[ubObjNr].uwMSGCFG |= 0x0004;
    CAN_HWOBJ[ubObjNr].ulCANAR   = pstObj->ulID ;
    CAN_HWOBJ[ubObjNr].ulCANAMR  = pstObj->ulMask ;
  }
  else                                      // standard identifier
  {
    CAN_HWOBJ[ubObjNr].uwMSGCFG &= ~(uword)0x0004;
    CAN_HWOBJ[ubObjNr].ulCANAR   = pstObj->ulID << 18;
    CAN_HWOBJ[ubObjNr].ulCANAMR  = pstObj->ulMask << 18;
  }

  CAN_HWOBJ[ubObjNr].uwCounter = pstObj->uwCounter;

  CAN_HWOBJ[ubObjNr].uwMSGCFG  = (CAN_HWOBJ[ubObjNr].uwMSGCFG & 0x000f) | (pstObj->uwMsgCfg & 0x00f0);

  if(CAN_HWOBJ[ubObjNr].uwMSGCFG & 0x0008)  // if transmit direction
  {
    for(i = 0; i < (pstObj->uwMsgCfg & 0x00f0) >> 4; i++)
    {
      CAN_HWOBJ[ubObjNr].ubData[i] = pstObj->ubData[i];
    }
    CAN_HWOBJ[ubObjNr].uwMSGCTR  = 0xf6bf;  // set NEWDAT, reset CPUUPD, 
  }                                         // set MSGVAL
  else                                      // if receive direction
  {
    CAN_HWOBJ[ubObjNr].uwMSGCTR  = 0xf7bf;  // reset CPUUPD, set MSGVAL
  }

} //  End of function CAN_vConfigMsgObj


//****************************************************************************
// @Function      void CAN_vLoadData(ubyte ubObjNr, ubyte *pubData) 
//
//----------------------------------------------------------------------------
// @Description   If a hardware TRANSMIT OBJECT has to be loaded with data 
//                but not with a new identifier, this function may be used 
//                instead of the function CAN_vConfigMsgObj. The message 
//                object should be accessed by calling the function 
//                CAN_ubRequestMsgObj before calling this function. This 
//                prevents the CAN controller from working with invalid data.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object to be configured (0-31)
// @Parameters    *pubData: 
//                Pointer on a data buffer
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (LoadData,1)

// USER CODE END

void CAN_vLoadData(ubyte ubObjNr, ubyte *pubData)
{
  ubyte i;

  CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xfaff;       // set CPUUPD and NEWDAT

  for(i = 0; i < (CAN_HWOBJ[ubObjNr].uwMSGCFG & 0xf0) >> 4; i++)
  {
    CAN_HWOBJ[ubObjNr].ubData[i] = *(pubData++);
  }

  CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xf7ff;       // reset CPUUPD

} //  End of function CAN_vLoadData


//****************************************************************************
// @Function      ubyte CAN_ubMsgLost(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   If a RECEIVE OBJECT receives new data before the old object 
//                has been read, the old object is lost. The CAN controller 
//                indicates this by setting the message lost bit (MSGLST). 
//                This function returns the status of this bit. 
//                
//                Note:
//                This function resets the message lost bit (MSGLST).
//
//----------------------------------------------------------------------------
// @Returnvalue   1 the message object has lost a message, else 0
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-31)
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (MsgLost,1)

// USER CODE END

ubyte CAN_ubMsgLost(ubyte ubObjNr)
{
  ubyte ubReturn;

  ubReturn = 0;
  if((CAN_HWOBJ[ubObjNr].uwMSGCTR & 0x0c00) == 0x0800)  // if set MSGLST 
  {
    CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xf7ff;               // reset MSGLST 
    ubReturn = 1;
  }
  return(ubReturn);

} //  End of function CAN_ubMsgLost


//****************************************************************************
// @Function      ubyte CAN_ubDelMsgObj(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function marks the selected message object as not 
//                valid. This means that this object cannot be sent or 
//                receive data. If the selected object is busy (meaning the 
//                object is transmitting a message or has received a new 
//                message) this function returns the value "0" and the object 
//                is not deleted.
//
//----------------------------------------------------------------------------
// @Returnvalue   1 the message object was deleted, else 0
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-31)
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (DelMsgObj,1)

// USER CODE END

ubyte CAN_ubDelMsgObj(ubyte ubObjNr)
{
  ubyte ubReturn;

  ubReturn = 0;
  if(!(CAN_HWOBJ[ubObjNr].uwMSGCTR & 0xa200)) // if set RMTPND, TXRQ or NEWDAT
  {
    CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xff7f;     // reset MSGVAL
    ubReturn = 1;
  }
  return(ubReturn);

} //  End of function CAN_ubDelMsgObj


//****************************************************************************
// @Function      void CAN_vReleaseObj(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function resets the NEWDAT flag of the selected 
//                RECEIVE OBJECT, so that the CAN controller have access to 
//                it. This function must be called if the function 
//                CAN_ubNewData detects, that new data are present in the 
//                message object and the actual data have been read by 
//                calling the function CAN_vGetMsgObj. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-31)
//
//----------------------------------------------------------------------------
// @Date          2014/9/5
//
//****************************************************************************

// USER CODE BEGIN (ReleaseObj,1)

// USER CODE END

void CAN_vReleaseObj(ubyte ubObjNr)
{
  CAN_HWOBJ[ubObjNr].uwMSGCTR = 0xfdff;       // reset NEWDAT

} //  End of function CAN_vReleaseObj



// USER CODE BEGIN (CAN_General,10)

// USER CODE END

