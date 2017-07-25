/*******************************************************************************
* File Name: Noise_Vol_Clk_Div_PM.c
* Version 1.0
*
* Description:
*  This file provides Low power mode APIs for Count7 component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Noise_Vol_Clk_Div.h"


Noise_Vol_Clk_Div_BACKUP_STRUCT Noise_Vol_Clk_Div_backup;


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component configuration and non-retention registers.
*  This function is called by the Count7_Sleep() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  Noise_Vol_Clk_Div_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void Noise_Vol_Clk_Div_SaveConfig(void) 
{
    Noise_Vol_Clk_Div_backup.count = Noise_Vol_Clk_Div_COUNT_REG;
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for low power mode
*  operation. The Count7_Sleep() API saves the current component state using
*  Count7_SaveConfig() and disables the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Noise_Vol_Clk_Div_Sleep(void) 
{
    if(0u != (Noise_Vol_Clk_Div_AUX_CONTROL_REG & Noise_Vol_Clk_Div_COUNTER_START))
    {
        Noise_Vol_Clk_Div_backup.enableState = 1u;
        Noise_Vol_Clk_Div_Stop();
    }
    else
    {
        Noise_Vol_Clk_Div_backup.enableState = 0u;
    }

    Noise_Vol_Clk_Div_SaveConfig();
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_RestoreConfig
********************************************************************************
*
* Summary:
*  This function restores the component configuration and non-retention
*  registers. This function is called by the Count7_Wakeup() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  Noise_Vol_Clk_Div_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void Noise_Vol_Clk_Div_RestoreConfig(void) 
{
    Noise_Vol_Clk_Div_COUNT_REG = Noise_Vol_Clk_Div_backup.count;
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when
*  Count7_Sleep() was called. The Count7_Wakeup() function calls the
*  Count7_RestoreConfig() function to restore the configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Noise_Vol_Clk_Div_Wakeup(void) 
{
    Noise_Vol_Clk_Div_RestoreConfig();

    /* Restore enable state */
    if (Noise_Vol_Clk_Div_backup.enableState != 0u)
    {
        Noise_Vol_Clk_Div_Enable();
    }
}


/* [] END OF FILE */
