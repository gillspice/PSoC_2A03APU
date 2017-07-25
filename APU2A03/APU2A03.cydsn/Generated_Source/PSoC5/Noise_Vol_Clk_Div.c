/*******************************************************************************
* File Name: Noise_Vol_Clk_Div.c
* Version 1.0
*
* Description:
*  This file provides source code for the Count7 component's API.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Noise_Vol_Clk_Div.h"
#include "CyLib.h"


uint8 Noise_Vol_Clk_Div_initVar = 0u;


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the parameter editor
*  settings.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Theory:
*  It is not necessary to call Count7_Init() because the Count7_Start() API
*  calls this function and is the preferred method to begin component
*  operation.
*
*******************************************************************************/
void Noise_Vol_Clk_Div_Init(void) 
{
    /* Set the initial period value from parameter editor */
    Noise_Vol_Clk_Div_PERIOD_REG = Noise_Vol_Clk_Div_INITIAL_PERIOD;
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_Enable
********************************************************************************
*
* Summary:
*  Enables the software enable of the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Theory:
*  It is not necessary to call Count7_Enable() because the Count7_Start() API
*  calls this function, which is the preferred method to begin component
*  operation.
*  This API performs modification of auxiliary control register which is a
*  shared resource so it is required to disable interrupts until the
*  modification will complete.
*
*******************************************************************************/
void Noise_Vol_Clk_Div_Enable(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    /* Set the counter start bit in auxiliary control. If routed enable
    * isn't used then this will immediately star the Count7 operation.
    */
    Noise_Vol_Clk_Div_AUX_CONTROL_REG |= Noise_Vol_Clk_Div_COUNTER_START;

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_Start
********************************************************************************
*
* Summary:
*  Performs all of the required initialization for the component and enables
*  the counter. The first time the routine is executed, the period is set as
*  configured in the customizer. When called to restart the counter following a
*  Count7_Stop() call, the current period value is retained.
*
* Parameters:
*  None.
*
* Global Variables:
*  Noise_Vol_Clk_Div_initVar - global variable.
*
* Return:
*  None.
*
*******************************************************************************/
void Noise_Vol_Clk_Div_Start(void) 
{
    /* If not initialized then perform initialization */
    if(Noise_Vol_Clk_Div_initVar == 0u)
    {
        Noise_Vol_Clk_Div_Init();
        Noise_Vol_Clk_Div_initVar = 1u;
    }

    /* Enable Count7 */
    Noise_Vol_Clk_Div_Enable();
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_Stop
********************************************************************************
*
* Summary:
*  Disables the software enable of the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Noise_Vol_Clk_Div_Stop(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    /* Clear the counter start bit in auxiliary control. */
    Noise_Vol_Clk_Div_AUX_CONTROL_REG &= (uint8) ~((uint8) Noise_Vol_Clk_Div_COUNTER_START);

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_WriteCounter
********************************************************************************
*
* Summary:
*  This function writes the counter directly. The counter should be disabled
*  before calling this function.
*
* Parameters:
*  count - Value to be written to counter.
*
* Return:
*  None
*
*******************************************************************************/
void Noise_Vol_Clk_Div_WriteCounter(uint8 count) 
{
    Noise_Vol_Clk_Div_COUNT_REG = (count & Noise_Vol_Clk_Div_COUNT_7BIT_MASK);
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_ReadCounter
********************************************************************************
*
* Summary:
*  This function reads the counter value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
uint8 Noise_Vol_Clk_Div_ReadCounter(void) 
{
    return(Noise_Vol_Clk_Div_COUNT_REG & Noise_Vol_Clk_Div_COUNT_7BIT_MASK);
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_WritePeriod
********************************************************************************
*
* Summary:
*  This function writes the period register. The actual period is one greater
*  than the value in the period register since the counting sequence starts
*  with the period register and counts down to 0 inclusive. The period of the
*  counter output does not change until the counter is reloaded following the
*  terminal count value of 0 or due to a hardware load signal.
*
* Parameters:
*  period - Period value to be written.
*
* Return:
*  None
*
*******************************************************************************/
void Noise_Vol_Clk_Div_WritePeriod(uint8 period) 
{
    Noise_Vol_Clk_Div_PERIOD_REG = period;
}


/*******************************************************************************
* Function Name: Noise_Vol_Clk_Div_ReadPeriod
********************************************************************************
*
* Summary:
*  This function reads the period register.
*
* Parameters:
*  None
*
* Return:
*  uint8 - Current period value.
*
*******************************************************************************/
uint8 Noise_Vol_Clk_Div_ReadPeriod(void) 
{
    return(Noise_Vol_Clk_Div_PERIOD_REG);
}


/* [] END OF FILE */
