#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Function to initialize Buzzer
void buzzer_pin_config (void)
{
	DDRC = DDRC | 0x08;		//Setting PORTC 3 as outpt
	PORTC = PORTC & 0xF7;		//Setting PORTC 3 logic low to turnoff buzzer
}

//Function to configure Interrupt switch
void interrupt_switch_config (void)
{
	DDRE = DDRE & 0x7F;  //PORTE 7 pin set as input
	PORTE = PORTE | 0x80; //PORTE7 internal pull-up enabled
}

//Function to configure LDD bargraph display
void LED_bargraph_config (void)
{
	DDRJ = 0xFF;  //PORT J is configured as output
	PORTJ = 0x00; //Output is set to 0
}

//Function to Initialize PORTS
void port_init (void)
{
	buzzer_pin_config();
	interrupt_switch_config();
	LED_bargraph_config();
}

void buzzer_on (void)
{
	unsigned char port_restore = 0;
	port_restore = PINC;
	port_restore = port_restore | 0x08;
	PORTC = port_restore;
}

void buzzer_off (void)
{
	unsigned char port_restore = 0;
	port_restore = PINC;
	port_restore = port_restore & 0xF7;
	PORTC = port_restore;
}

void init_devices (void)
{
	cli(); //Clears the global interrupts
	port_init();
	sei(); //Enables the global interrupts
}



//Main Function
int main(void)
{
	init_devices();
	while(1)
	{
		if((PINE & 0x80) == 0x80) //switch is not pressed
		{
			buzzer_off(); //Turn off buzzer
			PORTJ = 0x00; //Turn off bargraph LEDs
		}
		else
		{
			
			buzzer_on(); //Turn on buzzer
			PORTJ = 0xFF; //Turn on bargraph LEDs
		}
	}
}