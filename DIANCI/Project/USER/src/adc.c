#include "headfile.h"



//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADC初始化
//  @param      adcn            
//  @param      speed      		
//  @return     void
//  Sample usage:   初始化引脚为ADC功能,ADC时钟频率：SYSclk/2
//-------------------------------------------------------------------------------------------------------------------
/*
  0(1.0)  //1(1.1) 2(5.4) 3(1.3) //4(1.4) 5(1.5) //6(1.6) 7(1.7) 8(0.0) 9(0.1) 10(0.2) 
	11(0.3) 12(0.4) 13(0.5) 14(0.6)
*/
void Use_adc_Init(void)
{
	
//	adc_init(ADC_P05, ADC_SYSclk_DIV_2);//ADC通道13
	adc_init(ADC_P00, ADC_SYSclk_DIV_2);//8
	adc_init(ADC_P17, ADC_SYSclk_DIV_2);//7
	adc_init(ADC_P01, ADC_SYSclk_DIV_2);//9
	adc_init(ADC_P02, ADC_SYSclk_DIV_2);//10
	adc_init(ADC_P03, ADC_SYSclk_DIV_2);//11	
	
	
}
////-------------------------------------------------------------------------------------------------------------------
////  @brief      ADC转换一次读值
////  @param      adcn            选择ADC通道
////  @param      resolution      分辨率
////  @return     void
////  Sample usage:               adc_convert(ADC_P10, ADC_10BIT);
////-------------------------------------------------------------------------------------------------------------------
///*经过例程验证初始化不需要再配置，直接多次进行单次转换即可*/DMA不用读，直接转换
//void Read_adc_once(void)
//{
//   adc_data[0] = adc_once(ADC_P11,ADC_12BIT);
//	 adc_data[1] = adc_once(ADC_P13,ADC_12BIT);
//	 adc_data[2] = adc_once(ADC_P14,ADC_12BIT);
//	 adc_data[3] = adc_once(ADC_P15,ADC_12BIT);
//	 adc_data[4] = adc_once(ADC_P16,ADC_12BIT);
//}

void shuju_adc(void)
{
   uint8 i,n,x=0,y=0;
	
   uint16 dat[5*ADC_CH+1];
	 
	if(DmaADCFlag)  //判断ADC DMA采样是否完成
		{
			DmaADCFlag = 0; //清除完成标志   
		
				y=0;
			  OLED_ShowNum(0,0,17,2,12);	
			  OLED_ShowNum(0,12,00,2,12);	
			  OLED_ShowNum(0,24,01,2,12);	
			  OLED_ShowNum(0,36,02,2,12);	
			  OLED_ShowNum(0,48,03,2,12);	
//        OLED_ShowNum(70,0,5,1,12);			
				OLED_ShowString(12,0,":",12);
	      OLED_ShowString(12,12,":",12);	
	      OLED_ShowString(12,24,":",12);	
	      OLED_ShowString(12,36,":",12);	
	      OLED_ShowString(12,48,":",12);	
//			  OLED_ShowString(76,0,":",12);	
			for(i=0; i<ADC_CH; i++)     //打印每个设置通道的采样结果//5
			{
         if(i<5)  x=18;
				else	if(i==5) { x=82;y=0;}
				else y=0;
				for(n=0; n<ADC_DATA; n=n+2)   //打印当前通道的采样数据//12
				{				
					dat[i]=DmaAdBuffer[i][n]<<8;
					dat[i]=dat[i]|DmaAdBuffer[i][n+1];
					
					if(n==10)
					{
						
						OLED_ShowNum(x,y,dat[i],4,12);	
            OLED_Refresh();						
					y=y+12;	
					}
			}	      		
			}
			
		 DMA_ADC_TRIG();		//重新触发启动下一次转换
  }	
}


