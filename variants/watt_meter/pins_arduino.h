/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  ***********************************************************************
  Modified to work with WB0WUQ Watt Meter, SSPA Control, Auto Tuner 100w and Auto Tuner 2K
  ***********************************************************************
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#ifndef PCICR
#define PCICE EICR
#endif
#ifndef PCMSK
#define PCMSK EIMSK
#endif

#define NUM_DIGITAL_PINS            50
#define NUM_ANALOG_INPUTS           8

#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 40 : -1)

/* not gonna bother with PWM */
#define digitalPinHasPWM(p)         (0)

static const uint8_t SS   = 8;
static const uint8_t MOSI = 10;
static const uint8_t MISO = 11;
static const uint8_t SCK  = 9;

static const uint8_t SDA = 6;
static const uint8_t SCL = 5;
static const uint8_t LED_BUILTIN = 48;
static const uint8_t BLUE = 43;
static const uint8_t GOLD = 42;

static const uint8_t A0 = 37;
static const uint8_t A1 = 38;
static const uint8_t A2 = 39;
static const uint8_t A3 = 40;
static const uint8_t A4 = 41;
static const uint8_t A5 = 42;
static const uint8_t A6 = 43;
static const uint8_t A7 = 44;

//PC interrupts are not available on the AT90CAN128
#define digitalPinToPCICR(p)    ((uint8_t *)0)
#define digitalPinToPCICRbit(p) (1)
#define digitalPinToPCMSK(p)    ((uint8_t *)0)
#define digitalPinToPCMSKbit(p) (p)

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
	(uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
	(uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PE	, // PE 0 ** 0 ** USART0_RX	
	PE	, // PE 1 ** 1 ** USART0_TX

	PB	, // PB 5 ** 2 ** PWM2	I/O 1
	PB	, // PB 6 ** 3 ** PWM3	I/O 2
	PB	, // PB 7 ** 4 ** PWM4  I/O 3
	PD	, // PD 0 ** 5 ** SCL AT90CAN Pin #25
	PD	, // PD 1 ** 6 ** SDA AT90CAN Pin #26
	PD	, // PD 2 ** 7 ** PWM7	I/O 6
       	PD	, // PD 3 ** 8 ** D8    I/O 7
	PD	, // PD 7 ** 9 ** D9    1/O 8

	PC	, // PC 0 ** 10 ** D10  I/O 9
	PC	, // PC 1 ** 11 ** D11  1/O 10
	PC	, // PC 2 ** 12 ** D12	1/0 11
	PC	, // PC 3 ** 13 **      I/O 12
	PC	, // PC 4 ** 14 **      1/O 13

	PD	, // PD 6 ** 15 ** RXCAN	
	PD	, // PD 5 ** 16 ** TXCAN

	PC	, // PC 5 ** 17 **      I/O 14
	PC	, // PC 6 ** 18 ** USART1_RX I/O 15
	PC	, // PC 7 ** 19 ** USART1_TX I/O 16

	PB	, // PB 3 ** 20 ** SDA  Factory Default Reset Pin
	PB	, // PD 0 ** 21 ** SCL

	PA	, // PA 7 ** 22 ** I/O 17
	PA	, // PA 6 ** 23 ** I/O 18
	PA	, // PA 5 ** 24 ** I/O 19
	PA	, // PA 4 ** 25 ** I/O 20
	PA	, // PA 3 ** 26 ** I/O 21
	PA	, // PA 2 ** 27 ** I/O 22
	PA	, // PA 1 ** 28 ** I/O 23
	PA	, // PA 0 ** 29 ** I/O 24

	PF	, // PF 7 ** 30 ** ADC0   AT90CAN Pin #54
	PF	, // PF 6 ** 30 ** ADC1   AT90CAN Pin #55
	PF	, // PF 5 ** 30 ** ADC2   AT90CAN Pin #56
	PF	, // PF 4 ** 30 ** ADC3   AT90CAN Pin #57
	PF	, // PF 3 ** 30 ** ADC4   AT90CAN Pin #58
	PF	, // PF 2 ** 30 ** ADC5   AT90CAN Pin #59
	PF	, // PF 1 ** 30 ** ADC6   AT90CAN Pin #60
	PF	, // PF 0 ** 30 ** ADC7   AT90CAN Pin #61

	PB	, // PF 7 ** 38 ** NONE!
	PB	, // PF 6 ** 39 ** NONE!
	PB	, // PF 5 ** 40 ** NONE!
	PB	, // PF 4 ** 41 ** NONE!

	PG	, // PG 0 ** 42 ** GOLD
	PG	, // PG 1 ** 43 ** BLUE

	PB	, // PF 3 ** 44 ** NONE!
	PB	, // PF 2 ** 45 ** NONE!
      	PB	, // PF 1 ** 46 ** NONE!
	PB	, // PF 0 ** 47 ** NONE!

	PB	, // PB 0 ** 48 ** NONE!
	PB	, // PB 0 ** 49 ** NONE!


	PB	, // PB 0 ** 50 ** SPI_MISO
	PB	, // PB 0 ** 51 ** SPI_MOSI
	PB	, // PB 0 ** 52 ** SPI_SCK
	PB	, // PB 0 ** 53 ** SPI_SS (also BLUE)

      };

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX	
	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX

	_BV( 5 )	, // PB 5 ** 2 ** PWM2 I/O 1   01/02
	_BV( 6 )	, // PB 6 ** 3 ** PWM3 I/O 2   03/04
	_BV( 7 )	, // PB 7 ** 4 ** PWM4 I/O 3   05/06
	_BV( 0 )	, // PD 0 ** 5 ** SCL (TWI, I2C) AT90CAN128 Pin #25
	_BV( 1 )	, // PD 1 ** 6 ** SDA (TWI, I2C) AT90CAN128 Pin #26
	_BV( 2 )	, // PD 2 ** 7 ** PWM7 I/O 6   0B/0C
	_BV( 3 )	, // PD 3 ** 8 ** D8   I/O 7   0D/0E
	_BV( 7 )	, // PD 7 ** 9 ** D9   I/O 8   0F/10

	_BV( 0 )	, // PC 0 ** 10 ** D10 I/O 9   11/12
	_BV( 1 )	, // PC 1 ** 11 ** D11 I/O 10  13/14
	_BV( 2 )	, // PC 2 ** 12 ** D12 I/O 11  15/16
	_BV( 3 )	, // PC 3 ** 13 **     I/O 12  17/18
	_BV( 4 )	, // PC 4 ** 14 **     I/O 13  19/1A

	_BV( 6 )	, // PD 6 ** 15 ** RXCAN	
	_BV( 5 )	, // PD 5 ** 16 ** TXCAN

	_BV( 5 )	, // PC 5 ** 17 ** I/O 14   1B/1C
	_BV( 6 )	, // PC 6 ** 18 ** I/O 15   1D/1E
	_BV( 7 )	, // PC 7 ** 19 ** I/O 16   1F/20

	_BV( 3 )	, // PD 1 ** 20 ** SDA  Factory Default Reset Pin
	_BV( 0 )	, // PD 0 ** 21 ** SCL

	_BV( 7 )	, // PA 7 ** 22 ** I/O 17   21/22
	_BV( 6 )	, // PA 6 ** 23 ** I/O 18   23/24
	_BV( 5 )	, // PA 5 ** 24 ** I/O 19   25/26
	_BV( 4 )	, // PA 4 ** 25 ** I/O 20   27/28
	_BV( 3 )	, // PA 3 ** 26 ** I/O 21   29/2A
	_BV( 2 )	, // PA 2 ** 27 ** I/O 22   2B/2C
	_BV( 1 )	, // PA 1 ** 28 ** I/O 23   2D/2E
	_BV( 0 )	, // PA 0 ** 29 ** I/O 24   2F/30

	_BV( 7 )	, // PF 7 ** 30 ** ADC0   AT90CAN Pin #54
	_BV( 6 )	, // PF 6 ** 31 ** ADC1   AT90CAN Pin #55
	_BV( 5 )	, // PF 5 ** 32 ** ADC2   AT90CAN Pin #56
	_BV( 4 )	, // PF 4 ** 33 ** ADC3   AT90CAN Pin #57
	_BV( 3 )	, // PF 3 ** 34 ** ADC4   AT90CAN Pin #58
	_BV( 2 )	, // PF 2 ** 35 ** ADC5   AT90CAN Pin #59
	_BV( 1 )	, // PF 1 ** 36 ** ADC6   AT90CAN Pin #60
      	_BV( 0 )	, // PF 0 ** 37 ** ADC7   AT90CAN Pin #61

	_BV( 0 )	, // PF 7 ** 38 ** NONE!  I/O 33
	_BV( 0 )	, // PF 6 ** 39 ** NONE!  I/O 34
	_BV( 0 )	, // PF 5 ** 40 ** NONE!  I/O 35
	_BV( 0 )	, // PF 4 ** 41 ** NONE!  I/O 36

	_BV( 0 )	, // PG 0 ** 42 ** NONE!
	_BV( 1 )	, // PG 1 ** 43 ** NONE!

	_BV( 0 )	, // PF 3 ** 44 ** NONE!
	_BV( 0 )	, // PF 3 ** 45 ** NONE!
      	_BV( 0 )	, // PF 1 ** 46 ** NONE!
	_BV( 0 )	, // PB 0 ** 47 ** NONE!

	_BV( 0 )	, // PB 0 ** 48 ** NONE!
	_BV( 0 )	, // PB 0 ** 49 ** NONE!

	_BV( 0 )	, // PB 3 ** 50 ** SPI_MISO
	_BV( 0 )	, // PB 2 ** 51 ** SPI_MOSI
	_BV( 0 )	, // PB 1 ** 52 ** SPI_SCK
	_BV( 0 )	, // PB 0 ** 53 ** SPI_SS


};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
	NOT_ON_TIMER	, // PE 0 ** 0 ** USART0_RX	
	NOT_ON_TIMER	, // PE 1 ** 1 ** USART0_TX
	TIMER3A	      , // PE 3 ** 2 ** PWM2	
	TIMER3B     	, // PE 4 ** 3 ** PWM3	
	TIMER3C     	, // PE 5 ** 4 ** PWM4	
	TIMER2A     	, // PB 4 ** 5 ** PWM5	
	TIMER1A     	, // PB 5 ** 6 ** PWM6	
	TIMER1B     	, // PB 6 ** 7 ** PWM7	

	NOT_ON_TIMER	, // PE 2 ** 8 ** D8	
	NOT_ON_TIMER	, // PE 6 ** 9 ** D9	
	NOT_ON_TIMER	, // PE 7 ** 10 ** D10	
	NOT_ON_TIMER	, // PD 4 ** 11 ** D11	
	NOT_ON_TIMER	, // PD 7 ** 12 ** D12	
	NOT_ON_TIMER	, // PB 0 ** 13 ** BLUE	
	TIMER0A     	, // PB 7 ** 14 ** GOLD

	NOT_ON_TIMER	, // PD 6 ** 15 ** RXCAN	
	NOT_ON_TIMER	, // PD 5 ** 16 ** TXCAN	

	NOT_ON_TIMER	, // PB 0 ** 17 ** NONE!	

	NOT_ON_TIMER	, // PD 3 ** 18 ** USART1_RX	
	NOT_ON_TIMER	, // PD 2 ** 19 ** USART1_TX	
	NOT_ON_TIMER	, // PD 1 ** 20 ** SDA	
	NOT_ON_TIMER	, // PD 0 ** 21 ** SCL	

	NOT_ON_TIMER	, // PB 0 ** 22 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 23 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 24 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 25 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 26 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 27 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 28 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 29 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 30 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 31 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 32 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 33 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 34 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 35 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 36 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 37 ** NONE!
	NOT_ON_TIMER	, // PB 0 ** 38 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 39 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 40 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 41 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 42 ** NONE!
	NOT_ON_TIMER	, // PB 0 ** 43 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 44 ** NONE!
	NOT_ON_TIMER	, // PB 0 ** 45 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 46 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 47 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 48 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 49 ** NONE!	

	NOT_ON_TIMER	, // PB 3 ** 50 ** SPI_MISO	
	NOT_ON_TIMER	, // PB 2 ** 51 ** SPI_MOSI	
	NOT_ON_TIMER	, // PB 1 ** 52 ** SPI_SCK	
	NOT_ON_TIMER	, // PB 0 ** 53 ** SPI_SS (also BLUE)

};

#endif

#endif
