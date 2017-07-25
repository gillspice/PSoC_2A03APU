/*******************************************************************************
* File Name: Noise_Clk_Div_PM.c  
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

#include "Noise_Clk_Div.h"

static Noise_Clk_Div_backupStruct Noise_Clk_Div_backup;


/*******************************************************************************
* Function Name: Noise_Clk_Div_SaveConfig
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
*  Noise_Clk_Div_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Noise_Clk_Div_SaveConfig(void) 
{
    #if (!Noise_Clk_Div_UsingFixedFunction)

        Noise_Clk_Div_backup.CounterUdb = Noise_Clk_Div_ReadCounter();

        #if(!Noise_Clk_Div_ControlRegRemoved)
            Noise_Clk_Div_backup.CounterControlRegister = Noise_Clk_Div_ReadControlRegister();
        #endif /* (!Noise_Clk_Div_ControlRegRemoved) */

    #endif /* (!Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_RestoreConfig
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
*  Noise_Clk_Div_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Noise_Clk_Div_RestoreConfig(void) 
{      
    #if (!Noise_Clk_Div_UsingFixedFunction)

       Noise_Clk_Div_WriteCounter(Noise_Clk_Div_backup.CounterUdb);

        #if(!Noise_Clk_Div_ControlRegRemoved)
            Noise_Clk_Div_WriteControlRegister(Noise_Clk_Div_backup.CounterControlRegister);
        #endif /* (!Noise_Clk_Div_ControlRegRemoved) */

    #endif /* (!Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_Sleep
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
*  Noise_Clk_Div_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Noise_Clk_Div_Sleep(void) 
{
    #if(!Noise_Clk_Div_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Noise_Clk_Div_CTRL_ENABLE == (Noise_Clk_Div_CONTROL & Noise_Clk_Div_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Noise_Clk_Div_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Noise_Clk_Div_backup.CounterEnableState = 0u;
        }
    #else
        Noise_Clk_Div_backup.CounterEnableState = 1u;
        if(Noise_Clk_Div_backup.CounterEnableState != 0u)
        {
            Noise_Clk_Div_backup.CounterEnableState = 0u;
        }
    #endif /* (!Noise_Clk_Div_ControlRegRemoved) */
    
    Noise_Clk_Div_Stop();
    Noise_Clk_Div_SaveConfig();
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_Wakeup
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
*  Noise_Clk_Div_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Noise_Clk_Div_Wakeup(void) 
{
    Noise_Clk_Div_RestoreConfig();
    #if(!Noise_Clk_Div_ControlRegRemoved)
        if(Noise_Clk_Div_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Noise_Clk_Div_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Noise_Clk_Div_ControlRegRemoved) */
    
}


/* [] END OF FILE */
