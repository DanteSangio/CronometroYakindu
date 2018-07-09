/*
===============================================================================
 Name        : prueba.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

#define PUERTO(n)	n
#define PIN(n)		n

#define INPUT	((bool) 0)
#define OUTPUT	((bool) 1)

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

void Config_uC(void)
{
	Chip_GPIO_SetPinDIR(LPC_GPIO, PUERTO(0), PIN(23), OUTPUT);	//Puerto 0, pin 23 -> Salida
	Chip_GPIO_SetPinDIR(LPC_GPIO, PUERTO(0), PIN(22), OUTPUT);	//Puerto 0, pin 22 -> Salida
	Chip_GPIO_SetPinDIR(LPC_GPIO, PUERTO(0), PIN(21), INPUT);	//Puerto 0, pin 21 -> Entrada
	Chip_GPIO_SetPinDIR(LPC_GPIO, PUERTO(0), PIN(20), INPUT);	//Puerto 0, pin 20 -> Entrada

	Chip_IOCON_PinMux(LPC_IOCON, PUERTO(0), PIN(21), IOCON_MODE_PULLUP, IOCON_FUNC0);
	Chip_IOCON_PinMux(LPC_IOCON, PUERTO(0), PIN(20), IOCON_MODE_PULLDOWN, IOCON_FUNC0);

	Chip_IOCON_EnableOD(LPC_IOCON, PUERTO(0), PIN(23));		//Habilitamos Open Drain

}

int main(void)
{

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0;
    int j = 0;


    Config_uC;

    // Enter an infinite loop, just incrementing a counter
    while(1)
    {
        i++;
        j++;
    }
    return 0 ;
}
