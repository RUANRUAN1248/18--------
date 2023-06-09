#include "headfile.h"



/*************************************************************************
 *  �������ƣ�void motor_init(void)
 *  ����˵�������PWM��ʼ��
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2023.4.24
 *  ��    ע������1�����
 *************************************************************************/
void motor_init(void)
{
		pwm_init(PWMA_CH1P_P10,15000,0);//P1 ���PWMƵ��17000HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100
		pwm_init(PWMB_CH2_P21,15000,0);//P2 ���PWMƵ��17000HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100
		pwm_init(PWMB_CH1_P20,15000,0);//P3 ���PWMƵ��17000HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100
		pwm_init(PWMB_CH4_P23,15000,0);//P4 ���PWMƵ��17000HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100
}
void qian(void)           //P1-pwm  P2-0 P3-pwm P4-0ʱǰת
{
    pwm_duty(PWMA_CH1P_P10,5000);   //ռ�ձ�10%
	  pwm_duty(PWMB_CH2_P21,0);    //ռ�ձ�0%
	  pwm_duty(PWMB_CH1_P20,5000);    //ռ�ձ�10%
		pwm_duty(PWMB_CH4_P23,0);     //ռ�ձ�0%
}	
void hou(void)           //P1-0  P2-pwm P3-0 P4-pwmʱ��ת
{
    pwm_duty(PWMA_CH3P_P14,0);   //ռ�ձ�0%
	  pwm_duty(PWMA_CH4P_P16,50);    //ռ�ձ�10%
	  pwm_duty(PWMB_CH1_P20,0);    //ռ�ձ�0%
		pwm_duty(PWMB_CH4_P23,50);     //ռ�ձ�10%
}
void ting(void)         //P1=P2 P3=P4����P1.P2.P3.P4����ʱǰת
{
    pwm_duty(PWMA_CH3P_P14,0);   //ռ�ձ�0%
	  pwm_duty(PWMA_CH4P_P16,0);    //ռ�ձ�0%
	  pwm_duty(PWMB_CH1_P20,0);    //ռ�ձ�0%
		pwm_duty(PWMB_CH4_P23,0);     //ռ�ձ�0%
}




