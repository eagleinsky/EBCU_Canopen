#ifndef __can_xc164__
#define __can_xc164__
//#include "config.h"
#include "can_fest.h"
/*
// ????
#define NB_RX_MOB                       13	// ???8
// ????
#define NB_TX_MOB                       (NB_MOB - NB_RX_MOB)

#if (NB_TX_MOB < 1)
#error define less RX Mobs, you must have at least 1 TX MOb!
#elif (NB_RX_MOB < 8)
#error define at least 8 RX MObs!
#endif

#define START_TX_MOB                    NB_RX_MOB
#define TX_INT_MSK			((0x7F << (7 - NB_TX_MOB)) & 0x7F)

//??????*/
//unsigned char canInit(unsigned int bitrate);
unsigned char canSend(CAN_PORT notused, Message *m);
unsigned char canReceive(Message *m);
//unsigned char canChangeBaudRate_driver( CAN_HANDLE fd, char* baud);
#endif
