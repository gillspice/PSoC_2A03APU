/*******************************************************************************
* File Name: Length_Counter_1_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Length_Counter_1.h"

static Length_Counter_1_backupStruct Length_Counter_1_backup;


/*******************************************************************************
* Function Name: Length_Counter_1_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Length_Counter_1_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Length_Counter_1_SaveConfig(void) 
{
    #if (!Length_Counter_1_UsingFixedFunction)

        Length_Counter_1_backup.CounterUdb = Length_Counter_1_ReadCounter();

        #if(!Length_Counter_1_ControlRegRemoved)
            Length_Counter_1_backup.CounterControlRegister = Length_Counter_1_ReadControlRegister();
        #endif /* (!Length_Counter_1_ControlRegRemoved) */

    #endif /* (!Length_Counter_1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Length_Counter_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Length_Counter_1_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Length_Counter_1_RestoreConfig(void) 
{      
    #if (!Length_Counter_1_UsingFixedFunction)

       Length_Counter_1_WriteCounter(Length_Counter_1_backup.CounterUdb);

        #if(!Length_Counter_1_ControlRegRemoved)
            Length_Counter_1_WriteControlRegister(Length_Counter_1_backup.CounterControlRegister);
        #endif /* (!Length_Counter_1_ControlRegRemoved) */

    #endif /* (!Length_Counter_1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Length_Counter_1_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Length_Counter_1_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Length_Counter_1_Sleep(void) 
{
    #if(!Length_Counter_1_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Length_Counter_1_CTRL_ENABLE == (Length_Counter_1_CONTROL & Length_Counter_1_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Length_Counter_1_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Length_Counter_1_backup.CounterEnableState = 0u;
        }
    #else
        Length_Counter_1_backup.CounterEnableState = 1u;
        if(Length_Counter_1_backup.CounterEnableState != 0u)
        {
            Length_Counter_1_backup.CounterEnableState = 0u;
        }
    #endif /* (!Length_Counter_1_ControlRegRemoved) */
    
    Length_Counter_1_Stop();
    Length_Counter_1_SaveConfig();
}


/*******************************************************************************
* Function Name: Length_Counter_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Length_Counter_1_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Length_Counter_1_Wakeup(void) 
{
    Length_Counter_1_RestoreConfig();
    #if(!Length_Counter_1_ControlRegRemoved)
        if(Length_Counter_1_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Length_Counter_1_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Length_Counter_1_ControlRegRemoved) */
    
}


/* [] END OF FILE */
