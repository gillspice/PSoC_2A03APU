/*******************************************************************************
* File Name: Noise_Clk_Div.c  
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

#include "Noise_Clk_Div.h"

uint8 Noise_Clk_Div_initVar = 0u;


/*******************************************************************************
* Function Name: Noise_Clk_Div_Init
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
void Noise_Clk_Div_Init(void) 
{
        #if (!Noise_Clk_Div_UsingFixedFunction && !Noise_Clk_Div_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Noise_Clk_Div_UsingFixedFunction && !Noise_Clk_Div_ControlRegRemoved) */
        
        #if(!Noise_Clk_Div_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Noise_Clk_Div_interruptState;
        #endif /* (!Noise_Clk_Div_UsingFixedFunction) */
        
        #if (Noise_Clk_Div_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Noise_Clk_Div_CONTROL &= Noise_Clk_Div_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Noise_Clk_Div_CONTROL2 &= ((uint8)(~Noise_Clk_Div_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Noise_Clk_Div_CONTROL3 &= ((uint8)(~Noise_Clk_Div_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Noise_Clk_Div_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Noise_Clk_Div_CONTROL |= Noise_Clk_Div_ONESHOT;
            #endif /* (Noise_Clk_Div_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Noise_Clk_Div_CONTROL2 |= Noise_Clk_Div_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Noise_Clk_Div_RT1 &= ((uint8)(~Noise_Clk_Div_RT1_MASK));
            Noise_Clk_Div_RT1 |= Noise_Clk_Div_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Noise_Clk_Div_RT1 &= ((uint8)(~Noise_Clk_Div_SYNCDSI_MASK));
            Noise_Clk_Div_RT1 |= Noise_Clk_Div_SYNCDSI_EN;

        #else
            #if(!Noise_Clk_Div_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Noise_Clk_Div_CONTROL & ((uint8)(~Noise_Clk_Div_CTRL_CMPMODE_MASK));
            Noise_Clk_Div_CONTROL = ctrl | Noise_Clk_Div_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Noise_Clk_Div_CONTROL & ((uint8)(~Noise_Clk_Div_CTRL_CAPMODE_MASK));
            
            #if( 0 != Noise_Clk_Div_CAPTURE_MODE_CONF)
                Noise_Clk_Div_CONTROL = ctrl | Noise_Clk_Div_DEFAULT_CAPTURE_MODE;
            #else
                Noise_Clk_Div_CONTROL = ctrl;
            #endif /* 0 != Noise_Clk_Div_CAPTURE_MODE */ 
            
            #endif /* (!Noise_Clk_Div_ControlRegRemoved) */
        #endif /* (Noise_Clk_Div_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Noise_Clk_Div_UsingFixedFunction)
            Noise_Clk_Div_ClearFIFO();
        #endif /* (!Noise_Clk_Div_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Noise_Clk_Div_WritePeriod(Noise_Clk_Div_INIT_PERIOD_VALUE);
        #if (!(Noise_Clk_Div_UsingFixedFunction && (CY_PSOC5A)))
            Noise_Clk_Div_WriteCounter(Noise_Clk_Div_INIT_COUNTER_VALUE);
        #endif /* (!(Noise_Clk_Div_UsingFixedFunction && (CY_PSOC5A))) */
        Noise_Clk_Div_SetInterruptMode(Noise_Clk_Div_INIT_INTERRUPTS_MASK);
        
        #if (!Noise_Clk_Div_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)Noise_Clk_Div_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Noise_Clk_Div_WriteCompare(Noise_Clk_Div_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Noise_Clk_Div_interruptState = CyEnterCriticalSection();
            
            Noise_Clk_Div_STATUS_AUX_CTRL |= Noise_Clk_Div_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Noise_Clk_Div_interruptState);
            
        #endif /* (!Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_Enable
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
void Noise_Clk_Div_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Noise_Clk_Div_UsingFixedFunction)
        Noise_Clk_Div_GLOBAL_ENABLE |= Noise_Clk_Div_BLOCK_EN_MASK;
        Noise_Clk_Div_GLOBAL_STBY_ENABLE |= Noise_Clk_Div_BLOCK_STBY_EN_MASK;
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Noise_Clk_Div_ControlRegRemoved || Noise_Clk_Div_UsingFixedFunction)
        Noise_Clk_Div_CONTROL |= Noise_Clk_Div_CTRL_ENABLE;                
    #endif /* (!Noise_Clk_Div_ControlRegRemoved || Noise_Clk_Div_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_Start
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
*  Noise_Clk_Div_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Noise_Clk_Div_Start(void) 
{
    if(Noise_Clk_Div_initVar == 0u)
    {
        Noise_Clk_Div_Init();
        
        Noise_Clk_Div_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Noise_Clk_Div_Enable();        
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_Stop
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
void Noise_Clk_Div_Stop(void) 
{
    /* Disable Counter */
    #if(!Noise_Clk_Div_ControlRegRemoved || Noise_Clk_Div_UsingFixedFunction)
        Noise_Clk_Div_CONTROL &= ((uint8)(~Noise_Clk_Div_CTRL_ENABLE));        
    #endif /* (!Noise_Clk_Div_ControlRegRemoved || Noise_Clk_Div_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Noise_Clk_Div_UsingFixedFunction)
        Noise_Clk_Div_GLOBAL_ENABLE &= ((uint8)(~Noise_Clk_Div_BLOCK_EN_MASK));
        Noise_Clk_Div_GLOBAL_STBY_ENABLE &= ((uint8)(~Noise_Clk_Div_BLOCK_STBY_EN_MASK));
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_SetInterruptMode
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
void Noise_Clk_Div_SetInterruptMode(uint8 interruptsMask) 
{
    Noise_Clk_Div_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_ReadStatusRegister
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
uint8   Noise_Clk_Div_ReadStatusRegister(void) 
{
    return Noise_Clk_Div_STATUS;
}


#if(!Noise_Clk_Div_ControlRegRemoved)
/*******************************************************************************
* Function Name: Noise_Clk_Div_ReadControlRegister
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
uint8   Noise_Clk_Div_ReadControlRegister(void) 
{
    return Noise_Clk_Div_CONTROL;
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_WriteControlRegister
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
void    Noise_Clk_Div_WriteControlRegister(uint8 control) 
{
    Noise_Clk_Div_CONTROL = control;
}

#endif  /* (!Noise_Clk_Div_ControlRegRemoved) */


#if (!(Noise_Clk_Div_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Noise_Clk_Div_WriteCounter
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
void Noise_Clk_Div_WriteCounter(uint16 counter) \
                                   
{
    #if(Noise_Clk_Div_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (Noise_Clk_Div_GLOBAL_ENABLE & Noise_Clk_Div_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Noise_Clk_Div_GLOBAL_ENABLE |= Noise_Clk_Div_BLOCK_EN_MASK;
        CY_SET_REG16(Noise_Clk_Div_COUNTER_LSB_PTR, (uint16)counter);
        Noise_Clk_Div_GLOBAL_ENABLE &= ((uint8)(~Noise_Clk_Div_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(Noise_Clk_Div_COUNTER_LSB_PTR, counter);
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */
}
#endif /* (!(Noise_Clk_Div_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Noise_Clk_Div_ReadCounter
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
uint16 Noise_Clk_Div_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Noise_Clk_Div_UsingFixedFunction)
		(void)CY_GET_REG16(Noise_Clk_Div_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(Noise_Clk_Div_COUNTER_LSB_PTR_8BIT);
	#endif/* (Noise_Clk_Div_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Noise_Clk_Div_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Noise_Clk_Div_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(Noise_Clk_Div_STATICCOUNT_LSB_PTR));
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_ReadCapture
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
uint16 Noise_Clk_Div_ReadCapture(void) 
{
    #if(Noise_Clk_Div_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Noise_Clk_Div_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(Noise_Clk_Div_STATICCOUNT_LSB_PTR));
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_WritePeriod
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
void Noise_Clk_Div_WritePeriod(uint16 period) 
{
    #if(Noise_Clk_Div_UsingFixedFunction)
        CY_SET_REG16(Noise_Clk_Div_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(Noise_Clk_Div_PERIOD_LSB_PTR, period);
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_ReadPeriod
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
uint16 Noise_Clk_Div_ReadPeriod(void) 
{
    #if(Noise_Clk_Div_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Noise_Clk_Div_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(Noise_Clk_Div_PERIOD_LSB_PTR));
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */
}


#if (!Noise_Clk_Div_UsingFixedFunction)
/*******************************************************************************
* Function Name: Noise_Clk_Div_WriteCompare
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
void Noise_Clk_Div_WriteCompare(uint16 compare) \
                                   
{
    #if(Noise_Clk_Div_UsingFixedFunction)
        CY_SET_REG16(Noise_Clk_Div_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(Noise_Clk_Div_COMPARE_LSB_PTR, compare);
    #endif /* (Noise_Clk_Div_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Noise_Clk_Div_ReadCompare
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
uint16 Noise_Clk_Div_ReadCompare(void) 
{
    return (CY_GET_REG16(Noise_Clk_Div_COMPARE_LSB_PTR));
}


#if (Noise_Clk_Div_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Noise_Clk_Div_SetCompareMode
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
void Noise_Clk_Div_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Noise_Clk_Div_CONTROL &= ((uint8)(~Noise_Clk_Div_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    Noise_Clk_Div_CONTROL |= compareMode;
}
#endif  /* (Noise_Clk_Div_COMPARE_MODE_SOFTWARE) */


#if (Noise_Clk_Div_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Noise_Clk_Div_SetCaptureMode
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
void Noise_Clk_Div_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Noise_Clk_Div_CONTROL &= ((uint8)(~Noise_Clk_Div_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    Noise_Clk_Div_CONTROL |= ((uint8)((uint8)captureMode << Noise_Clk_Div_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (Noise_Clk_Div_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Noise_Clk_Div_ClearFIFO
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
void Noise_Clk_Div_ClearFIFO(void) 
{

    while(0u != (Noise_Clk_Div_ReadStatusRegister() & Noise_Clk_Div_STATUS_FIFONEMP))
    {
        (void)Noise_Clk_Div_ReadCapture();
    }

}
#endif  /* (!Noise_Clk_Div_UsingFixedFunction) */


/* [] END OF FILE */

