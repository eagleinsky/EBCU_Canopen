#ifndef _IAR_H_
#define _IAR_H_

#ifdef  __IAR_SYSTEMS_ICC__	// IAR Compiler

/*
#define ISR(vect)	\
  	_Pragma("vector="vect) \
	__interrupt void Interrupt_##vect (void)
*/
#define sei()		__enable_interrupt()
#define cli()		__disable_interrupt()
#define sleep_enable()	SMCR = 1 << SE
#define sleep_cpu()	__sleep()
#define wdt_reset()	__watchdog_reset()
#define wdt_enable(val)	{WDTCSR = 1 << WDCE  | 1 << WDE;	\
			WDTCSR = 1 << WDE | (val);}

#else
#error Not an IAR Compiler!
#endif				// IAR Compiler

#endif // _IAR_H_
