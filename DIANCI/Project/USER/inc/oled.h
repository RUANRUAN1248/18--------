#ifndef __OLED_H
#define __OLED_H 

#include "common.h"
#include "board.h"
#include "zf_spi.h"
#include "zf_delay.h"

//-----------------OLED端口定义---------------- 

#define OLED_SPI_N 			SPI_CH1
#define OLED_SPI_SCLK_PIN   SPI_CH1_SCLK_P15  //D0_sck
#define OLED_SPI_MOSI_PIN   SPI_CH1_MOSI_P13   //D1_sda
#define OLED_SPI_MISO_PIN   SPI_CH1_MISO_P14	//定义SPI_MISO引脚  OLED屏幕没有MISO引脚，但是这里任然需要定义，在spi的初始化时需要使用
#define OLED_SPI_REST_PIN 	P20				//液晶复位引脚定义
#define OLED_SPI_DC_PIN   	P21   			//液晶命令位引脚定义
#define OLED_SPI_CS_PIN     P22				//定义硬件SPI_CS引脚


#define OLED_SPI_RST(x)   	OLED_SPI_REST_PIN = x
#define OLED_SPI_DC(x)    	OLED_SPI_DC_PIN = x
#define OLED_SPI_CS(x) 		OLED_SPI_CS_PIN = x  

#define OLED_RES_Clr() OLED_SPI_REST_PIN = 0
#define OLED_RES_Set() OLED_SPI_REST_PIN = 1
#define OLED_DC_Clr()  OLED_SPI_DC_PIN = 0
#define OLED_DC_Set()  OLED_SPI_DC_PIN = 1
#define OLED_CS_Clr() OLED_SPI_CS_PIN = 0
#define OLED_CS_Set() OLED_SPI_CS_PIN = 1


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

#define u8 unsigned char
#define u32 unsigned int

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 cmd);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y);
//void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2);
//void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1);
void OLED_ScrollDisplay(u8 num,u8 space);
void OLED_WR_BP(u8 x,u8 y);
void OLED_ShowPicture(u8 x0,u8 y0,u8 x1,u8 y1,u8 BMP[]);
void OLED_Init(void);

#endif


