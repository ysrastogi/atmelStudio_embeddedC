/*! \mainpage Section-1: Getting familiar with software
 *
 * @author     e-Yantra Team
 * @date       2021/06/22
 *
 * \subsection Aim
 * To get started with the Embedded C Programming and rectify the errors in the skeleton code
 * such that the LED connected to Arduino UNO turns ON and OFF at an interval of a second.
 *
 * \subsection Connections
 * LED 				:  PB5 				<br>
 *
 */

//-------------------------------------------- HEADER FILES --------------------------------------------
#include "firebird_simulation.h"		// Header file included that contains macro definitions essential for Arduino UNO and Firebird V robot
#include <util/delay.h>					// Standard AVR Delay Library


//---------------------------------------------- FUNCTIONS ----------------------------------------------
// << TODO >> : Complete all the functions and their input arguments correctly as they might have errors

/**
 * @brief      Makes **ONLY** 'led_pin' as output and initially sets it to low
 */
void led_pin_config()
{
	// << NOTE >> : Use Masking and Shift Operators here
	
	// Make 'led_pin' as output by setting 'led_pin' in 'led_ddr_reg'
	led_ddr_reg |= ( 1 << led_pin );
	
	// Set 'led_pin' to low initially or reset the 'led_pin' in 'led_port_reg'
	led_port_reg &= ~( 1 << led_pin );
}


/**
 * @brief      Toggle status of **ONLY** 'led_pin' from OFF to ON and vice-versa
 */
void led_toggle(void)
{
	// << NOTE >> : Use Masking and Shift Operators here
	
	// Toggle the 'led_pin' status
	led_port_reg ^= ( 1 << led_pin );
}


//------------------------------------------------ MAIN ------------------------------------------------
/**
 * @brief      Main Function
 *
 * @details    First Initializes the LED present on Arduino UNO by calling led_pin_config() function,
 * 			   then calls the led_toggle() function to turn the LED ON and OFF at an interval of a second.
 */
int main(void)
{
	// << NOTE >> : You are not allowed to modify or change anything inside this function

	led_pin_config();			// Initialize the LED
	
    while (1)
    {
		led_toggle();			// Toggle the status of LED
		_delay_ms(1000);
    }
	return 0;
}
//------------------------------------------------ END -------------------------------------------------
