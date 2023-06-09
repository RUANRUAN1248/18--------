#include "headfile.h"
bit DmaADCFlag=0;
uint8 xdata DmaAdBuffer[ADC_CH][ADC_DATA];
//========================================================================
// 函数: void DMA_ADC_Inilize(DMA_ADC_InitTypeDef *DMA)
// 描述: DMA ADC 初始化程序.
// 参数: DMA: 结构参数,请参考DMA.h里的定义.
// 返回: none.
// 版本: V1.0, 2021-05-17
//========================================================================
void DMA_ADC_Inilize(DMA_ADC_InitTypeDef *DMA)
{
    DMA_ADC_STA = 0x00;             // 清除DMA状态寄存器
		DMA_ADC_CHSW1 = (uint8)(DMA->DMA_Channel >> 8);    // 设置DMA通道高字节
		DMA_ADC_CHSW0 = (uint8)(DMA->DMA_Channel);         // 设置DMA通道低字节
		DMA_ADC_RXAH = (uint8)(DMA->DMA_Buffer >> 8);       // 设置DMA接收地址高字节
		DMA_ADC_RXAL = (uint8)(DMA->DMA_Buffer);            // 设置DMA接收地址低字节
		DMA_ADC_CFG2 = DMA->DMA_Times;                   // 设置DMA传输次数
    if (DMA->DMA_Enable == ENABLE)
					DMA_ADC_CR |= 0x80;     // 使能ADC DMA
		else
			    DMA_ADC_CR &= ~0x80;    // 禁止ADC DMA
}
/******************** DMA 配置 ********************/
void	DMA_config(void)
{
		DMA_ADC_InitTypeDef		DMA_ADC_InitStructure;		//结构定义

		DMA_ADC_InitStructure.DMA_Enable = ENABLE;			//DMA使能  	ENABLE,DISABLE
		DMA_ADC_InitStructure.DMA_Channel = 0x0f80;			//ADC通道使能寄存器, 1:使能, bit15~bit0 对应 ADC15~ADC0
		DMA_ADC_InitStructure.DMA_Buffer = (uint16)DmaAdBuffer;	//ADC转换数据存储地址
		DMA_ADC_InitStructure.DMA_Times = ADC_4_Times;	//每个通道转换次数, ADC_1_Times,ADC_2_Times,ADC_4_Times,ADC_8_Times,ADC_16_Times,ADC_32_Times,ADC_64_Times,ADC_128_Times,ADC_256_Times
		DMA_ADC_Inilize(&DMA_ADC_InitStructure);		//初始化
		NVIC_DMA_ADC_Init(ENABLE,Priority_0,Priority_0);		//中断使能, ENABLE/DISABLE; 优先级(低到高) Priority_0~Priority_3; 总线优先级(低到高) Priority_0~Priority_3
		DMA_ADC_TRIG();		//触发启动转换
}
//========================================================================
// 函数: NVIC_DMA_ADC_Init
// 描述: DMA ADC嵌套向量中断控制器初始化. 
// 参数: State:    中断使能状态, ENABLE/DISABLE.
// 参数: Priority: 中断优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 参数: Bus_Priority: 数据总线访问优先级, Priority_0,Priority_1,Priority_2,Priority_3.
// 返回: 执行结果 SUCCESS/FAIL.
// 版本: V1.0, 2021-05-21
//========================================================================
uint8 NVIC_DMA_ADC_Init(uint8 State, uint8 Priority, uint8 Bus_Priority)
{
	DMA_ADC_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_ADC_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_ADC_CFG |= Bus_Priority;	//数据总线访问优先级
	if(State == ENABLE)
		DMA_ADC_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_ADC_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}


