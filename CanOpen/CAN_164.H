//****************************************************************************
// @Module        TwinCAN Module (CAN)
// @Filename      CAN_164.H
// @Project       canopen.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F40
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains all function prototypes and macros for 
//                the CAN module.
//
//----------------------------------------------------------------------------
// @Date          2014/9/5 14:48:07
//
//****************************************************************************

// USER CODE BEGIN (CAN_Header,1)

// USER CODE END



#ifndef _CAN_164_H_
#define _CAN_164_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CAN_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CAN_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (CAN_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

///  -------------------------------------------------------------------------
///  @Definition of a structure for the CAN data
///  -------------------------------------------------------------------------

// The following data type serves as a software message object. Each access to
// a hardware message object has to be made by forward a pointer to a software
// message object (TCAN_SWObj). The data type has the following fields:
//
// uwMsgCfg:
// this byte has the same structure as the message configuration register of a
// hardware message object. It contains the "Data Lenght Code" (DLC), the 
// "Extended Identifier" (XTD), the "Message Direction" (DIR), the "Node
// Select" and the "Remote Monitoring Mode".
//
//
//         7     6     5      4    3     2     1     0
//      |------------------------------------------------|
//      |        DLC            | DIR | XTD | NODE | RMM |
//      |------------------------------------------------|
//
// ulID: 
// this field is four bytes long and contains either the 11-bit identifier 
// or the 29-bit identifier
//
// ulMask: 
// this field is four bytes long and contains either the 11-bit mask 
// or the 29-bit mask
//
// ubData[8]:
// 8 bytes containing the data of a frame
//
// uwCounter:
// this field is two bytes long and contains the counter value 
//

typedef struct
  {
     uword  uwMsgCfg;   // Message Configuration Register
     ulong  ulID;       // standard (11-bit)/extended (29-bit) identifier
     ulong  ulMask;     // standard (11-bit)/extended (29-bit) mask
     ubyte  ubData[8];  // 8-bit Data Bytes
     uword  uwCounter;  // Frame Counter
  }TCAN_SWObj;

// USER CODE BEGIN (CAN_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CAN_vInit(void);
void CAN_vGetMsgObj(ubyte ubObjNr, TCAN_SWObj *pstObj);
ubyte CAN_ubRequestMsgObj(ubyte ubObjNr);
ubyte CAN_ubNewData(ubyte ubObjNr);
void CAN_vTransmit(ubyte ubObjNr);
void CAN_vConfigMsgObj(ubyte ubObjNr, TCAN_SWObj *pstObj);
void CAN_vLoadData(ubyte ubObjNr, ubyte *pubData);
ubyte CAN_ubMsgLost(ubyte ubObjNr);
ubyte CAN_ubDelMsgObj(ubyte ubObjNr);
void CAN_vReleaseObj(ubyte ubObjNr);


// USER CODE BEGIN (CAN_Header,8)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************


// USER CODE BEGIN (CAN_Header,9)

// USER CODE END


#endif  // ifndef _CAN_164_H_
