/**
 ** @file                   WDT_Tester.c
 ** @brief                  This file implements watchdog timer Module tester
 ** @author                 Mohamed Sayed
 ** @date                   Jan 23, 2023
 ** @version                0.1
 */

/*- INCLUDES
----------------------------------------------*/
#include "app.h"


/*-------------------------------*/
/*- APIs IMPLEMENTATION
-----------------------------------*/


int main (void)
	{
		APP_init();
		while (1)
		{
			APP_start();
		}
	}


