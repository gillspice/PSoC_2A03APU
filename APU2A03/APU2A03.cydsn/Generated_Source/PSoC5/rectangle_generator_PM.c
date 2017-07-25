/*******************************************************************************
* File Name: rectangle_generator_PM.c
* Version 2.30
*
* Description:
*  This file provides the API source code for sleep mode support for Shift
*  Register component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "rectangle_generator.h"

static rectangle_generator_BACKUP_STRUCT rectangle_generator_backup =
{
    rectangle_generator_DISABLED,

    ((uint16) rectangle_generator_DEFAULT_A0),
    ((uint16) rectangle_generator_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint16) rectangle_generator_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: rectangle_generator_SaveConfig
********************************************************************************
*
* Summary:
*  Saves Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void rectangle_generator_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    rectangle_generator_backup.saveSrA0Reg   = CY_GET_REG16(rectangle_generator_SHIFT_REG_LSB_PTR);
    rectangle_generator_backup.saveSrA1Reg   = CY_GET_REG16(rectangle_generator_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        rectangle_generator_backup.saveSrIntMask = rectangle_generator_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: rectangle_generator_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void rectangle_generator_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG16(rectangle_generator_SHIFT_REG_LSB_PTR, rectangle_generator_backup.saveSrA0Reg);
    CY_SET_REG16(rectangle_generator_SHIFT_REG_VALUE_LSB_PTR, rectangle_generator_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        rectangle_generator_SR_STATUS_MASK = ((uint8) rectangle_generator_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: rectangle_generator_Sleep
********************************************************************************
*
* Summary:
*  Prepare the component to enter a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void rectangle_generator_Sleep(void) 
{
    rectangle_generator_backup.enableState = ((uint8) rectangle_generator_IS_ENABLED);

    rectangle_generator_Stop();
    rectangle_generator_SaveConfig();
}


/*******************************************************************************
* Function Name: rectangle_generator_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void rectangle_generator_Wakeup(void) 
{
    rectangle_generator_RestoreConfig();

    if(0u != rectangle_generator_backup.enableState)
    {
        rectangle_generator_Enable();
    }
}


/* [] END OF FILE */
