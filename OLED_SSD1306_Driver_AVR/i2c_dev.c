#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
#include "i2c_dev.h"



void InitI2C(void)
{
  DDRC &= ~(BIT0|BIT1);
  //PORTC |= (BIT0|BIT1);   // commented since the module has on board pullup
  
  TWBR = 0x0F;                                        //SCL hz value set (250 khz) for fast mode
  //TWBR = 0x5F;                                        //SCL hz value set (77 khz) for strd mode
  TWSR = 0x00;                                        //prescalar value set(4)
}


int start_i2c_transmission(void)
{
  TWCR = (BIT7|BIT6|BIT5|BIT2);       //Send start condition of I2C                         
  while(!(TWCR & BIT7));              //wait untill start condition send operation  
  if ((TWSR & 0xF8) != START)
  {
    return -1;                       // start not transmitted
  }
  return 0;
}

int send_i2c_slave_addr(unsigned char addr)
{
  TWDR = (addr);                        //load the slave addr                      
  TWCR = (BIT7|BIT2);                 //Trigger send operation                          
  while(!(TWCR & BIT7));              //wait untill send operation to be finish
//  if ((TWSR & 0xF8) != MT_SLA_ACK)
//  {
//    return -1;                       // start not transmitted
//  }
  return 0;
}

int send_i2c_slave_ram_addr(unsigned char addr)
{
  TWDR = addr;                        //load the RAM addr                     
  TWCR = (BIT7|BIT2);                 //Trigger send operation                         
  while(!(TWCR & BIT7));              //wait untill send operation to be finish
  if ((TWSR & 0xF8) != MT_DATA_ACK)
  {
    return -1;                       // start not transmitted
  }
  return 0;
}

int send_i2c_slave_data(unsigned char data)
{
  TWDR = data;                        //load the RAM addr                     
  TWCR = (BIT7|BIT2);                 //Trigger send operation                         
  while(!(TWCR & BIT7));              //wait untill send operation to be finish
  return 0;
}

int restart_i2c_transmission(void)
{
  TWCR = (BIT7|BIT6|BIT5|BIT2);      //Send repeated start condition of I2C                         
  while(!(TWCR & BIT7));              //wait untill start condition send operation
  if ((TWSR & 0xF8) != RPT_START)
  {
    return -1;                       // repeated start not transmitted
  }
  return 0;
}

int read_i2c_one_byte(void)
{
  TWCR = (BIT7|BIT2);                 //Trigger read operation with nack out                       
  while(!(TWCR & BIT7));              //wait untill read operation to be finish  
  return TWDR;
}

int read_i2c_more_byte(void)
{
  TWCR = (BIT7|BIT6|BIT2);                 //Trigger read operation                        
  while(!(TWCR & BIT7));              //wait untill read operation to be finish 
  return TWDR;
}

void stop_i2c_transmission(void)
{
  TWCR = (BIT7|BIT6|BIT4|BIT2);       //STOP the I2C,yet disabled
}



void i2c_write(unsigned char addr,unsigned char data)
{    
  start_i2c_transmission();                           /* for sending start */                            
  send_i2c_slave_addr(SLAVE_ADDR_ACC | WRITE);        /*Load slave address + write and send*/ 
  send_i2c_slave_ram_addr(addr);   
  send_i2c_slave_data(data);                          /*send data*/ 
  stop_i2c_transmission();                            /*Stop i2c transmission*/  
  
}


int i2c_read(unsigned char addr)
{
  unsigned char data;
  
  start_i2c_transmission();                           /* for sending start */
  send_i2c_slave_addr(SLAVE_ADDR_ACC | WRITE);        /*Load slave address + write and send*/
  send_i2c_slave_ram_addr(addr);                      /*Load ram address pointer of slave and send*/ 
  restart_i2c_transmission();                         /*repeated start and send*/ 
  send_i2c_slave_addr(SLAVE_ADDR_ACC | READ);         /*Load slave address + read and send*/
  data =  read_i2c_one_byte();                        /*receives data and send nack to slave*/
  stop_i2c_transmission();                           /*Stop i2c transmission*/
  
  return data;  
}
