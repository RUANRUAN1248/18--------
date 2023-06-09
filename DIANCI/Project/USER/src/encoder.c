#include "headfile.h"


int16 templ_pluse = 0;
int16 tempr_pluse = 0;
/*对于 CTIM0_P34，选择定时器0和引脚P3.4，并设置定时器0的TL0和TH0寄存器为0，将TMOD寄存器的第2位设置为1，表示选择外部计数模式，最后启动定时器0。

对于 CTIM1_P35，选择定时器1和引脚P3.5，并设置定时器1的TL1和TH1寄存器为0，将TMOD寄存器的第6位设置为1，表示选择外部计数模式，最后启动定时器1。

对于 CTIM2_P12，选择定时器2和引脚P1.2，并设置定时器2的T2L和T2H寄存器为0，将AUXR寄存器的第3、4位设置为1，表示选择外部计数模式，并启动定时器2。

对于 CTIM3_P04，选择定时器3和引脚P0.4，并设置定时器3的T3L和T3H寄存器为0，将T4T3M寄存器的第2、3位设置为1，表示选择外部计数模式，并启动定时器3。

对于 CTIM4_P06，选择定时器4和引脚P0.6，并设置定时器4的T4L和T4H寄存器为0，将T4T3M寄存器的第6、7位设置为1，表示选择外部计数模式，并启动定时器4。

该函数的目的是根据传入的参数选择合适的定时器和引脚，并进行初始化和启动操作，以便后续使用外部计数功能*/
//带方向编码器可以直接用库函数
//-------------------------------------------------------------------------------------------------------------------
//  @brief      编码器初始化
//  @param       tim_n           选择模块
//  @return     
//  Sample usage:            
//-------------------------------------------------------------------------------------------------------------------

void encoder_Init(void)
{
   ctimer_count_init(SPEEDL_PLUSE);//定时器初始化作为外部计数,初始化定时器0，外部输入为P3.4引脚
	 ctimer_count_init(SPEEDR_PLUSE);//初始化定时器3作为外部计数

}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      编码器读数据
//  @param      datl           数据
//  @return     uint16      返回计数值
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
//  @brief      编码器清除数据
//  @param      datl           数据
//  @return     uint16      返回计数值
//  Sample usage:           num = ctimer_count_read(CTIM0_P34);     
//-------------------------------------------------------------------------------------------------------------------

void clean_encoder(void)
{
  ctimer_count_clean(SPEEDL_PLUSE);
  ctimer_count_clean(SPEEDR_PLUSE);
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      使用编码器
//  @param      datl           数据
//  @return     uint16      返回计数值
//  Sample usage:           num = ctimer_count_read(CTIM0_P34);     
//-------------------------------------------------------------------------------------------------------------------
void Use_encoderL(void)
{
	 templ_pluse=0;
	 tempr_pluse=0;
   encoder_Init();
	 delay_ms(200);//200ms计数时间，也是让其完全初始化，不要删除，不然会不好使
   templ_pluse = Read_encoderL();
	 tempr_pluse = Read_encoderR();
	 printf("templ_pluse = %d\r\n", templ_pluse);
	 
	 printf("tempr_pluse = %d\r\n", tempr_pluse);
	 
	 clean_encoder();
}



