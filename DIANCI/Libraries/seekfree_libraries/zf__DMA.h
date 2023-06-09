#ifndef _ZF__DMA_H
#define _ZF__DMA_H


#define DMA_ADC_TRIG()					DMA_ADC_CR |= 0x40
#define DMA_ADCIF_CLR()					DMA_ADC_STA &= ~0x01

#define DMA_M2M_TRIG()					DMA_M2M_CR |= 0x40
#define DMA_M2MIF_CLR()					DMA_M2M_STA &= ~0x01

#define DMA_UR1T_TRIG()					DMA_UR1T_CR |= 0x40
#define DMA_UR2T_TRIG()					DMA_UR2T_CR |= 0x40
#define DMA_UR3T_TRIG()					DMA_UR3T_CR |= 0x40
#define DMA_UR4T_TRIG()					DMA_UR4T_CR |= 0x40

#define DMA_UR1R_TRIG()					DMA_UR1R_CR |= 0x20
#define DMA_UR2R_TRIG()					DMA_UR2R_CR |= 0x20
#define DMA_UR3R_TRIG()					DMA_UR3R_CR |= 0x20
#define DMA_UR4R_TRIG()					DMA_UR4R_CR |= 0x20

#define DMA_SPI_TRIG_M()				DMA_SPI_CR |= 0x40		//SPI触发主机模式
#define DMA_SPI_TRIG_S()				DMA_SPI_CR |= 0x20		//SPI触发从机模式

#define DMA_UR1R_CLRFIFO()			DMA_UR1R_CR |= 0x01	//清空 DMA FIFO
#define DMA_UR2R_CLRFIFO()			DMA_UR2R_CR |= 0x01
#define DMA_UR3R_CLRFIFO()			DMA_UR3R_CR |= 0x01
#define DMA_UR4R_CLRFIFO()			DMA_UR4R_CR |= 0x01
#define DMA_SPI_CLRFIFO()				DMA_SPI_CR |= 0x01
#define DMA_LCM_CLRFIFO()				DMA_LCM_CR |= 0x01

#define DMA_ADC_CLR_STA()				DMA_ADC_STA = 0
#define DMA_SPI_CLR_STA()				DMA_SPI_STA = 0
#define DMA_M2M_CLR_STA()				DMA_M2M_STA = 0
#define DMA_UR1T_CLR_STA()			DMA_UR1T_STA = 0
#define DMA_UR1R_CLR_STA()			DMA_UR1R_STA = 0
#define DMA_UR2T_CLR_STA()			DMA_UR2T_STA = 0
#define DMA_UR2R_CLR_STA()			DMA_UR2R_STA = 0
#define DMA_UR3T_CLR_STA()			DMA_UR3T_STA = 0
#define DMA_UR3R_CLR_STA()			DMA_UR3R_STA = 0
#define DMA_UR4T_CLR_STA()			DMA_UR4T_STA = 0
#define DMA_UR4R_CLR_STA()			DMA_UR4R_STA = 0

#define SET_M2M_TX_FIFO(n)			{DMA_M2M_TXAH = (n>>8); DMA_M2M_TXAL = (n);}
#define SET_M2M_RX_FIFO(n)			{DMA_M2M_RXAH = (n>>8); DMA_M2M_RXAL = (n);}

#define SET_DMA_ADC_CR(n)				DMA_ADC_CR = (n)
#define SET_DMA_SPI_CR(n)				DMA_SPI_CR = (n)
#define SET_DMA_M2M_CR(n)				DMA_M2M_CR = (n)
#define SET_DMA_UR1T_CR(n)			DMA_UR1T_CR = (n)
#define SET_DMA_UR1R_CR(n)			DMA_UR1R_CR = (n)
#define SET_DMA_UR2T_CR(n)			DMA_UR2T_CR = (n)
#define SET_DMA_UR2R_CR(n)			DMA_UR2R_CR = (n)
#define SET_DMA_UR3T_CR(n)			DMA_UR3T_CR = (n)
#define SET_DMA_UR3R_CR(n)			DMA_UR3R_CR = (n)
#define SET_DMA_UR4T_CR(n)			DMA_UR4T_CR = (n)
#define SET_DMA_UR4R_CR(n)			DMA_UR4R_CR = (n)

