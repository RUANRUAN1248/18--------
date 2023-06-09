#ifndef _ENCODER_H
#define _ENCODER_H

extern int16 templ_pluse;
extern int16 tempr_pluse ;
#define SPEEDR_PLUSE   CTIM0_P34
#define SPEEDL_PLUSE   CTIM3_P04
#define DIR P35
#define DIL P53



void encoder_Init(void);
int16 Read_encoderL(void);
int16 Read_encoderR(void);
void clean_encoderL(void);
void Use_encoderL(void);

#endif


