#include "headfile.h"

/*************************************************************************
 *  �������ƣ�float constrain_float(float amt, float low, float high)
 *  ����˵�����޷�����
 *  ����˵����
  * @param    amt   �� ����
  * @param    low   �� ���ֵ
  * @param    high  �� ���ֵ
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע��
 *************************************************************************/
float constrain_float(float amt, float low, float high)
{
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}
/************************************************
�������ƣ�PIDL_Init(PIDL_Type_Def *PIDL)
��    �ܣ���ʼ��PIDL����
��    ����PIDL_Type_Def *PIDL
�� �� ֵ����
*************************************************/
void PIDL_Init(PIDL_Type_Def *PIDL)
{
     PIDL->Kp =0;
	   PIDL->Ki =0;
	   PIDL->Kd =0;
	   PIDL->out_p =0; //Kp���
	   PIDL->out_i =0; //Ki���
		 PIDL->out_d =0; //Kd���
		 PIDL->out =0;   //pid���
		 PIDL->integrator =0; //����ֵ
	   PIDL->limit =0;//�����޷�
	   PIDL->error =0;      //��ǰƫ��
		 PIDL->last_error =0; //�ϴ����
		 PIDL->last_derivative =0; //�ϴ���������ϴ����֮��
}
/************************************************
�������ƣ�PIDR_Init(PIDR_Type_Def *PIDR)
��    �ܣ���ʼ��PIDR����
��    ����PIDR_Type_Def *PIDL
�� �� ֵ����
*************************************************/
void PIDR_Init(PIDR_Type_Def *PIDR)
{
     PIDR->Kp =0;
	   PIDR->Ki =0;
	   PIDR->Kd =0;
		 PIDR->out_p =0; //Kp���
	   PIDR->out_i =0; //Ki���
		 PIDR->out_d =0; //Kd���
		 PIDR->out =0;   //pid���
		 PIDR->integrator =0; //����ֵ
	   PIDR->limit =0;//�����޷�
	   PIDR->error =0;      //��ǰƫ��
		 PIDR->last_error =0; //�ϴ����
		 PIDR->last_derivative =0; //�ϴ���������ϴ����֮��
}

//pwm=Kp*e(k)+Ki*��e(k)+Kd[e��k��-e(k-1)]
/************************************************
�������� �� PID_Loc(float SetValue,float ActualValue,PIDL_Type_Def *PIDL)
��    �� �� λ��ʽPID
��    �� �� SetValue ------ ����ֵ(����ֵ)
            ActualValue --- ʵ��ֵ(����ֵ)
            PID ----------- PID���ݽṹ
�� �� ֵ �� PIDL->out -------- ���
*************************************************/
float PIDL_Loc(float SetValue,float ActualValue,PIDL_Type_Def *PIDL)
{
	      PIDL->error = SetValue - ActualValue;                                           //�������
	      PIDL->integrator += PIDL->error;                                                //����ۻ�	     
	      PIDL->integrator = PIDL->integrator > PIDL->limit?PIDL->limit:PIDL->integrator; //�����޷�
	      PIDL->last_derivative = PIDL->error - PIDL->last_error;
				PIDL->out_p = PIDL->Kp *  PIDL->error;                                          //Kp���
	      PIDL->out_i = PIDL->Ki *  PIDL->integrator;                                     //Ki���
	      PIDL->out_d = PIDL->Kd *  PIDL->last_derivative;                                //Kd���
	      PIDL->last_error = PIDL->error;                                                 //������һ��ƫ��
	      PIDL->out =PIDL->out_p + PIDL->out_i + PIDL->out_d;                             //���
	//����
	      if(PIDL->out > Servo_max)
    {
      PIDL->out =  Servo_max;
    }
    else if(PIDL->out< Servo_min)
    {
      PIDL->out =  Servo_min;
    }
	     return PIDL->out ; 
	
	
}
float PIDR_Loc(float SetValue,float ActualValue,PIDR_Type_Def *PIDR)
{
	      PIDR->error = SetValue - ActualValue;                                           //�������
	      PIDR->integrator += PIDR->error;                                                //����ۻ�	     
	      PIDR->integrator = PIDR->integrator > PIDR->limit?PIDR->limit:PIDR->integrator; //�����޷�
	      PIDR->last_derivative = PIDR->error - PIDR->last_error;
				PIDR->out_p = PIDR->Kp *  PIDR->error;                                          //Kp���
	      PIDR->out_i = PIDR->Ki *  PIDR->integrator;                                     //Ki���
	      PIDR->out_d = PIDR->Kd *  PIDR->last_derivative;                                //Kd���
	      PIDR->last_error = PIDR->error;                                                 //������һ��ƫ��
	      PIDR->out =PIDR->out_p + PIDR->out_i + PIDR->out_d;                             //���
	//����
	      if(PIDR->out > Servo_max)
    {
      PIDR->out =  Servo_max;
    }
    else if(PIDR->out < Servo_min)
    {
      PIDR->out =  Servo_min;
    }
	     return PIDR->out ; 
	
	
}
//pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
/************************************************
�������� �� PID_Inc
��    �� �� ����ʽPID
��    �� �� SetValue ------ ����ֵ(����ֵ)
            ActualValue --- ʵ��ֵ(����ֵ)
            PID ----------- PID���ݽṹ
�� �� ֵ �� PIDL->out -------- ����PID����(+/-)
*************************************************/
float PIDL_Inc(float SetValue, float ActualValue, PIDL_Type_Def *PIDL)
{
    
 
    PIDL->error = SetValue - ActualValue;                                  //���㵱ǰƫ��  
	  PIDL->last_derivative = PIDL->error - PIDL->last_error;
    PIDL->out_p = PIDL->Kp * PIDL->last_derivative;
    PIDL->out_i = PIDL->Ki * PIDL->error;
    PIDL->out_d = PIDL->Kd * (PIDL->error - 2*PIDL->last_error +  PIDL->last_last_error);	
    PIDL->out = PIDL->out_p + PIDL->out_i + PIDL->out_d;                    //����ʽPID������    
	
    PIDL->last_last_error = PIDL->last_error;
    PIDL->last_error =PIDL->error;

    if(PIDL->out > motor_Max)
    {
      PIDL->out = motor_Max;
    }
    else if(PIDL->out < motor_Min)
    {
      PIDL->out = motor_Min;
    }                                           //�޷�

    return PIDL->out;
}

float PIDR_Inc(float SetValue, float ActualValue, PIDR_Type_Def *PIDR)
{
    
 
    PIDR->error = SetValue - ActualValue;                                  //���㵱ǰƫ��  
	  PIDR->last_derivative = PIDR->error - PIDR->last_error;
    PIDR->out_p = PIDR->Kp * PIDR->last_derivative;
    PIDR->out_i = PIDR->Ki * PIDR->error;
    PIDR->out_d = PIDR->Kd * (PIDR->error - 2*PIDR->last_error +  PIDR->last_last_error);	
    PIDR->out = PIDR->out_p + PIDR->out_i + PIDR->out_d;                    //����ʽPID������    
	
    PIDR->last_last_error = PIDR->last_error;
    PIDR->last_error =PIDR->error;

    if(PIDR->out > motor_Max)
    {
      PIDR->out = motor_Max;
    }
    else if(PIDR->out < motor_Min)
    {
      PIDR->out = motor_Min;
    }                                           //�޷�

    return PIDR->out;
}













