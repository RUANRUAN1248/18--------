#include "headfile.h"


int16 templ_pluse = 0;
int16 tempr_pluse = 0;
/*���� CTIM0_P34��ѡ��ʱ��0������P3.4�������ö�ʱ��0��TL0��TH0�Ĵ���Ϊ0����TMOD�Ĵ����ĵ�2λ����Ϊ1����ʾѡ���ⲿ����ģʽ�����������ʱ��0��

���� CTIM1_P35��ѡ��ʱ��1������P3.5�������ö�ʱ��1��TL1��TH1�Ĵ���Ϊ0����TMOD�Ĵ����ĵ�6λ����Ϊ1����ʾѡ���ⲿ����ģʽ�����������ʱ��1��

���� CTIM2_P12��ѡ��ʱ��2������P1.2�������ö�ʱ��2��T2L��T2H�Ĵ���Ϊ0����AUXR�Ĵ����ĵ�3��4λ����Ϊ1����ʾѡ���ⲿ����ģʽ����������ʱ��2��

���� CTIM3_P04��ѡ��ʱ��3������P0.4�������ö�ʱ��3��T3L��T3H�Ĵ���Ϊ0����T4T3M�Ĵ����ĵ�2��3λ����Ϊ1����ʾѡ���ⲿ����ģʽ����������ʱ��3��

���� CTIM4_P06��ѡ��ʱ��4������P0.6�������ö�ʱ��4��T4L��T4H�Ĵ���Ϊ0����T4T3M�Ĵ����ĵ�6��7λ����Ϊ1����ʾѡ���ⲿ����ģʽ����������ʱ��4��

�ú�����Ŀ���Ǹ��ݴ���Ĳ���ѡ����ʵĶ�ʱ�������ţ������г�ʼ���������������Ա����ʹ���ⲿ��������*/
//���������������ֱ���ÿ⺯��
//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��������ʼ��
//  @param       tim_n           ѡ��ģ��
//  @return     
//  Sample usage:            
//-------------------------------------------------------------------------------------------------------------------

void encoder_Init(void)
{
   ctimer_count_init(SPEEDL_PLUSE);//��ʱ����ʼ����Ϊ�ⲿ����,��ʼ����ʱ��0���ⲿ����ΪP3.4����
	 ctimer_count_init(SPEEDR_PLUSE);//��ʼ����ʱ��3��Ϊ�ⲿ����

}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      ������������
//  @param      datl           ����
//  @return     uint16      ���ؼ���ֵ
//  Sample usage:           num = ctimer_count_read(CTIM0_P34);     
//-------------------------------------------------------------------------------------------------------------------

int16 Read_encoderL(void)
{
	  int16 datl;
	  if(DIL == 1)
		{
			datl = ctimer_count_read(SPEEDL_PLUSE);
		}
		else
		{
			datl = ctimer_count_read(SPEEDL_PLUSE) * -1;
		}
     return datl; 
}
int16 Read_encoderR(void)
{
	 int16 datr;
	if(DIR == 1)
		{
			datr = ctimer_count_read(SPEEDR_PLUSE );
		}
		else
		{
			datr = ctimer_count_read(SPEEDR_PLUSE ) * -1;
		}
     return datr; 
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      �������������
//  @param      datl           ����
//  @return     uint16      ���ؼ���ֵ
//  Sample usage:           num = ctimer_count_read(CTIM0_P34);     
//-------------------------------------------------------------------------------------------------------------------

void clean_encoder(void)
{
  ctimer_count_clean(SPEEDL_PLUSE);
  ctimer_count_clean(SPEEDR_PLUSE);
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      ʹ�ñ�����
//  @param      datl           ����
//  @return     uint16      ���ؼ���ֵ
//  Sample usage:           num = ctimer_count_read(CTIM0_P34);     
//-------------------------------------------------------------------------------------------------------------------
void Use_encoderL(void)
{
	 templ_pluse=0;
	 tempr_pluse=0;
   encoder_Init();
	 delay_ms(200);//200ms����ʱ�䣬Ҳ��������ȫ��ʼ������Ҫɾ������Ȼ�᲻��ʹ
   templ_pluse = Read_encoderL();
	 tempr_pluse = Read_encoderR();
	 printf("templ_pluse = %d\r\n", templ_pluse);
	 
	 printf("tempr_pluse = %d\r\n", tempr_pluse);
	 
	 clean_encoder();
}


