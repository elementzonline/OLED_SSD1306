#include <p18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <i2c.h>
#include "SSD1306.h"
#include "bitmaps.h"


void sendcommand(unsigned char com) {

IdleI2C();
   StartI2C();
   IdleI2C();
   putcI2C(OLED_address); //send address
   IdleI2C();
   putcI2C(0x80); //send data incomming
    IdleI2C();
    putcI2C(com);
    IdleI2C();
    //WriteI2C(0x80);
    //WriteI2C(com);
    StopI2C();





}

void SendChar(unsigned char data) {

    IdleI2C();
    StartI2C();
    IdleI2C();
    putcI2C(OLED_address); //send address
    IdleI2C();
    putcI2C(0x40); //send data incomming
    IdleI2C();
    putcI2C(data);
    IdleI2C();
   // WriteI2C(0x40);
    //WriteI2C(data);
    StopI2C();

}

void setXY(unsigned char row, unsigned char col) {
    sendcommand(0xb0 + row); //set page address
    sendcommand(0x00 + (8 * col & 0x0f)); //set low col address
    sendcommand(0x10 + ((8 * col >> 4)&0x0f)); //set high col address
}

void clear_display(void) {
    unsigned char i, k;
    for (k = 0; k < 8; k++) {
        setXY(k, 0);
        {
            for (i = 0; i < 128; i++) //clear all COL
            {
                SendChar(0); //clear all COL
                //delay(10);
            }
        }
    }
}

void reset_display(void) {
    displayOff();
    clear_display();

    displayOn();
}

void displayOff(void) {
    sendcommand(0xae); //display off
}

void displayOn(void) {
    sendcommand(0xaf); //display on
}



void init_OLED(){

    OpenI2C(MASTER, SLEW_ON);
    SSPADD = 29; //200kHz Baud clock(9) @20MHz
    //100kHz Baud clock(39) @16MHz

    ///////
    //OpenI2C(MASTER, SLEW_OFF);
    //StartI2C();
    sendcommand(0xae); //display off
    sendcommand(0xa6); //Set Normal Display (default)
    // Adafruit Init sequence for 128x64 OLED module
    sendcommand(0xAE); //DISPLAYOFF
    sendcommand(0xD5); //SETDISPLAYCLOCKDIV
    sendcommand(0x80); // the suggested ratio 0x80
    sendcommand(0xA8); //SSD1306_SETMULTIPLEX
    sendcommand(0x3F);
    sendcommand(0xD3); //SETDISPLAYOFFSET
    sendcommand(0x0); //no offset
    sendcommand(0x40 | 0x0); //SETSTARTLINE
    sendcommand(0x8D); //CHARGEPUMP
    sendcommand(0x14);
    sendcommand(0x20); //MEMORYMODE
    sendcommand(0x00); //0x0 act like ks0108

    sendcommand(0xA0 | 0x1); //SEGREMAP   //Rotate screen 180 deg
    //sendcommand(0xA0);

    sendcommand(0xC8); //COMSCANDEC  Rotate screen 180 Deg
    //sendcommand(0xC0);

    sendcommand(0xDA); //0xDA
    sendcommand(0x12); //COMSCANDEC
    sendcommand(0x81); //SETCONTRAS
    sendcommand(0xCF); //
    sendcommand(0xd9); //SETPRECHARGE
    sendcommand(0xF1);
    sendcommand(0xDB); //SETVCOMDETECT
    sendcommand(0x40);
    sendcommand(0xA4); //DISPLAYALLON_RESUME
    sendcommand(0xA6);

    /////////////////////////////////////////////////
    clear_display();
    sendcommand(0x2e); // stop scroll
    //----------------------------REVERSE comments----------------------------//
    //  sendcommand(0xa0);		//seg re-map 0->127(default)
    //  sendcommand(0xa1);		//seg re-map 127->0
    //  sendcommand(0xc8);
    //  delay(1000);
    //----------------------------REVERSE comments----------------------------//
    // sendcommand(0xa7);  //Set Inverse Display
    // sendcommand(0xae);		//display off
    sendcommand(0x20); //Set Memory Addressing Mode
    sendcommand(0x00); //Set Memory Addressing Mode ab Horizontal addressing mode
    //  sendcommand(0x02);         // Set Memory Addressing Mode ab Page addressing mode(RESET)
    setXY(0, 0);
    /*
     for(int i=0;i<128*8;i++)     // show 128* 64 Logo
     {
       SendChar(pgm_read_byte(logo+i));
     }
     */
    sendcommand(0xaf); //display on
}


//==========================================================//
// Prints a string in coordinates X Y, being multiples of 8.
// This means we have 16 COLS (0-15) and 8 ROWS (0-7).
void sendStrXY( char *string, int X, int Y)
{
  setXY(X,Y);
  unsigned char i=0;
  while(*string)
  {
    for(i=0;i<8;i++)
    {
      SendChar((myFont[*string-0x20][i]));
    }
    *string++;
  }
}
 
