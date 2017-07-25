/*******************************************************************************
* File Name: volume_generator.h
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

#if !defined(CY_COUNT7_volume_generator_H)
#define CY_COUNT7_volume_generator_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  volume_generator_Init(void) ;
void  volume_generator_Enable(void) ;
void  volume_generator_Start(void) ;
void  volume_generator_Stop(void) ;
void  volume_generator_WriteCounter(uint8 count) ;
uint8 volume_generator_ReadCounter(void) ;
void  volume_generator_WritePeriod(uint8 period) ;
uint8 volume_generator_ReadPeriod(void) ;
void  volume_generator_SaveConfig(void) ;
void  volume_generator_RestoreConfig(void) ;
void  volume_generator_Sleep(void) ;
void  volume_generator_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} volume_generator_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern volume_generator_BACKUP_STRUCT volume_generator_backup;
extern uint8 volume_generator_initVar;


/***************************************
* Initial Parameter
***************************************/
#define volume_generator_INITIAL_PERIOD               (31u)


/***************************************
* Registers
***************************************/
#define volume_generator_COUNT_REG                    (*(reg8 *) volume_generator_Counter7__COUNT_REG)
#define volume_generator_COUNT_PTR                    ( (reg8 *) volume_generator_Counter7__COUNT_REG)
#define volume_generator_PERIOD_REG                   (*(reg8 *) volume_generator_Counter7__PERIOD_REG)
#define volume_generator_PERIOD_PTR                   ( (reg8 *) volume_generator_Counter7__PERIOD_REG)
#define volume_generator_AUX_CONTROL_REG              (*(reg8 *) volume_generator_Counter7__CONTROL_AUX_CTL_REG)
#define volume_generator_AUX_CONTROL_PTR              ( (reg8 *) volume_generator_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define volume_generator_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define volume_generator_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_volume_generator_H */


/* [] END OF FILE */
