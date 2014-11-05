//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.C
// @Project       canopen.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F40
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          2014/9/5 14:48:07
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (MAIN_General,2)
#include <can_xc164.h>
#include "can.h"
#include "master.h"
// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
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

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 8 MHz
  ///  - VCO output frequency 150 .. 200 MHz
  ///  - system clock is 40 MHz

  MAIN_vUnlockProtecReg();       // unlock write security
  PLLCON         =  0x7343;      // load PLL control register


  //// -----------------------------------------------------------------------
  //// Begin of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------
  ///  All following settings must be set in the start-up file. You can use 
  ///  DAvE's project file (*.dpt) to include this register values into your 
  ///  compiler EDE.

    ///  ---------------------------------------------------------------------
    ///  Initialization of the CPUCON1 Register:
    ///  ---------------------------------------------------------------------
    ///  - space between two vectors is 2 words
    ///  - DISWDT executable until End of Init
    ///  - segmentation is enabled
    ///  - switch context is interruptible
    ///  - branch prediction is enabled
    ///  - zero cycle jump function is enabled

    //// this register must be set in the start-up file
    //// CPUCON1  =  0x0007

    ///  ---------------------------------------------------------------------
    ///  Initialization of the VECSEG Register:
    ///  ---------------------------------------------------------------------
    ///  - start from external memory

    //// this register must be set in the start-up file
    //// VECSEG  =  0x0000

    ///  ---------------------------------------------------------------------
    ///  Initialization of the SYSCON0 Register:
    ///  ---------------------------------------------------------------------

    //// this register must be set in the start-up file
    //// SYSCON0  =  0x0000

    ///  ---------------------------------------------------------------------
    ///  Initialization of the SYSCON1 Register:
    ///  ---------------------------------------------------------------------
    ///  clock prescaler for system is fpll / 1

    //// this register must be set in the start-up file
    //// SYSCON1  =  0x0000

    ///  ---------------------------------------------------------------------
    ///  Initialization of the SYSCON3 Register:
    ///  ---------------------------------------------------------------------

    //// this register must be set in the start-up file
    //// SYSCON3  =  0x0000

    ///  ---------------------------------------------------------------------
    ///  Initialization of EBC
    ///  ---------------------------------------------------------------------

    //// this register must be set in the start-up file
    //// EBCMOD1  =  0x007F

    ///  EBC is disabled
  //// -----------------------------------------------------------------------
  //// End of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------


  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the TwinCAN Module (CAN)
  CAN_vInit();

  // USER CODE BEGIN (Init,3)

  // USER CODE END

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register. After calling of this function and write on the 
//                protected register is the security level set to low 
//                protected mode.
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

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{
  uword uwPASSWORD;

  if((SCUSLS & 0x1800) == 0x0800)      // if low protected mode
  {

    uwPASSWORD = SCUSLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCUSLC = 0x8E00 | uwPASSWORD;      // command 4

  }  // end if low protected mode

  if((SCUSLS & 0x1800) == 0x1800)      // if write protected mode
  {
    SCUSLC = 0xAAAA;                   // command 0
    SCUSLC = 0x5554;                   // command 1

    uwPASSWORD = SCUSLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCUSLC = 0x9600 | uwPASSWORD;      // command 2
    SCUSLC = 0x0800;                   // command 3; new PASSWOR is 0x00

    uwPASSWORD = SCUSLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCUSLC = 0x8E00 | uwPASSWORD;      // command 4

  }  // end if write protected mode

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
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

// USER CODE BEGIN (Main,1)

// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)
	Message recvm;
	TCAN_SWObj C;
	C.ulID=0x600;
  C.uwMsgCfg=0x0082;
	C.ulMask=0x600;
  // USER CODE END

  MAIN_vInit();

  // USER CODE BEGIN (Main,4)
	setNodeId (&master_Data, 0x01);
  setState(&master_Data, Initialisation);
	CAN_vConfigMsgObj(1,&C);

	while(1){
	if(canReceive(0,&recvm))
		canDispatch(&master_Data,&recvm);
}
  // USER CODE END

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)

// USER CODE END

