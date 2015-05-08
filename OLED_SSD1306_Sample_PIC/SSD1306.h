
#ifndef _SSD1306_H_
#define _SSD1306_H_

#define OLED_address  0x78
void sendcommand(unsigned char com);
void SendChar(unsigned char data);
void clear_display(void);
void setXY(unsigned char row, unsigned char col);
void reset_display(void);
void displayOff(void);
void displayOn(void);
void init_OLED();
void sendStrXY( char *string, int X, int Y); 

#endif