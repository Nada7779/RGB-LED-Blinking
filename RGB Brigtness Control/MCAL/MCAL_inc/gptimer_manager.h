/**
 ** @file                   gptimer_manager.h
 ** @brief                  This is header file for gptimer_manager 
 ** @author                 Nada Abdelazim
 ** @date                   June 21, 2023
 ** @version                0.1
 */

#ifndef GPTIMER_MANAGER_H_
#define GPTIMER_MANAGER_H_

#include "gptimer_manager_config.h"
#include "gptimer.h"
#include "gpio.h"


#define PERCENTAGE                100

/*---------------------------------------------------------/
/- APIs definitions -----------------------------------/
/---------------------------------------------------------*/
/**
 *  @brief 			   This function initializes TIMER 0 according to user's cnfigurations.
 *  @param[in]		 none.
 *  @return        ::SUCCESS in case of success, otherwise, review error code
 */
uint8_t timer0_init ( void) ;
/**
 *  @brief 			   This function to delay in ms using TIMER 0 in one_shot mode.
 *  @param[in]		 uint16_t milli_sec of the time desired to be delayed.
 *  @return        ::SUCCESS in case of success, otherwise, review error code
 */
uint16_t timer0_delay_ms (uint16_t a_u16_milli_sec);
/**
 *  @brief 			   This function to generate pwm in specific pin.
 *  @param[in]		 port and pin number to generate pwm on it and the desired duty cycle in percenatge.
 *  @return        ::SUCCESS in case of success, otherwise, review error code
 */

uint8_t timer0_pwm (uint16_t a_u16_duty_cycle,uint8_t a_u8_pin_num, uint8_t a_u8_port_num);

#endif 