#define SET_LCM_DMA_LEN(n)			{DMA_LCM_AMTH = (n>>8); DMA_LCM_AMT = (n);}
#define DMA_LCM_TRIG_WC()				DMA_LCM_CR |= 0xC0		//触发 LCM_DMA 发命令操作
#define DMA_LCM_TRIG_WD()				DMA_LCM_CR |= 0xA0		//触发 LCM_DMA 发数据操作
#define DMA_LCM_TRIG_RC()				DMA_LCM_CR |= 0x90		//触发 LCM_DMA 读命令操作
#define DMA_LCM_TRIG_RD()				DMA_LCM_CR |= 0x88		//触发 LCM_DMA 读数据操作

#define DMA_I2CT_TRIG()					DMA_I2CT_CR |= 0x40
#define DMA_I2CR_TRIG()					DMA_I2CR_CR |= 0x40
#define DMA_I2CR_CLRFIFO()			DMA_I2CR_CR |= 0x01	//清空 DMA FIFO
#define SET_I2CT_DMA_LEN(n)			{DMA_I2CT_AMTH = (n>>8); DMA_I2CT_AMT = (n);}
#define SET_I2CR_DMA_LEN(n)			{DMA_I2CR_AMTH = (n>>8); DMA_I2CR_AMT = (n);}
#define SET_I2C_DMA_ST(n)				{DMA_I2C_ST2 = (n>>8); DMA_I2C_ST1 = (n);}
#define I2C_DMA_Enable()				DMA_I2C_CR |= 0x01
#define I2C_DMA_Disable()				DMA_I2C_CR &= ~0x01

//========================================================================
//                              常量声明
//========================================================================

#define DMA_ENABLE				0x80
#define M2M_TRIG					0x40
#define ADC_TRIG					0x40
#define UR_T_TRIG					0x40
#define UR_R_TRIG					0x20
#define SPI_TRIG_M				0x40
#define SPI_TRIG_S				0x20
#define CLR_FIFO					0x01

#define ADC_1_Times				7
#define ADC_2_Times				8
#define ADC_4_Times				9
#define ADC_8_Times				10
#define ADC_16_Times			11
#define ADC_32_Times			12
#define ADC_64_Times			13
#define ADC_128_Times			14
#define ADC_256_Times			15

#define M2M_ADDR_INC			0
#define M2M_ADDR_DEC			1

#define SPI_SS_P12				0
#define SPI_SS_P22				1
#define SPI_SS_P74				2
#define SPI_SS_P35				3

#define	ADC_CH		5			/* 1~16, ADC转换通道数, 需同步修改转换通道 */
#define	ADC_DATA	12			/* 6~n, 每个通道ADC转换数据总数, 2*转换次数+4, 需同步修改转换次数 */

extern bit DmaADCFlag;
extern uint8 xdata DmaAdBuffer[ADC_CH][ADC_DATA];
typedef struct
{
	uint8	DMA_Enable;					//DMA使能  	ENABLE,DISABLE
	uint16	DMA_Channel;				//ADC通道使能寄存器, 1:使能, bit15~bit0 对应 ADC15~ADC0
	uint16	DMA_Buffer;					//ADC转换数据存储地址
	uint8	DMA_Times;					//每个通道转换次数, ADC_1_Times,ADC_2_Times,ADC_4_Times,ADC_8_Times,ADC_16_Times,ADC_32_Times,ADC_64_Times,ADC_128_Times,ADC_256_Times
} DMA_ADC_InitTypeDef;
void DMA_ADC_Inilize(DMA_ADC_InitTypeDef *DMA);
uint8 NVIC_DMA_ADC_Init(uint8 State, uint8 Priority, uint8 Bus_Priority);
void	DMA_config(void);

#endif

