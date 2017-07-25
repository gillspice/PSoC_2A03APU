/*******************************************************************************
* File Name: Tri_Divider.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 Tri_Divider_initVar = 0u;


/*******************************************************************************
* Function Name: Tri_Divider_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Tri_Divider_Init(void) 
{
        #if (!Tri_Divider_UsingFixedFunction && !Tri_Divider_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Tri_Divider_UsingFixedFunction && !Tri_Divider_ControlRegRemoved) */
        
        #if(!Tri_Divider_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Tri_Divider_interruptState;
        #endif /* (!Tri_Divider_UsingFixedFunction) */
        
        #if (Tri_Divider_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Tri_Divider_CONTROL &= Tri_Divider_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Tri_Divider_CONTROL2 &= ((uint8)(~Tri_Divider_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Tri_Divider_CONTROL3 &= ((uint8)(~Tri_Divider_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Tri_Divider_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Tri_Divider_CONTROL |= Tri_Divider_ONESHOT;
            #endif /* (Tri_Divider_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Tri_Divider_CONTROL2 |= Tri_Divider_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Tri_Divider_RT1 &= ((uint8)(~Tri_Divider_RT1_MASK));
            Tri_Divider_RT1 |= Tri_Divider_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Tri_Divider_RT1 &= ((uint8)(~Tri_Divider_SYNCDSI_MASK));
            Tri_Divider_RT1 |= Tri_Divider_SYNCDSI_EN;

        #else
            #if(!Tri_Divider_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Tri_Divider_CONTROL & ((uint8)(~Tri_Divider_CTRL_CMPMODE_MASK));
            Tri_Divider_CONTROL = ctrl | Tri_Divider_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Tri_Divider_CONTROL & ((uint8)(~Tri_Divider_CTRL_CAPMODE_MASK));
            
            #if( 0 != Tri_Divider_CAPTURE_MODE_CONF)
                Tri_Divider_CONTROL = ctrl | Tri_Divider_DEFAULT_CAPTURE_MODE;
            #else
                Tri_Divider_CONTROL = ctrl;
            #endif /* 0 != Tri_Divider_CAPTURE_MODE */ 
            
            #endif /* (!Tri_Divider_ControlRegRemoved) */
        #endif /* (Tri_Divider_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Tri_Divider_UsingFixedFunction)
            Tri_Divider_ClearFIFO();
        #endif /* (!Tri_Divider_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Tri_Divider_WritePeriod(Tri_Divider_INIT_PERIOD_VALUE);
        #if (!(Tri_Divider_UsingFixedFunction && (CY_PSOC5A)))
            Tri_Divider_WriteCounter(Tri_Divider_INIT_COUNTER_VALUE);
        #endif /* (!(Tri_Divider_UsingFixedFunction && (CY_PSOC5A))) */
        Tri_Divider_SetInterruptMode(Tri_Divider_INIT_INTERRUPTS_MASK);
        
        #if (!Tri_Divider_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)Tri_Divider_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Tri_Divider_WriteCompare(Tri_Divider_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Tri_Divider_interruptState = CyEnterCriticalSection();
            
            Tri_Divider_STATUS_AUX_CTRL |= Tri_Divider_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Tri_Divider_interruptState);
            
        #endif /* (!Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void Tri_Divider_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Tri_Divider_UsingFixedFunction)
        Tri_Divider_GLOBAL_ENABLE |= Tri_Divider_BLOCK_EN_MASK;
        Tri_Divider_GLOBAL_STBY_ENABLE |= Tri_Divider_BLOCK_STBY_EN_MASK;
    #endif /* (Tri_Divider_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Tri_Divider_ControlRegRemoved || Tri_Divider_UsingFixedFunction)
        Tri_Divider_CONTROL |= Tri_Divider_CTRL_ENABLE;                
    #endif /* (!Tri_Divider_ControlRegRemoved || Tri_Divider_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Tri_Divider_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  Tri_Divider_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Tri_Divider_Start(void) 
{
    if(Tri_Divider_initVar == 0u)
    {
        Tri_Divider_Init();
        
        Tri_Divider_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Tri_Divider_Enable();        
}


/*******************************************************************************
* Function Name: Tri_Divider_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void Tri_Divider_Stop(void) 
{
    /* Disable Counter */
    #if(!Tri_Divider_ControlRegRemoved || Tri_Divider_UsingFixedFunction)
        Tri_Divider_CONTROL &= ((uint8)(~Tri_Divider_CTRL_ENABLE));        
    #endif /* (!Tri_Divider_ControlRegRemoved || Tri_Divider_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Tri_Divider_UsingFixedFunction)
        Tri_Divider_GLOBAL_ENABLE &= ((uint8)(~Tri_Divider_BLOCK_EN_MASK));
        Tri_Divider_GLOBAL_STBY_ENABLE &= ((uint8)(~Tri_Divider_BLOCK_STBY_EN_MASK));
    #endif /* (Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void Tri_Divider_SetInterruptMode(uint8 interruptsMask) 
{
    Tri_Divider_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Tri_Divider_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   Tri_Divider_ReadStatusRegister(void) 
{
    return Tri_Divider_STATUS;
}


#if(!Tri_Divider_ControlRegRemoved)
/*******************************************************************************
* Function Name: Tri_Divider_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   Tri_Divider_ReadControlRegister(void) 
{
    return Tri_Divider_CONTROL;
}


/*******************************************************************************
* Function Name: Tri_Divider_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    Tri_Divider_WriteControlRegister(uint8 control) 
{
    Tri_Divider_CONTROL = control;
}

#endif  /* (!Tri_Divider_ControlRegRemoved) */


#if (!(Tri_Divider_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Tri_Divider_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void Tri_Divider_WriteCounter(uint16 counter) \
                                   
{
    #if(Tri_Divider_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (Tri_Divider_GLOBAL_ENABLE & Tri_Divider_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Tri_Divider_GLOBAL_ENABLE |= Tri_Divider_BLOCK_EN_MASK;
        CY_SET_REG16(Tri_Divider_COUNTER_LSB_PTR, (uint16)counter);
        Tri_Divider_GLOBAL_ENABLE &= ((uint8)(~Tri_Divider_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(Tri_Divider_COUNTER_LSB_PTR, counter);
    #endif /* (Tri_Divider_UsingFixedFunction) */
}
#endif /* (!(Tri_Divider_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Tri_Divider_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) The present value of the counter.
*
*******************************************************************************/
uint16 Tri_Divider_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Tri_Divider_UsingFixedFunction)
		(void)CY_GET_REG16(Tri_Divider_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(Tri_Divider_COUNTER_LSB_PTR_8BIT);
	#endif/* (Tri_Divider_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Tri_Divider_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Tri_Divider_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(Tri_Divider_STATICCOUNT_LSB_PTR));
    #endif /* (Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint16) Present Capture value.
*
*******************************************************************************/
uint16 Tri_Divider_ReadCapture(void) 
{
    #if(Tri_Divider_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Tri_Divider_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(Tri_Divider_STATICCOUNT_LSB_PTR));
    #endif /* (Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint16) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void Tri_Divider_WritePeriod(uint16 period) 
{
    #if(Tri_Divider_UsingFixedFunction)
        CY_SET_REG16(Tri_Divider_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(Tri_Divider_PERIOD_LSB_PTR, period);
    #endif /* (Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) Present period value.
*
*******************************************************************************/
uint16 Tri_Divider_ReadPeriod(void) 
{
    #if(Tri_Divider_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Tri_Divider_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(Tri_Divider_PERIOD_LSB_PTR));
    #endif /* (Tri_Divider_UsingFixedFunction) */
}


#if (!Tri_Divider_UsingFixedFunction)
/*******************************************************************************
* Function Name: Tri_Divider_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void Tri_Divider_WriteCompare(uint16 compare) \
                                   
{
    #if(Tri_Divider_UsingFixedFunction)
        CY_SET_REG16(Tri_Divider_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(Tri_Divider_COMPARE_LSB_PTR, compare);
    #endif /* (Tri_Divider_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Tri_Divider_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint16) Present compare value.
*
*******************************************************************************/
uint16 Tri_Divider_ReadCompare(void) 
{
    return (CY_GET_REG16(Tri_Divider_COMPARE_LSB_PTR));
}


#if (Tri_Divider_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Tri_Divider_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Tri_Divider_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Tri_Divider_CONTROL &= ((uint8)(~Tri_Divider_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    Tri_Divider_CONTROL |= compareMode;
}
#endif  /* (Tri_Divider_COMPARE_MODE_SOFTWARE) */


#if (Tri_Divider_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Tri_Divider_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Tri_Divider_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Tri_Divider_CONTROL &= ((uint8)(~Tri_Divider_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    Tri_Divider_CONTROL |= ((uint8)((uint8)captureMode << Tri_Divider_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (Tri_Divider_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Tri_Divider_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void Tri_Divider_ClearFIFO(void) 
{

    while(0u != (Tri_Divider_ReadStatusRegister() & Tri_Divider_STATUS_FIFONEMP))
    {
        (void)Tri_Divider_ReadCapture();
    }

}
#endif  /* (!Tri_Divider_UsingFixedFunction) */


/* [] END OF FILE */

