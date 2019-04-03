#include "c8051F020.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "servo_V.h"
//#include "distance.h"
#include "ringB/UART0_RingBuffer_lib.h"
#include "ringB/UART1_RingBuffer_lib.h"

#define R90 430

int xdata dS = 20;
char xdata D_nbr = 0;


int process(char* cmd_str) {
	char xdata retourC[8];
	int xdata retourI;
	char cmd[4] = "\0";
	char param1[7] = "\0";
	char param2[7] = "\0";
	char param3[7] = "\0";
	char param4[7] = "\0";
	sscanf(cmd_str, "%s %s %s %s %s", cmd, param1, param2, param3, param4);
	
	if (strcmp(cmd, "Q") == 0) {	//arret urgence
		//TODO
		return 0;
	}
	
	if (strcmp(cmd, "D") == 0) {	//debut epreuve
		D(param1);
		return 0;
	}
	
	if (D_nbr != 0) {
		
		
		if (strcmp(cmd, "CS") == 0) {		//servo V
			if (setServoVertical(cmd, param1, param2) == 1) {
				valid();
			}
			else {
				invalid();
			}
			return 0;
		}
	}
		
	invalid();
	return 1;
}

////////////////////////////////////////////////////////
//interrupt function
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
//functions
////////////////////////////////////////////////////////

void valid() {
	serOutstring(">\r\n");
}

void invalid() {
	serOutstring("#\r\n");
}