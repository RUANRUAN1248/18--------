#include "headfile.h"
bit DmaADCFlag=0;
uint8 xdata DmaAdBuffer[ADC_CH][ADC_DATA];
//========================================================================
// ����: void DMA_ADC_Inilize(DMA_ADC_InitTypeDef *DMA)
// ����: DMA ADC ��ʼ������.
// ����: DMA: �ṹ����,��ο�DMA.h��Ķ���.
// ����: none.
// �汾: V1.0, 2021-05-17
//========================================================================
void DMA_ADC_Inilize(DMA_ADC_InitTypeDef *DMA)
{
    DMA_ADC_STA = 0x00;             // ���DMA״̬�Ĵ���
		DMA_ADC_CHSW1 = (uint8)(DMA->DMA_Channel >> 8);    // ����DMAͨ�����ֽ�
		DMA_ADC_CHSW0 = (uint8)(DMA->DMA_Channel);         // ����DMAͨ�����ֽ�
		DMA_ADC_RXAH = (uint8)(DMA->DMA_Buffer >> 8);       // ����DMA���յ�ַ���ֽ�
		DMA_ADC_RXAL = (uint8)(DMA->DMA_Buffer);            // ����DMA���յ�ַ���ֽ�
		DMA_ADC_CFG2 = DMA->DMA_Times;                   // ����DMA�������
    if (DMA->DMA_Enable == ENABLE)
					DMA_ADC_CR |= 0x80;     // ʹ��ADC DMA
		else
			    DMA_ADC_CR &= ~0x80;    // ��ֹADC DMA
}
/******************** DMA ���� ********************/
void	DMA_config(void)
{
		DMA_ADC_InitTypeDef		DMA_ADC_InitStructure;		//�ṹ����

		DMA_ADC_InitStructure.DMA_Enable = ENABLE;			//DMAʹ��  	ENABLE,DISABLE
		DMA_ADC_InitStructure.DMA_Channel = 0x0f80;			//ADCͨ��ʹ�ܼĴ���, 1:ʹ��, bit15~bit0 ��Ӧ ADC15~ADC0
		DMA_ADC_InitStructure.DMA_Buffer = (uint16)DmaAdBuffer;	//ADCת�����ݴ洢��ַ
		DMA_ADC_InitStructure.DMA_Times = ADC_4_Times;	//ÿ��ͨ��ת������, ADC_1_Times,ADC_2_Times,ADC_4_Times,ADC_8_Times,ADC_16_Times,ADC_32_Times,ADC_64_Times,ADC_128_Times,ADC_256_Times
		DMA_ADC_Inilize(&DMA_ADC_InitStructure);		//��ʼ��
		NVIC_DMA_ADC_Init(ENABLE,Priority_0,Priority_0);		//�ж�ʹ��, ENABLE/DISABLE; ���ȼ�(�͵���) Priority_0~Priority_3; �������ȼ�(�͵���) Priority_0~Priority_3
		DMA_ADC_TRIG();		//��������ת��
}
//========================================================================
// ����: NVIC_DMA_ADC_Init
// ����: DMA ADCǶ�������жϿ�������ʼ��. 
// ����: State:    �ж�ʹ��״̬, ENABLE/DISABLE.
// ����: Priority: �ж����ȼ�, Priority_0,Priority_1,Priority_2,Priority_3.
// ����: Bus_Priority: �������߷������ȼ�, Priority_0,Priority_1,Priority_2,Priority_3.
// ����: ִ�н�� SUCCESS/FAIL.
// �汾: V1.0, 2021-05-21
//========================================================================
uint8 NVIC_DMA_ADC_Init(uint8 State, uint8 Priority, uint8 Bus_Priority)
{
	DMA_ADC_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_ADC_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_ADC_CFG |= Bus_Priority;	//�������߷������ȼ�
	if(State == ENABLE)
		DMA_ADC_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_ADC_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}


