/*******************************************************************************
* File Name: volume_generator_PM.c
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

#include "volume_generator.h"


volume_generator_BACKUP_STRUCT volume_generator_backup;


/*******************************************************************************
* Function Name: volume_generator_SaveConfig
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
*  volume_generator_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void volume_generator_SaveConfig(void) 
{
    volume_generator_backup.count = volume_generator_COUNT_REG;
}


/*******************************************************************************
* Function Name: volume_generator_Sleep
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
void volume_generator_Sleep(void) 
{
    if(0u != (volume_generator_AUX_CONTROL_REG & volume_generator_COUNTER_START))
    {
        volume_generator_backup.enableState = 1u;
        volume_generator_Stop();
    }
    else
    {
        volume_generator_backup.enableState = 0u;
    }

    volume_generator_SaveConfig();
}


/*******************************************************************************
* Function Name: volume_generator_RestoreConfig
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
*  volume_generator_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void volume_generator_RestoreConfig(void) 
{
    volume_generator_COUNT_REG = volume_generator_backup.count;
}


/*******************************************************************************
* Function Name: volume_generator_Wakeup
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
void volume_generator_Wakeup(void) 
{
    volume_generator_RestoreConfig();

    /* Restore enable state */
    if (volume_generator_backup.enableState != 0u)
    {
        volume_generator_Enable();
    }
}


/* [] END OF FILE */
