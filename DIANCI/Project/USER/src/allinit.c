#include "headfile.h"

void all_init()
{
	uart_init();
	// 电机初始化
	pwm_init(PWMA_CH1P_P60, 17000, 0);
	pwm_init(PWMA_CH2P_P62, 17000, 0);
	pwm_init(PWMA_CH3P_P64, 17000, 0);
	pwm_init(PWMA_CH4P_P66, 17000, 0);

	// 舵机初始化
	pwm_init(S3010_CH, 50, 700);

	// ADC 通道初始化
	Use_adc_Init();

	// 陀螺仪初始化
	icm20602_init();

	// oled初始化
	OLED_Init();
	OLED_Init(); // 初始化OLED
	OLED_Clear();
	OLED_DisPlay_On();
	// 蜂鸣器
	BEEP = 0;
	// 编码器
	ctimer_count_init(SPEEDL_PLUSE);
	ctimer_count_init(SPEEDR_PLUSE);
	// 中断定时器
	pit_timer_ms(TIM_1, 5);
	//TOF初始化
	dl1a_init();	

	DMA_config();
}