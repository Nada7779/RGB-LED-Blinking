/**
 ** @file                   app.c
 ** @brief                  This is source file for app for TM4C123GH6PM
 ** @author                 Nada Abdelazim
 ** @date                   June 21, 2023
 ** @version                0.1
 */
#include "app.h"
#include "led.h"
#include "button.h"
#include "gptimer_manager.h"

#define  INIT_STATE   0
#define FIRST_STATE   1
#define SECOND_STATE  2
#define THIRD_STATE   3
#define FOURTH_STATE  4




#define FIRST_DUTY_CYCLE    30
#define SECOND_DUTY_CYCLE   60
#define THIRD_DUTY_CYCLE    90



uint8_t buttonstate;
		
uint8_t sequence;

void APP_init(void)
{
	 buttonstate=released;	
	 sequence=FIRST_STATE;

	// TIMER0 INIT
	timer0_init () ;
	// LEDs init
	led_init(GREEN_LED_PORT,GREEN_LED_PIN);
	// button init
	button_init(SW1_PORT,SW1_PIN);
	// Initially, all LEDs are OFF
	led_off(GREEN_LED_PORT,GREEN_LED_PIN);	
}
void APP_start(void)
	{
		
		button_read(SW1_PORT,SW1_PIN,&buttonstate);
			
		if (buttonstate==pressed)
		{
			if (sequence>FOURTH_STATE)
			{
				sequence=INIT_STATE;
			}
			sequence++;
		}
				
				if ( sequence == FIRST_STATE)
				{
					        timer0_pwm(FIRST_DUTY_CYCLE,GREEN_LED_PIN,GREEN_LED_PORT);
				          sequence=SECOND_STATE;

				}
				
				else if ( sequence == SECOND_STATE)
				{
							      timer0_pwm(SECOND_DUTY_CYCLE,GREEN_LED_PIN,GREEN_LED_PORT);
				            sequence=THIRD_STATE;
					
				}
			else if ( sequence == THIRD_STATE)
				{
	                       timer0_pwm(THIRD_DUTY_CYCLE,GREEN_LED_PIN,GREEN_LED_PORT);
				                  sequence=FOURTH_STATE;
					
				}
			else if ( sequence == FOURTH_STATE)
				{
                          led_off(GREEN_LED_PORT,GREEN_LED_PIN);
				                  sequence=FIRST_STATE;
				}



			else
				{					              
				              
			  }
		}
		






	
	


