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
*                                      APPLICATION CONFIGURATION
*
*                                          Microsoft Windows
*
* Filename      : app_cfg.h
* Version       : V1.00
* Programmer(s) : FGK
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  APP_CFG_MODULE_PRESENT
#define  APP_CFG_MODULE_PRESENT


#define  OS_TASK_TMR_PRIO                        (OS_LOWEST_PRIO - 2)

//Modification here
#define COMP_TIME 0
#define DEADLINE 1
#define RELEASE_TIME 2
#define CHILD_COUNT 1
#define DEPENDENCY_COUNT 0

/*
*********************************************************************************************************
*                                          TASKS PRIORITIES
*********************************************************************************************************
*/

#define  APP_TASK_START_PRIO                              60u

/*
*********************************************************************************************************
*                                          TASK STACK SIZES
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE                         256u
//Modification here
//预留其它任务栈大小的设定宏
#define  APP_TASK_STK_SIZE                               256u

/*
*********************************************************************************************************
*                                     TRACE / DEBUG CONFIGURATION
*********************************************************************************************************
*/

#define  TRACE_LEVEL_OFF                       0u
#define  TRACE_LEVEL_INFO                      1u
#define  TRACE_LEVEL_DBG                       2u

#define  APP_TRACE_LEVEL                TRACE_LEVEL_OFF
#define  APP_TRACE                      printf

#define  APP_TRACE_INFO(x)            ((APP_TRACE_LEVEL >= TRACE_LEVEL_INFO) ? (void)(APP_TRACE x) : (void)0)
#define  APP_TRACE_DBG(x)             ((APP_TRACE_LEVEL >= TRACE_LEVEL_DBG)  ? (void)(APP_TRACE x) : (void)0)

/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of APP cfg module include.                       */
