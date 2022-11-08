/*
 * firebird_simulation.h
 *
 * Created: 2/15/2020 17:14:54
 * Author: e-Yantra Team
 */ 


#ifndef FIREBIRD_SIMULATION_H_
#define FIREBIRD_SIMULATION_H_


#include <avr/io.h>									// Standard AVR IO Library


// Definitions for ATmega328P micro-controller for circuit in SimulIDE
#if defined(__AVR_ATmega328P__)

#define F_CPU						16000000

#define led_ddr_reg					DDRB
#define led_port_reg				PORTB
#define led_pin						5			// PB5	( IO13 or D13 )

#endif


// Definitions for ATmega2560 micro-controller on Firebird V robot
#if defined(__AVR_ATmega2560__)

#define F_CPU						14745600

#define led_ddr_reg					DDRJ
#define led_port_reg				PORTJ
#define led_pin						5			// PJ5

#endif


#endif /* FIREBIRD_SIMULATION_H_ */