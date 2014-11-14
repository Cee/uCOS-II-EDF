/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*                                          Board Support Package
*
*                                 (c) Copyright 2010; Micrium; Weston, FL
*                                           All Rights Reserved
*
* Filename      : bsp.c
* Programmer(s) : FGK
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <cpu_core.h>
#include  <bsp.h>


/*$PAGE*/
/*
*********************************************************************************************************
*                                          LOCAL PROTOTYPES
*********************************************************************************************************
*/

static  void  LED_Init(void);


/*$PAGE*/
/*
*********************************************************************************************************
*                                         BSP INITIALIZATION
*
* Description : This function should be called by the application code before using any functions in
*               this module.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_Init (void)
{
    LED_Init();
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                         LED INITIALIZATION
*
* Description : This function is used to initialize the LEDs on the board.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  LED_Init (void)
{
    LED_Off(0);
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                               LED ON
*
* Description : This function is used to control any or all the LEDs on the board.
*
* Argument(s) : led         is the number of the LED to control.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  LED_On (CPU_INT08U  led)
{
   (void)&led;                                                  /* Prevent 'variable unused' compiler warning.          */
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                               LED OFF
*
* Description : This function is used to control any or all the LEDs on the board.
*
* Argument(s) : led         is the number of the LED to control.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  LED_Off (CPU_INT08U  led)
{
   (void)&led;                                                  /* Prevent 'variable unused' compiler warning.          */
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                             LED TOGGLE
*
* Description : This function is used to toggle the state of any or all the LEDs on the board.
*
* Argument(s) : led         is the number of the LED to control.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  LED_Toggle (CPU_INT08U led)
{
   (void)&led;                                                  /* Prevent 'variable unused' compiler warning.          */
}
