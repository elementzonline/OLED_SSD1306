#ifndef _I2C_DEV_H__
#define _I2C_DEV_H__

/*
  Configuration done SSD1306
*/
#define SLAVE_ADDR_ACC        0x78

#define READ              0x01
#define WRITE             0x00

#define START             0x08
#define MT_SLA_ACK        0x18
#define MT_DATA_ACK       0x28
#define RPT_START         0x10




/*Function declarations*/

void InitI2C(void);
int start_i2c_transmission(void);
int send_i2c_slave_addr(unsigned char addr);
int send_i2c_slave_ram_addr(unsigned char addr);
int send_i2c_slave_data(unsigned char data);
int restart_i2c_transmission(void);
int read_i2c_one_byte(void);
int read_i2c_more_byte(void);
void stop_i2c_transmission(void);


void i2c_write(unsigned char addr,unsigned char data);
int acc_read(unsigned char addr);

#endif /* _I2C_DEV_H__ */
