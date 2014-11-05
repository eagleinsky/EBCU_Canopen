#ifndef __APPLICFG_AVR__
#define __APPLICFG_AVR__

#include <string.h>
#include <stdio.h>

// 定义数据类型
// 整数
#define INTEGER8 signed char
#define INTEGER16 short
#define INTEGER24
#define INTEGER32 long
#define INTEGER40
#define INTEGER48
#define INTEGER56
#define INTEGER64

// 无符号整数
#define UNS8   unsigned char
#define UNS16  unsigned short
#define UNS32  unsigned long
/*
#define UNS24
#define UNS40
#define UNS48
#define UNS56
#define UNS64
*/ 


// 浮点
#define REAL32	float
#define REAL64 double


// 消息功能，在PC上显示
#ifdef DEBUG_ERR_CONSOLE_ON
#define MSG_ERR(num, str, val)      \
          printf(num, ' ');	\
          printf(str);		\
          printf(val);		\
          printf('\n');
#else
#    define MSG_ERR(num, str, val)
#endif


#ifdef DEBUG_WAR_CONSOLE_ON
#define MSG_WAR(num, str, val)      \
          printf(num, ' ');	\
          printf(str);		\
          printf(val);		\
          printf('\n');
#else
#    define MSG_WAR(num, str, val)
#endif

typedef void* CAN_HANDLE;

typedef void* CAN_PORT;

#endif


