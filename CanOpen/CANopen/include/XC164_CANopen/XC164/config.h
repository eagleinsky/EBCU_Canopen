#ifndef _CONFIG_H_
#define _CONFIG_H_
/*
#ifdef  __IAR_SYSTEMS_ICC__
#include <ioavr.h>
#include <intrinsics.h>
#include "iar.h"
#else	// GCC
#include <inttypes.h>
#include <avr\io.h>
#include <avr\interrupt.h>
#include <avr/pgmspace.h>
#include <avr\sleep.h>
#include <avr\wdt.h>
#endif	// GCC

*/
#define FOSC           8000        // �ⲿ���񣬳���������֮�⻹��Ҫ����дʱ������������
#ifndef F_CPU
#define F_CPU          (1000UL*FOSC) // WinAVR��Ҫ���
#endif
#define CAN_BAUDRATE    125

// ATMEL�ٷ��궨��
#define MAX_CAN_BUS_ID 1
#define SDO_MAX_LENGTH_TRANSFERT 32
#define SDO_MAX_SIMULTANEOUS_TRANSFERTS 1
#define NMT_MAX_NODE_ID 128
#define SDO_TIMEOUT_MS 3000U
#define MAX_NB_TIMER 8

#define CANOPEN_LITTLE_ENDIAN 1

#define US_TO_TIMEVAL_FACTOR 8

#define REPEAT_SDO_MAX_SIMULTANEOUS_TRANSFERTS_TIMES(repeat)\
repeat
#define REPEAT_NMT_MAX_NODE_ID_TIMES(repeat)\
repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat

#define EMCY_MAX_ERRORS 8
#define REPEAT_EMCY_MAX_ERRORS_TIMES(repeat)\
repeat repeat repeat repeat repeat repeat repeat repeat


#endif /* _CONFIG_H_ */
