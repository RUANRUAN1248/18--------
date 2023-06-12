/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"


/*
 * 系统频率，可查看board.h中的 FOSC 宏定义修改。 // ????0??????
 * board.h文件中FOSC的值设置为0,则程序自动设置系统频率为33.1776MHZ
 * 在board_init中,已经将P54引脚设置为复位
 * 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可
 */
void main()
{
	DisableGlobalIRQ();
	board_init();			// 初始化寄存器,勿删除此句代码。
	
	//电机初始化
	//舵机初始化
	//ADC 通道初始化
	//陀螺仪
	//oled初始化
	//蜂鸣器
	//编码器
	//中断定时器
	//pwm_init(PWMA_CH4N_P17, 1700)
	Use_adc_Init();
	DMA_config();
	OLED_Init();				//初始化OLED
	OLED_Clear();
	OLED_DisPlay_On();			//初始化LED
	
 	EnableGlobalIRQ();
  while(1)
	{ 
			
		 // 此处编写需要循环执行的代码
		shuju_adc();
		
		 delay_ms(200);	//200ms输出一次采样结果，方便观察
		OLED_Refresh();
		
  }
}

   


//Use_adc_Init();
//	DMA_config();
//	EnableGlobalIRQ();   
//    while(1)
//	{
//		uint8 i,n;
//		 // 此处编写需要循环执行的代码
//		 delay_ms(200);	//200ms输出一次采样结果，方便观察
//		
//		if(DmaADCFlag)  //判断ADC DMA采样是否完成
//		{
//			DmaADCFlag = 0; //清除完成标志
//			for(i=0; i<ADC_CH; i++)     //打印每个设置通道的采样结果
//			{
//				printf("%d:",i);
//				for(n=0; n<ADC_DATA; n++)   //打印当前通道的采样数据
//				{
//					printf("%02d ",DmaAdBuffer[i][n]);	//第1组数据,...,第n组数据,AD通道,平均余数,平均值
//				}
//				
//				printf("\r\n"); //串口输出回车换行符
//			}
//			printf("\r\n");     //串口输出回车换行符
//			DMA_ADC_TRIG();		//重新触发启动下一次转换
//		}
//		
//    }



   //   gpio_mode(INT0_P32,GPI_IMPEDANCE);
	//   exit_init(INT0_P32,FALLING_EDGE);   //初始化P32 作为外部中断引脚
  //	   motor_init();
  //	   pwm_init(PWMB_CH3_P22 , 50,3390 );     //初始化PWMA  使用引脚P7.4  输出PWM频率50HZ   占空比为百分之 pwm_duty / PWM_DUTY_MAX * 100











