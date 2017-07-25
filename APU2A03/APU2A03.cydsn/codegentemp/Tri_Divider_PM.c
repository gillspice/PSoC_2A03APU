/*******************************************************************************
* File Name: Tri_Divider_PM.c  
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

#include "Tri_Divider.h"

static Tri_Divider_backupStruct Tri_Divider_backup;


/*******************************************************************************
* Function Name: Tri_Divider_SaveConfig
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
*  Tri_Divider_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Tri_Divider_SaveConfig(void) 
{
    #if (!Tri_Divider_UsingFixedFunction)

        Tri_Divider_backup.CounterUdb = Tri_Divider_ReadCounter();

        #if(!Tri_Divider_ControlRegRemoved)
            Tri_Divider_backup.CounterControlRegister = Tri_Divider_ReadControlRegister();
        #endif /* (!Tri_Divider_ControlRegRemoved) */

    #endif /* (!Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_RestoreConfig
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
*  Tri_Divider_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Tri_Divider_RestoreConfig(void) 
{      
    #if (!Tri_Divider_UsingFixedFunction)

       Tri_Divider_WriteCounter(Tri_Divider_backup.CounterUdb);

        #if(!Tri_Divider_ControlRegRemoved)
            Tri_Divider_WriteControlRegister(Tri_Divider_backup.CounterControlRegister);
        #endif /* (!Tri_Divider_ControlRegRemoved) */

    #endif /* (!Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_Sleep
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
*  Tri_Divider_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Tri_Divider_Sleep(void) 
{
    #if(!Tri_Divider_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Tri_Divider_CTRL_ENABLE == (Tri_Divider_CONTROL & Tri_Divider_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Tri_Divider_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Tri_Divider_backup.CounterEnableState = 0u;
        }
    #else
        Tri_Divider_backup.CounterEnableState = 1u;
        if(Tri_Divider_backup.CounterEnableState != 0u)
        {
            Tri_Divider_backup.CounterEnableState = 0u;
        }
    #endif /* (!Tri_Divider_ControlRegRemoved) */
    
    Tri_Divider_Stop();
    Tri_Divider_SaveConfig();
}


/*******************************************************************************
* Function Name: Tri_Divider_Wakeup
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
*  Tri_Divider_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Tri_Divider_Wakeup(void) 
{
    Tri_Divider_RestoreConfig();
    #if(!Tri_Divider_ControlRegRemoved)
        if(Tri_Divider_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Tri_Divider_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Tri_Divider_ControlRegRemoved) */
    
}


/* [] END OF FILE */
