#ifndef _PID_H
#define _PID_H


typedef struct
{
		float       Kp;   //p
    float     	Ki;   //I
	  float       Kd;   //D
	  float       imax; //�����޷�
	  
	  float       out_p; //Kp���
	  float       out_i; //Ki���
	  float       out_d; //Kd���
	  float       out;   //pid���
	
	  float       integrator;//����ֵ
	  float       limit;   //�����޷�
	  float       error;    //��ǰ���
	  float       last_error; //�ϴ����
	  float       last_last_error;//���ϴ����  
	  float       last_derivative;//�ϴ�����뵱ǰ���֮��
	
	  
}PIDL_Type_Def;
typedef struct
{
		float       Kp;   //p
    float     	Ki;   //I
	  float       Kd;   //D
	  float       imax; //�����޷�
	  
	  float       out_p; //Kp���
	  float       out_i; //Ki���
	  float       out_d; //Kd���
	  float       out;   //pid���
	
	  float       integrator;//����ֵ
	  float       limit;
	  float       error;    //��ǰ���
	  float       last_error;//�ϴ����
	  float       last_last_error;//���ϴ����
	  float       last_derivative;//�ϴ�����뵱ǰ���֮��
	  
}PIDR_Type_Def;


float constrain_float(float amt, float low, float high);
void PIDL_Init(PIDL_Type_Def *PIDL);
void PIDR_Init(PIDR_Type_Def *PIDR);
float PIDL_Loc(float SetValue,float ActualValue,PIDL_Type_Def *PIDL);
float PIDR_Loc(float SetValue,float ActualValue,PIDR_Type_Def *PIDR);
float PIDL_Inc(float SetValue, float ActualValue,PIDL_Type_Def *PIDL);
float PIDR_Inc(float SetValue, float ActualValue, PIDR_Type_Def *PIDR);

#endif














