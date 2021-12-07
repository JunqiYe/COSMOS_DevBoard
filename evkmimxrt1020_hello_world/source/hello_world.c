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
#include "com_wrap.h"

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

// Everything is 64bits to for data alignment
typedef struct beacon
{
	uint64_t length;
	uint64_t id;
	uint64_t temp;
	uint64_t voltage;
	uint64_t current;
	uint64_t charge;
	uint64_t state;
} beacon;

soh_t mySoh;

beacon b = {1};


void receiveCmd();
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
    b.temp = 123;
    b.voltage = 21;
    b.current = 3;
    b.state = 1;
    b.charge = 100;

    while (1)
    {
    	receiveCmd();
    	sendTlm();
    	delay(99999999);
    }
}

void delay(int i) {
	volatile int delay = i;
	for (int i = 0; i < delay; i++) {}
}


void sendTlm()
{
//  mySoh.length = sizeof(mySoh);
//  writeTlm((const char*)&mySoh, sizeof(mySoh));
	b.length = (uint64_t)(sizeof(b));
//	PRINTF("%x\r\n", &(b.length));
//	PRINTF("%x\r\n", &(b.id));
//	PRINTF("%x\r\n", &(b.temp));
//	PRINTF("%x\r\n", &(b.voltage));
//	PRINTF("%x\r\n", &(b.current));
//	PRINTF("%x\r\n", &(b.charge));
//	PRINTF("%x\r\n", &(b.state));
//	PRINTF("%x\r\n", b.temp);
	writeTlm((const char*)&b, sizeof(b));
//	PRINTF("\r\n");
}

uint64_t cmd_in;
void receiveCmd(){
	cmd_in = 0;
	for (int i = 0; i < sizeof(cmd_in); i++) {
		cmd_in |= ((uint8_t)GETCHAR()) << 8*i;
	}
	if(cmd_in != 0) {
		b.state = cmd_in;
	}


}


void writeTlm(const char* pkt, uint8_t size)
{
  for(int i=0; i<size; i++)
  {
//	if (i!= 0 && i % 8 == 0) PRINTF("\r\n");
    PRINTF("%c", pkt[i]);

  }
}
