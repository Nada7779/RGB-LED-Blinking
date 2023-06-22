/**
 ** @file                   gptimer_manager.c
 ** @brief                  This is source file for gptimer 
 ** @author                 Nada Abdelazim
 ** @date                   June 21, 2023
 ** @version                0.1
 */
 
#include "gptimer_manager.h"


/*---------------------------------------------------------/
/- APIs declerations -----------------------------------/
/---------------------------------------------------------*/

/**
 *  @brief 			   This function initializes TIMER 0 according to user's cnfigurations.
 *  @param[in]		 none.
 *  @return        ::SUCCESS in case of success, otherwise, review error code
 */
uint8_t timer0_init(void)
{
	uint8_t uint8_tstatus=SUCCESS;
	
	Timer_cfg_st TIMER_0;
	
	TIMER_0.timer_mode=  TIMER0_MODE;
	TIMER_0.timer_num=   TIMER0_NUM;
	TIMER_0.timer_res=   TIMER0_RES;
	TIMER_0.timer_use=   TIMER0_USE;
	TIMER_0.timer_type=  TIMER0_TYPE;
	TIMER_0.count_dir=   TIMER0_DIR;
	TIMER_0.detect_change=  TIMER0_DETECT_CHANGE;
	TIMER_0.enable_timer_type=  TIMER0_ENABLE_TIMER_TYPE;
	TIMER_0.timer_value=        TIMER0_VALUE;
	TIMER_0.timer_prescaler=    TIMER0_PRESCALER;
	
	uint8_tstatus= timer_init(&TIMER_0);
	
	return uint8_tstatus;
  
}

/**
 *  @brief 			   This function to delay in ms using TIMER 0 in one_shot mode.
 *  @param[in]		 uint16_t milli_sec of the time desired to be delayed.
 *  @return        ::SUCCESS in case of success, otherwise, review error code
 */
uint16_t timer0_delay_ms (uint16_t a_u16_milli_sec)
{
		uint8_t uint8_tstatus=SUCCESS;
  
   if (TIMER0_MODE==ONESHOT_MODE) 
	 {
	 Timer_cfg_st TIMER_0;
	 TIMER_0.timer_type=  TIMER0_TYPE;
	 TIMER_0.timer_num=   TIMER0_NUM;
	
	 // disable timer
	 timer_stop(&TIMER_0);
		 
	// Set the delay time in milliseconds
   uint16_t delay_ticks = (a_u16_milli_sec * SYSTEM_CLOCK) / TIMER0_PRESCALER;
	
	// Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).
 	GPTMTAILR_TIMER0 = delay_ticks;
	
	// enable timer
	timer_start (&TIMER_0);
	
	//Poll the GPTMRIS register 
	while (READ_BIT(GPTMRIS_TIMER0,0) == TATORIS) ;
	
	// diable timer
	 timer_stop(&TIMER_0);
	 }
	  
		else  uint8_tstatus=ERROR;
		 
		return uint8_tstatus;
}

/**
 *  @brief 			   This function to generate pwm in specific pin.
 *  @param[in]		 port and pin number to generate pwm on it and the desired duty cycle in percenatge.
 *  @return        ::SUCCESS in case of success, otherwise, review error code
 */

uint8_t timer0_pwm (uint16_t a_u16_duty_cycle,uint8_t a_u8_pin_num, uint8_t a_u8_port_num)
{
	
	uint8_t uint8_tstatus=SUCCESS;

	pin_write (HIGH,a_u8_port_num,a_u8_pin_num);
	
	
	uint16_t delay_high;
	
	delay_high= ((SIGNAL_DURATION * a_u16_duty_cycle)/PERCENTAGE);
  
	
	uint8_tstatus = timer0_delay_ms(delay_high);
	
	pin_write (LOW,a_u8_port_num,a_u8_pin_num);
	
	timer0_delay_ms(SIGNAL_DURATION-delay_high);
	
	return uint8_tstatus;

}


