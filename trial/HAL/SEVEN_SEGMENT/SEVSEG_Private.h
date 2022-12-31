/*
 * SEVSEG_Private.h
 *
 * Created: 9/24/2022 2:25:08 AM
 *  Author: User
 */ 


#ifndef SEVSEG_PRIVATE_H_
#define SEVSEG_PRIVATE_H_

#include "SEVSEG_Configuration.h"

void SEG_Initialzation(void);
void SEG_ENABLE1(void);
void SEG_ENABLE2(void);
void SEG_DISABLE1(void);
void SEG_DISABLE2(void);
void SEG_ENABLE_DIB(void);
void SEG_DISABLE_DIB(void);

void SEG_DISPALY(uint16_t num);



#endif /* SEVSEG_PRIVATE_H_ */