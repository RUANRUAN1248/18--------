#include "headfile.h"

/*************************************************************************
 *  函数名称：float constrain_float(float amt, float low, float high)
 *  功能说明：限幅函数
 *  参数说明：
  * @param    amt   ： 参数
  * @param    low   ： 最低值
  * @param    high  ： 最高值
 *  函数返回：无
 *  修改时间：2020年4月1日
 *  备    注：
 *************************************************************************/
float constrain_float(float amt, float low, float high)
{
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}
/************************************************
函数名称：PIDL_Init(PIDL_Type_Def *PIDL)
功    能：初始化PIDL参数
参    数：PIDL_Type_Def *PIDL
返 回 值：无
*************************************************/
void PIDL_Init(PIDL_Type_Def *PIDL)
{
     PIDL->Kp =0;
	   PIDL->Ki =0;
	   PIDL->Kd =0;
	   PIDL->out_p =0; //Kp输出
	   PIDL->out_i =0; //Ki输出
		 PIDL->out_d =0; //Kd输出
		 PIDL->out =0;   //pid输出
		 PIDL->integrator =0; //积分值
	   PIDL->limit =0;//积分限幅
	   PIDL->error =0;      //当前偏差
		 PIDL->last_error =0; //上次误差
		 PIDL->last_derivative =0; //上次误差与上上次误差之差
}
/************************************************
函数名称：PIDR_Init(PIDR_Type_Def *PIDR)
功    能：初始化PIDR参数
参    数：PIDR_Type_Def *PIDL
返 回 值：无
*************************************************/
void PIDR_Init(PIDR_Type_Def *PIDR)
{
     PIDR->Kp =0;
	   PIDR->Ki =0;
	   PIDR->Kd =0;
		 PIDR->out_p =0; //Kp输出
	   PIDR->out_i =0; //Ki输出
		 PIDR->out_d =0; //Kd输出
		 PIDR->out =0;   //pid输出
		 PIDR->integrator =0; //积分值
	   PIDR->limit =0;//积分限幅
	   PIDR->error =0;      //当前偏差
		 PIDR->last_error =0; //上次误差
		 PIDR->last_derivative =0; //上次误差与上上次误差之差
}

//pwm=Kp*e(k)+Ki*∑e(k)+Kd[e（k）-e(k-1)]
/************************************************
函数名称 ： PID_Loc(float SetValue,float ActualValue,PIDL_Type_Def *PIDL)
功    能 ： 位置式PID
参    数 ： SetValue ------ 设置值(期望值)
            ActualValue --- 实际值(反馈值)
            PID ----------- PID数据结构
返 回 值 ： PIDL->out -------- 输出
*************************************************/
float PIDL_Loc(float SetValue,float ActualValue,PIDL_Type_Def *PIDL)
{
	      PIDL->error = SetValue - ActualValue;                                           //现在误差
	      PIDL->integrator += PIDL->error;                                                //误差累积	     
	      PIDL->integrator = PIDL->integrator > PIDL->limit?PIDL->limit:PIDL->integrator; //积分限幅
	      PIDL->last_derivative = PIDL->error - PIDL->last_error;
				PIDL->out_p = PIDL->Kp *  PIDL->error;                                          //Kp输出
	      PIDL->out_i = PIDL->Ki *  PIDL->integrator;                                     //Ki输出
	      PIDL->out_d = PIDL->Kd *  PIDL->last_derivative;                                //Kd输出
	      PIDL->last_error = PIDL->error;                                                 //保存上一次偏差
	      PIDL->out =PIDL->out_p + PIDL->out_i + PIDL->out_d;                             //输出
	//限制
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
	      PIDR->error = SetValue - ActualValue;                                           //现在误差
	      PIDR->integrator += PIDR->error;                                                //误差累积	     
	      PIDR->integrator = PIDR->integrator > PIDR->limit?PIDR->limit:PIDR->integrator; //积分限幅
	      PIDR->last_derivative = PIDR->error - PIDR->last_error;
				PIDR->out_p = PIDR->Kp *  PIDR->error;                                          //Kp输出
	      PIDR->out_i = PIDR->Ki *  PIDR->integrator;                                     //Ki输出
	      PIDR->out_d = PIDR->Kd *  PIDR->last_derivative;                                //Kd输出
	      PIDR->last_error = PIDR->error;                                                 //保存上一次偏差
	      PIDR->out =PIDR->out_p + PIDR->out_i + PIDR->out_d;                             //输出
	//限制
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
//pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
/************************************************
函数名称 ： PID_Inc
功    能 ： 增量式PID
参    数 ： SetValue ------ 设置值(期望值)
            ActualValue --- 实际值(反馈值)
            PID ----------- PID数据结构
返 回 值 ： PIDL->out -------- 本次PID增量(+/-)
*************************************************/
float PIDL_Inc(float SetValue, float ActualValue, PIDL_Type_Def *PIDL)
{
    
 
    PIDL->error = SetValue - ActualValue;                                  //计算当前偏差  
	  PIDL->last_derivative = PIDL->error - PIDL->last_error;
    PIDL->out_p = PIDL->Kp * PIDL->last_derivative;
    PIDL->out_i = PIDL->Ki * PIDL->error;
    PIDL->out_d = PIDL->Kd * (PIDL->error - 2*PIDL->last_error +  PIDL->last_last_error);	
    PIDL->out = PIDL->out_p + PIDL->out_i + PIDL->out_d;                    //增量式PID控制器    
	
    PIDL->last_last_error = PIDL->last_error;
    PIDL->last_error =PIDL->error;

    if(PIDL->out > motor_Max)
    {
      PIDL->out = motor_Max;
    }
    else if(PIDL->out < motor_Min)
    {
      PIDL->out = motor_Min;
    }                                           //限幅

    return PIDL->out;
}

float PIDR_Inc(float SetValue, float ActualValue, PIDR_Type_Def *PIDR)
{
    
 
    PIDR->error = SetValue - ActualValue;                                  //计算当前偏差  
	  PIDR->last_derivative = PIDR->error - PIDR->last_error;
    PIDR->out_p = PIDR->Kp * PIDR->last_derivative;
    PIDR->out_i = PIDR->Ki * PIDR->error;
    PIDR->out_d = PIDR->Kd * (PIDR->error - 2*PIDR->last_error +  PIDR->last_last_error);	
    PIDR->out = PIDR->out_p + PIDR->out_i + PIDR->out_d;                    //增量式PID控制器    
	
    PIDR->last_last_error = PIDR->last_error;
    PIDR->last_error =PIDR->error;

    if(PIDR->out > motor_Max)
    {
      PIDR->out = motor_Max;
    }
    else if(PIDR->out < motor_Min)
    {
      PIDR->out = motor_Min;
    }                                           //限幅

    return PIDR->out;
}













