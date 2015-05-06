/*
 * main.cpp
 *
 *  Created on: 29-Oct-2014
 *      Author: Dhanish Vijayan
 *      Company: Elementz Engineers Guild Pvt Ltd
 */


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/pgmspace.h>
#include "main.h"
#include "ssd1306.h"
#include "com_def.h"
#include "bitmaps.h"


int main(void){
	_delay_ms(1000);

/* Initialize OLED Display */
	init_OLED();
	reset_display();

	while(1){

		/*Draw image on Screen*/
		for(int i=0;i<128*8;i++)     // show 128* 64 Logo
					SendChar(pgm_read_byte(logo2+i));

		sendcommand(0x2f);  /*Scroll on*/
		_delay_ms(4000);
		sendcommand(0x2e);  /*Scroll off*/


		clear_display();

/* Draw text from font */
		sendStrXY("   VISIT US AT  ",0,0);
		sendStrXY("      WWW.      ",2,0);
		sendStrXY(" ELEMENTZONLINE ",4,0);
		sendStrXY("      .COM      ",6,0);

		_delay_ms(8000);
		clear_display();
	}
return 0;
}

