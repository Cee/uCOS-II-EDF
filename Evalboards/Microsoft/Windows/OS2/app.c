/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*                          (c) Copyright 2009-2011; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                          APPLICATION CODE
*
*                                          Microsoft Windows
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : JJL
*                 FGK
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <includes.h>


/*
*********************************************************************************************************
*                                             LOCAL DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            LOCAL VARIABLES
*********************************************************************************************************
*/

//Modification here
//定义其它任务的栈空间
static CPU_STK stack1[APP_TASK_STK_SIZE];
static CPU_STK stack2[APP_TASK_STK_SIZE];
static CPU_STK stack3[APP_TASK_STK_SIZE];
static CPU_STK stack4[APP_TASK_STK_SIZE];
static CPU_STK stack5[APP_TASK_STK_SIZE];
static CPU_STK stack6[APP_TASK_STK_SIZE];
static CPU_STK stack7[APP_TASK_STK_SIZE];
static CPU_STK stack8[APP_TASK_STK_SIZE];
static CPU_STK stack9[APP_TASK_STK_SIZE];
static CPU_STK stack10[APP_TASK_STK_SIZE];
static CPU_STK stack11[APP_TASK_STK_SIZE];
static CPU_STK stack12[APP_TASK_STK_SIZE];


INT32S limits[][3] = {
		{ 0, 0, 0 },//Prio0，不用
		{ 1, 3, 0 },//Prio1
		{ 3, 6, 0 },//Prio2
		{ 4, 9, 0 }//Prio3
};

/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppTaskStart(void  *p_arg);
static  void  periodicTask(void  *p_arg);
static  void  sporadicTask(void  *p_arg);

INT32S tryChangeD(INT8U taskPriority);
INT32S tryChangeR(INT8U taskPriority);

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Argument(s) : none.
*
* Return(s)   : none.
*********************************************************************************************************
*/





int  main (void)
{

    OSInit();                                                   /* Init uC/OS-II.                                       */
	CPU_Init();


	OSTaskCreateExt(periodicTask,
		(void *)limits[1],
		stack1 + (APP_TASK_STK_SIZE - 1),
		(INT8U)(1),
		(INT16U)(1),
		stack1,
		(INT32U)APP_TASK_STK_SIZE,
		(void *)limits[1],
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

	OSTaskCreateExt(periodicTask,
		(void *)limits[2],
		stack2 + (APP_TASK_STK_SIZE - 1),
		(INT8U)(2),
		(INT16U)(2),
		stack2,
		(INT32U)APP_TASK_STK_SIZE,
		(void *)limits[2],
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

	OSTaskCreateExt(periodicTask,
		(void *)limits[3],
		stack3 + (APP_TASK_STK_SIZE - 1),
		(INT8U)(3),
		(INT16U)(3),
		stack3,
		(INT32U)APP_TASK_STK_SIZE,
		(void *)limits[3],
		(INT16U)(OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

    OSStart();                                                  /* Start multitasking (i.e. give control to uC/OS-II).  */
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg       is the argument passed to 'AppTaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Note(s)     : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static void periodicTask(void *p_arg)
{
	INT32S *p = (INT32S *)p_arg;

	INT32S start;
	INT32S end;
	INT32S toDelay;
	start = 0;

	while (1)
	{
		while (OSTCBCur->compTime > 0)
		{
			//Do nothing
		}
		end = OSTimeGet();
		toDelay = OSTCBCur->period - (end - start) % OSTCBCur->period;
		toDelay = toDelay < 0 ? 0 : toDelay;
		start += (OSTCBCur->period);
		OSTCBCur->compTime = OSTCBCur->fullCompTime;
		OSTimeDly(toDelay);
	}
}
