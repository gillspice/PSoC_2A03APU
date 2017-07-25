/*******************************************************************************
* File Name: rectangle_generator.c
* Version 2.30
*
* Description:
*  This file provides the API source code for the Shift Register component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "rectangle_generator.h"

uint8 rectangle_generator_initVar = 0u;


/*******************************************************************************
* Function Name: rectangle_generator_Start
********************************************************************************
*
* Summary:
*  Starts the Shift Register.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  rectangle_generator_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void rectangle_generator_Start(void) 
{
    if(0u == rectangle_generator_initVar)
    {
        rectangle_generator_Init();
        rectangle_generator_initVar = 1u; /* Component initialized */
    }

    rectangle_generator_Enable();
}


/*******************************************************************************
* Function Name: rectangle_generator_Enable
********************************************************************************
*
* Summary:
*  Enables the Shift Register.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void rectangle_generator_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    rectangle_generator_SR_CONTROL |= rectangle_generator_CLK_EN;

    rectangle_generator_EnableInt();
}


/*******************************************************************************
* Function Name: rectangle_generator_Init
********************************************************************************
*
* Summary:
*  Initializes Tx and/or Rx interrupt sources with initial values.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void rectangle_generator_Init(void) 
{
    rectangle_generator_SetIntMode(rectangle_generator_INT_SRC);
}


/*******************************************************************************
* Function Name: rectangle_generator_Stop
********************************************************************************
*
* Summary:
*  Disables the Shift Register
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void rectangle_generator_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    rectangle_generator_SR_CONTROL &= ((uint8) ~rectangle_generator_CLK_EN);
    rectangle_generator_DisableInt();
}


/*******************************************************************************
* Function Name: rectangle_generator_EnableInt
********************************************************************************
*
* Summary:
*  Enables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void rectangle_generator_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    rectangle_generator_SR_AUX_CONTROL |= rectangle_generator_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: rectangle_generator_DisableInt
********************************************************************************
*
* Summary:
*  Disables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void rectangle_generator_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    rectangle_generator_SR_AUX_CONTROL &= ((uint8) ~rectangle_generator_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: rectangle_generator_GetFIFOStatus
********************************************************************************
*
* Summary:
*  Returns current status of input or output FIFO.
*
* Parameters:
*  fifoId.
*
* Return:
*  FIFO status.
*
*******************************************************************************/
uint8 rectangle_generator_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = rectangle_generator_RET_FIFO_NOT_DEFINED;

    #if(0u != rectangle_generator_USE_INPUT_FIFO)
        if(rectangle_generator_IN_FIFO == fifoId)
        {
            switch(rectangle_generator_GET_IN_FIFO_STS)
            {
                case rectangle_generator_IN_FIFO_FULL :
                    result = rectangle_generator_RET_FIFO_FULL;
                    break;

                case rectangle_generator_IN_FIFO_EMPTY :
                    result = rectangle_generator_RET_FIFO_EMPTY;
                    break;

                case rectangle_generator_IN_FIFO_PARTIAL:
                    result = rectangle_generator_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = rectangle_generator_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != rectangle_generator_USE_INPUT_FIFO) */

    if(rectangle_generator_OUT_FIFO == fifoId)
    {
        switch(rectangle_generator_GET_OUT_FIFO_STS)
        {
            case rectangle_generator_OUT_FIFO_FULL :
                result = rectangle_generator_RET_FIFO_FULL;
                break;

            case rectangle_generator_OUT_FIFO_EMPTY :
                result = rectangle_generator_RET_FIFO_EMPTY;
                break;

            case rectangle_generator_OUT_FIFO_PARTIAL :
                result = rectangle_generator_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = rectangle_generator_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: rectangle_generator_SetIntMode
********************************************************************************
*
* Summary:
*  Sets the Interrupt Source for the Shift Register interrupt. Multiple
*  sources may be ORed together
*
* Parameters:
*  interruptSource: Byte containing the constant for the selected interrupt
*  source/s.
*
* Return:
*  None.
*
*******************************************************************************/
void rectangle_generator_SetIntMode(uint8 interruptSource) 
{
    rectangle_generator_SR_STATUS_MASK &= ((uint8) ~rectangle_generator_INTS_EN_MASK);          /* Clear existing int */
    rectangle_generator_SR_STATUS_MASK |= (interruptSource & rectangle_generator_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: rectangle_generator_GetIntStatus
********************************************************************************
*
* Summary:
*  Gets the Shift Register Interrupt status.
*
* Parameters:
*  None.
*
* Return:
*  Byte containing the constant for the selected interrupt source/s.
*
*******************************************************************************/
uint8 rectangle_generator_GetIntStatus(void) 
{
    return(rectangle_generator_SR_STATUS & rectangle_generator_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: rectangle_generator_WriteRegValue
********************************************************************************
*
* Summary:
*  Send state directly to shift register
*
* Parameters:
*  shiftData: containing shift register state.
*
* Return:
*  None.
*
*******************************************************************************/
void rectangle_generator_WriteRegValue(uint16 shiftData)
                                                                     
{
    CY_SET_REG16(rectangle_generator_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != rectangle_generator_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: rectangle_generator_WriteData
    ********************************************************************************
    *
    * Summary:
    *  Send state to FIFO for later transfer to shift register based on the Load
    *  input
    *
    * Parameters:
    *  shiftData: containing shift register state.
    *
    * Return:
    *  Indicates: successful execution of function
    *  when FIFO is empty; and error when FIFO is full.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    cystatus rectangle_generator_WriteData(uint16 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(rectangle_generator_RET_FIFO_FULL != (rectangle_generator_GetFIFOStatus(rectangle_generator_IN_FIFO)))
        {
            CY_SET_REG16(rectangle_generator_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != rectangle_generator_USE_INPUT_FIFO) */


#if(0u != rectangle_generator_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: rectangle_generator_ReadData
    ********************************************************************************
    *
    * Summary:
    *  Returns state in FIFO due to Store input.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Shift Register state
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint16 rectangle_generator_ReadData(void) 
    {
        return(CY_GET_REG16(rectangle_generator_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != rectangle_generator_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: rectangle_generator_ReadRegValue
********************************************************************************
*
* Summary:
*  Directly returns current state in shift register, not data in FIFO due
*  to Store input.
*
* Parameters:
*  None.
*
* Return:
*  Shift Register state. Clears output FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint16 rectangle_generator_ReadRegValue(void) 
{
    uint16 result;

    /* Clear FIFO before software capture */
    while(rectangle_generator_RET_FIFO_EMPTY != rectangle_generator_GetFIFOStatus(rectangle_generator_OUT_FIFO))
    {
        (void) CY_GET_REG16(rectangle_generator_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(rectangle_generator_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG16(rectangle_generator_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (rectangle_generator_SR_SIZE % 8u))
        result &= ((uint16) rectangle_generator_SR_MASK);
    #endif /* (0u != (rectangle_generator_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
