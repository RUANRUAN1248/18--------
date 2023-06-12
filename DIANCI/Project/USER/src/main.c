/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"


/*
 * ϵͳƵ�ʣ��ɲ鿴board.h�е� FOSC �궨���޸ġ� // ????0??????
 * board.h�ļ���FOSC��ֵ����Ϊ0,������Զ�����ϵͳƵ��Ϊ33.1776MHZ
 * ��board_init��,�Ѿ���P54��������Ϊ��λ
 * �����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����
 */
void main()
{
	DisableGlobalIRQ();
	board_init();			// ��ʼ���Ĵ���,��ɾ���˾���롣
	
	//�����ʼ��
	//�����ʼ��
	//ADC ͨ����ʼ��
	//������
	//oled��ʼ��
	//������
	//������
	//�ж϶�ʱ��
	//pwm_init(PWMA_CH4N_P17, 1700)
	Use_adc_Init();
	DMA_config();
	OLED_Init();				//��ʼ��OLED
	OLED_Clear();
	OLED_DisPlay_On();			//��ʼ��LED
	
 	EnableGlobalIRQ();
  while(1)
	{ 
			
		 // �˴���д��Ҫѭ��ִ�еĴ���
		shuju_adc();
		
		 delay_ms(200);	//200ms���һ�β������������۲�
		OLED_Refresh();
		
  }
}

   


//Use_adc_Init();
//	DMA_config();
//	EnableGlobalIRQ();   
//    while(1)
//	{
//		uint8 i,n;
//		 // �˴���д��Ҫѭ��ִ�еĴ���
//		 delay_ms(200);	//200ms���һ�β������������۲�
//		
//		if(DmaADCFlag)  //�ж�ADC DMA�����Ƿ����
//		{
//			DmaADCFlag = 0; //�����ɱ�־
//			for(i=0; i<ADC_CH; i++)     //��ӡÿ������ͨ���Ĳ������
//			{
//				printf("%d:",i);
//				for(n=0; n<ADC_DATA; n++)   //��ӡ��ǰͨ���Ĳ�������
//				{
//					printf("%02d ",DmaAdBuffer[i][n]);	//��1������,...,��n������,ADͨ��,ƽ������,ƽ��ֵ
//				}
//				
//				printf("\r\n"); //��������س����з�
//			}
//			printf("\r\n");     //��������س����з�
//			DMA_ADC_TRIG();		//���´���������һ��ת��
//		}
//		
//    }



   //   gpio_mode(INT0_P32,GPI_IMPEDANCE);
	//   exit_init(INT0_P32,FALLING_EDGE);   //��ʼ��P32 ��Ϊ�ⲿ�ж�����
  //	   motor_init();
  //	   pwm_init(PWMB_CH3_P22 , 50,3390 );     //��ʼ��PWMA  ʹ������P7.4  ���PWMƵ��50HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100











