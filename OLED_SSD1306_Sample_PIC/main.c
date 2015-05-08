#include <p18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <i2c.h>
#include <xc.h>
#include "config.h"
#include "bitmaps.h"
#include "SSD1306.h"

#define _XTAL_FREQ 20000000

void main() {



    init_OLED();

    reset_display();
    while (1) {
        sendcommand(0x2f);
        /*Draw image on Screen*/
        for (int i = 0; i < 128 * 8; i++) { // show 128* 64 Logo
            SendChar(logo2[i]);
        }
        // sendcommand(0x2f); /*Scroll on*/
        for (int j = 0; j < 100; j++) {
            __delay_ms(39);
        }
        // sendcommand(0x2e); /*Scroll off*/

        //displayOn();
        clear_display();
        sendcommand(0x2e);


        sendStrXY("Visit us", 2, 4);
        sendStrXY("on", 4, 7);
        sendStrXY("www.elementzonline.com", 6, 0);


        for (int j = 0; j < 100; j++) {
            __delay_ms(39);
        }
        clear_display();


    }
    //    StopI2C();
}

