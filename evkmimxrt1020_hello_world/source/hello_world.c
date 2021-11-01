/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
typedef struct soh_t
{
  uint8_t length;
  uint8_t id;
  uint8_t data;

}soh_t;

typedef struct beacon
{
	uint8_t length;
	uint8_t id;
	uint64_t temp;
	uint64_t voltage;
	uint64_t current;
	uint16_t charge;
	uint8_t state;
} beacon;

soh_t mySoh;

beacon b = {1};

void delay(int i);
void sendTlm();
void writeTlm(const char* pkt, uint8_t size);

int main(void)
{
    char ch;

    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    //PRINTF("hello world.\r\n");
    mySoh.id = 1;
    mySoh.data = 250;

    b.id = 2;
    b.length = 8;
    b.temp = 1024;
    b.voltage = 21;
    b.current = 3;
    b.state = 1;
    b.charge = 100;

    while (1)
    {
//    	processCmds();
    	sendTlm();
    	delay(99999999);
//    	PRINTF("9");
//        ch = GETCHAR();
//        PRINTF("%c\n", ch);
//        PUTCHAR(ch);
    }
}

void delay(int i) {
	volatile int delay = i;
	for (int i = 0; i < delay; i++) {}
}

uint8_t mask = 0xff;
void send_beacon(beacon* b) {
	// temp
	for (int i = 0; i < sizeof(b->temp); i++) {
		uint8_t rst = (long)(b->temp) >> 8*i;
		//printf(“%x”, rst);
		rst &= mask;
		//printf(“%x”, rst);
		//printf(“\n”);
	}
}

void sendTlm()
{
//  mySoh.length = sizeof(mySoh);
//  writeTlm((const char*)&mySoh, sizeof(mySoh));
	b.length = (uint8_t)(sizeof(b));
	writeTlm((const char*)&b, sizeof(b));
}

//void processCmds(){
//	while (SCANF()){
//		mySoh.data = GETCHAR();
//	}
//
//}

void writeTlm(const char* pkt, uint8_t size)
{
  for(int i=0; i<size; i++)
  {
    PRINTF("%c", pkt[i]);
  }
}
