/*
 * ssd1306.h
 *
 *  Created on: 05-May-2015
 *      Author: root
 */

#ifndef SSD1306_H_
#define SSD1306_H_

void sendcommand(unsigned char com);
void SendChar(unsigned char data);
void displayOn(void);
void displayOff(void);
void setXY(unsigned char row,unsigned char col);
void sendStrXY( char *string, int X, int Y);
void init_OLED(void);
void clear_display(void);
void reset_display();

#endif /* SSD1306_H_ */
