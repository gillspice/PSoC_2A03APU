/*******************************************************************************
* File Name: LFSR_PM.c
* Version 2.40
*
* Description:
*  This file provides Sleep APIs for PRS component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "LFSR.h"

#if ((LFSR_TIME_MULTIPLEXING_ENABLE) && (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK))
    uint8 LFSR_sleepState = LFSR_NORMAL_SEQUENCE;    
#endif  /* End ((LFSR_TIME_MULTIPLEXING_ENABLE) && 
          (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)) */


/*******************************************************************************
* Function Name: LFSR_SaveConfig
********************************************************************************
*
* Summary:
*  Saves seed and polynomial registers.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global Variables:
*  LFSR_backup - modified when non-retention registers are saved.
*
*******************************************************************************/
void LFSR_SaveConfig(void) 
{    
    #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
        /* Save dff register for time mult */
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)
            LFSR_backup.dffStatus = LFSR_STATUS;
            /* Clear normal dff sequence set */
            LFSR_sleepState &= ((uint8)~LFSR_NORMAL_SEQUENCE);
        #endif  /* End LFSR_TIME_MULTIPLEXING_ENABLE */
        
        /* Save A0 and A1 registers */
        #if (LFSR_PRS_SIZE <= 32u)
            LFSR_backup.seed = LFSR_Read();
            
        #else
            LFSR_backup.seedUpper = LFSR_ReadUpper();
            LFSR_backup.seedLower = LFSR_ReadLower();
            
        #endif     /* End (LFSR_PRS_SIZE <= 32u) */
        
    #endif  /* End (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
}


/*******************************************************************************
* Function Name: LFSR_Sleep
********************************************************************************
*
* Summary:
*  Stops PRS computation and saves PRS configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global Variables:
*  LFSR_backup - modified when non-retention registers are saved.
*
*******************************************************************************/
void LFSR_Sleep(void) 
{
    /* Store PRS enable state */
    if(LFSR_IS_PRS_ENABLE(LFSR_CONTROL_REG))
    {
        LFSR_backup.enableState = 1u;
        LFSR_Stop();
    }
    else
    {
        LFSR_backup.enableState = 0u;
    }
    
    LFSR_SaveConfig();
}


/*******************************************************************************
* Function Name: LFSR_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores seed and polynomial registers.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
#if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
    #if (LFSR_TIME_MULTIPLEXING_ENABLE)
        void LFSR_RestoreConfig(void) 
        {   
            /* Restore A0 and A1 registers */
            #if (LFSR_PRS_SIZE <= 32u)
                LFSR_WriteSeed(LFSR_backup.seed);
            #else
                LFSR_WriteSeedUpper(LFSR_backup.seedUpper);
                LFSR_WriteSeedLower(LFSR_backup.seedLower);
            #endif  /* End (LFSR_PRS_SIZE <= 32u) */
            
            #if (LFSR_RUN_MODE == LFSR__CLOCKED)
                #if (LFSR_PRS_SIZE <= 32u)
                    LFSR_ResetSeedInit(LFSR_DEFAULT_SEED);                        
                #else
                    LFSR_ResetSeedInitUpper(LFSR_DEFAULT_SEED_UPPER);
                    LFSR_ResetSeedInitLower(LFSR_DEFAULT_SEED_LOWER); 
                #endif  /* End (LFSR_PRS_SIZE <= 32u) */ 
            #endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */
            
            /* Restore dff state for time mult: use async set/reest */
            /* Set CI, SI, SO, STATE0, STATE1 */
            LFSR_CONTROL_REG = LFSR_backup.dffStatus;
            
            /* Make pulse, to set trigger to defined state */
            LFSR_EXECUTE_DFF_SET;
            
            /* Set normal dff sequence set */
            LFSR_sleepState |= LFSR_NORMAL_SEQUENCE;
        }
        
    #else
        void LFSR_RestoreConfig(void) 
        {   
            /* Restore A0 and A1 registers */
            #if (LFSR_PRS_SIZE <= 32u)
                LFSR_WriteSeed(LFSR_backup.seed);
            #else
                LFSR_WriteSeedUpper(LFSR_backup.seedUpper);
                LFSR_WriteSeedLower(LFSR_backup.seedLower);
            #endif  /* End (LFSR_PRS_SIZE <= 32u) */
            
            #if (LFSR_RUN_MODE == LFSR__CLOCKED)
                #if (LFSR_PRS_SIZE <= 32u)
                    LFSR_ResetSeedInit(LFSR_DEFAULT_SEED);                        
                #else
                    LFSR_ResetSeedInitUpper(LFSR_DEFAULT_SEED_UPPER);
                    LFSR_ResetSeedInitLower(LFSR_DEFAULT_SEED_LOWER); 
                #endif  /* End (LFSR_PRS_SIZE <= 32u) */ 
            #endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */
        }
        
    #endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */
    
#else
    void LFSR_RestoreConfig(void) 
    {
        LFSR_Init();
    }
    
#endif  /* End (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */


/*******************************************************************************
* Function Name: LFSR_Wakeup
********************************************************************************
*
* Summary:
*  Restores PRS configuration and starts PRS computation. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
#if ((LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) && (LFSR_TIME_MULTIPLEXING_ENABLE))
    void LFSR_Wakeup(void) 
#else
    void LFSR_Wakeup(void) 
#endif  /* End ((LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) && 
                (LFSR_TIME_MULTIPLEXING_ENABLE)) */
{
    LFSR_RestoreConfig();
    
    /* Restore PRS enable state */
    if (LFSR_backup.enableState != 0u)
    {
        LFSR_Enable();
    }
}

/* [] END OF FILE */
