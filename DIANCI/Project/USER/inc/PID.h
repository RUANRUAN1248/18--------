#ifndef _PID_H
#define _PID_H


typedef struct
{
		float       Kp;   //p
    float     	Ki;   //I
	  float       Kd;   //D
	  float       imax; //积分限幅
	  
	  float       out_p; //Kp输出
	  float       out_i; //Ki输出
	  float       out_d; //Kd输出
	  float       out;   //pid输出
	
	  float       integrator;//积分值
	  float       limit;   //积分限幅
	  float       error;    //当前误差
	  float       last_error; //上次误差
	  float       last_last_error;//上上次误差  
	  float       last_derivative;//上次误差与当前误差之差
	
	  
}PIDL_Type_Def;
typedef struct
{
		float       Kp;   //p
    float     	Ki;   //I
	  float       Kd;   //D
	  float       imax; //积分限幅
	  
	  float       out_p; //Kp输出
	  float       out_i; //Ki输出
	  float       out_d; //Kd输出
	  float       out;   //pid输出
	
	  float       integrator;//积分值
	  float       limit;
	  float       error;    //当前误差
	  float       last_error;//上次误差
	  float       last_last_error;//上上次误差
	  float       last_derivative;//上次误差与当前误差之差
	  
}PIDR_Type_Def;


float constrain_float(float amt, float low, float high);
void PIDL_Init(PIDL_Type_Def *PIDL);
void PIDR_Init(PIDR_Type_Def *PIDR);
float PIDL_Loc(float SetValue,float ActualValue,PIDL_Type_Def *PIDL);
float PIDR_Loc(float SetValue,float ActualValue,PIDR_Type_Def *PIDR);
float PIDL_Inc(float SetValue, float ActualValue,PIDL_Type_Def *PIDL);
float PIDR_Inc(float SetValue, float ActualValue, PIDR_Type_Def *PIDR);

#endif














