/*******************************************************************************
* File Name: Noise_Vol_Clk_Div.h
* Version 1.0
*
* Description:
*  This header file contains registers and constants associated with the
*  Count7 component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COUNT7_Noise_Vol_Clk_Div_H)
#define CY_COUNT7_Noise_Vol_Clk_Div_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  Noise_Vol_Clk_Div_Init(void) ;
void  Noise_Vol_Clk_Div_Enable(void) ;
void  Noise_Vol_Clk_Div_Start(void) ;
void  Noise_Vol_Clk_Div_Stop(void) ;
void  Noise_Vol_Clk_Div_WriteCounter(uint8 count) ;
uint8 Noise_Vol_Clk_Div_ReadCounter(void) ;
void  Noise_Vol_Clk_Div_WritePeriod(uint8 period) ;
uint8 Noise_Vol_Clk_Div_ReadPeriod(void) ;
void  Noise_Vol_Clk_Div_SaveConfig(void) ;
void  Noise_Vol_Clk_Div_RestoreConfig(void) ;
void  Noise_Vol_Clk_Div_Sleep(void) ;
void  Noise_Vol_Clk_Div_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} Noise_Vol_Clk_Div_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern Noise_Vol_Clk_Div_BACKUP_STRUCT Noise_Vol_Clk_Div_backup;
extern uint8 Noise_Vol_Clk_Div_initVar;


/***************************************
* Initial Parameter
***************************************/
#define Noise_Vol_Clk_Div_INITIAL_PERIOD               (31u)


/***************************************
* Registers
***************************************/
#define Noise_Vol_Clk_Div_COUNT_REG                    (*(reg8 *) Noise_Vol_Clk_Div_Counter7__COUNT_REG)
#define Noise_Vol_Clk_Div_COUNT_PTR                    ( (reg8 *) Noise_Vol_Clk_Div_Counter7__COUNT_REG)
#define Noise_Vol_Clk_Div_PERIOD_REG                   (*(reg8 *) Noise_Vol_Clk_Div_Counter7__PERIOD_REG)
#define Noise_Vol_Clk_Div_PERIOD_PTR                   ( (reg8 *) Noise_Vol_Clk_Div_Counter7__PERIOD_REG)
#define Noise_Vol_Clk_Div_AUX_CONTROL_REG              (*(reg8 *) Noise_Vol_Clk_Div_Counter7__CONTROL_AUX_CTL_REG)
#define Noise_Vol_Clk_Div_AUX_CONTROL_PTR              ( (reg8 *) Noise_Vol_Clk_Div_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define Noise_Vol_Clk_Div_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define Noise_Vol_Clk_Div_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_Noise_Vol_Clk_Div_H */


/* [] END OF FILE */
