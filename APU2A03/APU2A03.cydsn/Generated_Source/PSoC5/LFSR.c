/*******************************************************************************
* File Name: LFSR.c
* Version 2.40
*
* Description:
*  This file provides the source code to the API for the PRS component
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

uint8 LFSR_initVar = 0u;

LFSR_BACKUP_STRUCT LFSR_backup =
{
    0x00u, /* enableState; */

    #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
        /* Save dff register for time mult */
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)
            LFSR_INIT_STATE, /* dffStatus; */
        #endif  /* End LFSR_TIME_MULTIPLEXING_ENABLE */

        /* Save A0 and A1 registers are none-retention */
        #if(LFSR_PRS_SIZE <= 32u)
            LFSR_DEFAULT_SEED, /* seed */

        #else
            LFSR_DEFAULT_SEED_UPPER, /* seedUpper; */
            LFSR_DEFAULT_SEED_LOWER, /* seedLower; */

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

    #endif  /* End (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
};


/*******************************************************************************
* Function Name: LFSR_Init
********************************************************************************
*
* Summary:
*  Initializes seed and polynomial registers with initial values.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void LFSR_Init(void) 
{
    /* Writes seed value and ponynom value provided for customizer */
    #if (LFSR_PRS_SIZE <= 32u)
        LFSR_WritePolynomial(LFSR_DEFAULT_POLYNOM);
        LFSR_WriteSeed(LFSR_DEFAULT_SEED);
        #if (LFSR_RUN_MODE == LFSR__CLOCKED)
            LFSR_ResetSeedInit(LFSR_DEFAULT_SEED);
        #endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */
            LFSR_Enable();
    #else
        LFSR_WritePolynomialUpper(LFSR_DEFAULT_POLYNOM_UPPER);
        LFSR_WritePolynomialLower(LFSR_DEFAULT_POLYNOM_LOWER);
        LFSR_WriteSeedUpper(LFSR_DEFAULT_SEED_UPPER);
        LFSR_WriteSeedLower(LFSR_DEFAULT_SEED_LOWER);
        #if (LFSR_RUN_MODE == LFSR__CLOCKED)
            LFSR_ResetSeedInitUpper(LFSR_DEFAULT_SEED_UPPER);
            LFSR_ResetSeedInitLower(LFSR_DEFAULT_SEED_LOWER);
        #endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */
            LFSR_Enable();
    #endif  /* End (LFSR_PRS_SIZE <= 32u) */
}


/*******************************************************************************
* Function Name: LFSR_Enable
********************************************************************************
*
* Summary:
*  Starts PRS computation on rising edge of input clock.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void LFSR_Enable(void) 
{
        LFSR_CONTROL_REG |= LFSR_CTRL_ENABLE;
}


/*******************************************************************************
* Function Name: LFSR_Start
********************************************************************************
*
* Summary:
*  Initializes seed and polynomial registers with initial values. Computation
*  of PRS starts on rising edge of input clock.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  LFSR_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time LFSR_Start() is called. This allows
*  enable/disable component without re-initialization in all subsequent calls
*  to the LFSR_Start() routine.
*
*******************************************************************************/
void LFSR_Start(void) 
{
    /* Writes seed value and ponynom value provided from customizer */
    if (LFSR_initVar == 0u)
    {
        LFSR_Init();
        LFSR_initVar = 1u;
    }

    LFSR_Enable();
}


/*******************************************************************************
* Function Name: LFSR_Stop
********************************************************************************
*
* Summary:
*  Stops PRS computation.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void LFSR_Stop(void) 
{
    LFSR_CONTROL_REG &= ((uint8)~LFSR_CTRL_ENABLE);
}


#if (LFSR_RUN_MODE == LFSR__APISINGLESTEP)
    /*******************************************************************************
    * FUNCTION NAME: LFSR_Step
    ********************************************************************************
    *
    * Summary:
    *  Increments the PRS by one when API single step mode is used.
    *
    * Parameters:
    *  void
    *
    * Return:
    *  void
    *
    *******************************************************************************/
    void LFSR_Step(void) 
    {
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)
            /* Makes 4 pulse, 4x for Time Mult */
            LFSR_EXECUTE_STEP;
            LFSR_EXECUTE_STEP;
            LFSR_EXECUTE_STEP;
            LFSR_EXECUTE_STEP;

        #else
            /* One pulse without Time mult required */
            LFSR_EXECUTE_STEP;

        #endif  /* End LFSR_TIME_MULTIPLEXING_ENABLE */
    }
#endif  /* End (LFSR_RUN_MODE == LFSR__APISINGLESTEP) */


#if (LFSR_RUN_MODE == LFSR__CLOCKED)
    #if (LFSR_PRS_SIZE <= 32u) /* 8-32 bits PRS */
        /*******************************************************************************
        * FUNCTION NAME: LFSR_ResetSeedInit
        ********************************************************************************
        *
        * Summary:
        *  Increments the PRS by one when API single step mode is used.
        *
        * Parameters:
        *  void
        *
        * Return:
        *  void
        *
        *******************************************************************************/
        void LFSR_ResetSeedInit(uint16 seed)
                                            
        {
            uint8 enableInterrupts;

            /* Mask the Seed to cut unused bits */
            seed &= LFSR_MASK;

            /* Change AuxControl reg, need to be safety */
            enableInterrupts = CyEnterCriticalSection();

            #if (LFSR_TIME_MULTIPLEXING_ENABLE)
                /* Set FIFOs to single register */
                LFSR_AUX_CONTROL_A_REG |= LFSR_AUXCTRL_FIFO_SINGLE_REG;

                #if(LFSR_PRS_SIZE > 16u)       /* 17-32 bits PRS */
                    LFSR_AUX_CONTROL_B_REG |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
                #endif  /* End (LFSR_PRS_SIZE <= 8u) */

                /* AuxControl reg settings are done */
                CyExitCriticalSection(enableInterrupts);

                /* Write Seed COPY */
                #if (LFSR_PRS_SIZE <= 16u)          /* 16 bits PRS */
                    LFSR_SEED_COPY_A__A1_REG = HI8(seed);
                    LFSR_SEED_COPY_A__A0_REG = LO8(seed);

                #elif (LFSR_PRS_SIZE <= 24u)        /* 24 bits PRS */
                    LFSR_SEED_COPY_B__A1_REG = LO8(HI16(seed));
                    LFSR_SEED_COPY_B__A0_REG = HI8(seed);
                    LFSR_SEED_COPY_A__A0_REG = LO8(seed);

                #else                                           /* 32 bits PRS */
                    LFSR_SEED_COPY_B__A1_REG = HI8(HI16(seed));
                    LFSR_SEED_COPY_A__A1_REG = LO8(HI16(seed));
                    LFSR_SEED_COPY_B__A0_REG = HI8(seed);
                    LFSR_SEED_COPY_A__A0_REG = LO8(seed);
                #endif  /* End (LFSR_PRS_SIZE <= 32u) */

            #else
                /* Set FIFOs to single register */
                #if (LFSR_PRS_SIZE <= 8u)      /* 8 bits PRS */
                    LFSR_AUX_CONTROL_A_REG |= LFSR_AUXCTRL_FIFO_SINGLE_REG;

                #elif (LFSR_PRS_SIZE <= 16u)      /* 16 bits PRS */
                    LFSR_AUX_CONTROL_A_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
                    LFSR_AUX_CONTROL_B_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;

                #elif (LFSR_PRS_SIZE <= 24u)      /* 24-39 bits PRS */
                    LFSR_AUX_CONTROL_A_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
                    LFSR_AUX_CONTROL_B_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
                    LFSR_AUX_CONTROL_C_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;

                #elif (LFSR_PRS_SIZE <= 32u)      /* 40-55 bits PRS */
                    LFSR_AUX_CONTROL_A_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
                    LFSR_AUX_CONTROL_B_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
                    LFSR_AUX_CONTROL_C_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
                    LFSR_AUX_CONTROL_D_REG  |= LFSR_AUXCTRL_FIFO_SINGLE_REG;

                #endif  /* End (LFSR_PRS_SIZE <= 8u) */

                /* AuxControl reg setting are done */
                CyExitCriticalSection(enableInterrupts);

                /* Write Seed COPY */
                CY_SET_REG16(LFSR_SEED_COPY_PTR, seed);

            #endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */
        }

    #else

        /*******************************************************************************
        * FUNCTION NAME: LFSR_ResetSeedInitUpper
        ********************************************************************************
        *
        * Summary:
        *  Increments the PRS by one when API single step mode is used.
        *
        * Parameters:
        *  void
        *
        * Return:
        *  void
        *
        *******************************************************************************/
        void LFSR_ResetSeedInitUpper(uint32 seed) 
        {
			uint8 enableInterrupts;

			/* Mask the Seed Upper half to cut unused bits */
            seed &= LFSR_MASK;

			/* Change AuxControl reg, need to be safety */
            enableInterrupts = CyEnterCriticalSection();

            /* Set FIFOs to single register */
            LFSR_AUX_CONTROL_A_REG |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
            LFSR_AUX_CONTROL_B_REG |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
            LFSR_AUX_CONTROL_C_REG |= LFSR_AUXCTRL_FIFO_SINGLE_REG;

			#if (LFSR_PRS_SIZE > 48u)               /* 49-64 bits PRS */
                LFSR_AUX_CONTROL_D_REG |= LFSR_AUXCTRL_FIFO_SINGLE_REG;
            #endif  /* End (LFSR_PRS_SIZE <= 8u) */

            /* AuxControl reg settings are done */
            CyExitCriticalSection(enableInterrupts);

            /* Write Seed Upper COPY */
            #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
                LFSR_SEED_UPPER_COPY_C__A1_REG = LO8(seed);

            #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
                LFSR_SEED_UPPER_COPY_C__A1_REG = HI8(seed);
                LFSR_SEED_UPPER_COPY_B__A1_REG = LO8(seed);

            #elif (LFSR_PRS_SIZE <= 56u)        /* 56 bits PRS */
                LFSR_SEED_UPPER_COPY_D__A1_REG = LO8(HI16(seed));
                LFSR_SEED_UPPER_COPY_C__A1_REG = HI8(seed);
                LFSR_SEED_UPPER_COPY_B__A1_REG = HI8(seed);

            #else                                           /* 64 bits PRS */
                LFSR_SEED_UPPER_COPY_D__A1_REG = HI8(HI16(seed));
                LFSR_SEED_UPPER_COPY_C__A1_REG = LO8(HI16(seed));
                LFSR_SEED_UPPER_COPY_B__A1_REG = HI8(seed);
                LFSR_SEED_UPPER_COPY_A__A1_REG = LO8(seed);

            #endif  /* End (LFSR_PRS_SIZE <= 32u) */
        }


        /*******************************************************************************
        * FUNCTION NAME: LFSR_ResetSeedInitLower
        ********************************************************************************
        *
        * Summary:
        *  Increments the PRS by one when API single step mode is used.
        *
        * Parameters:
        *  void
        *
        * Return:
        *  void
        *
        *******************************************************************************/
        void LFSR_ResetSeedInitLower(uint32 seed) 
        {
            /* Write Seed Lower COPY */
            #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
                LFSR_SEED_LOWER_COPY_B__A1_REG = HI8(HI16(seed));
                LFSR_SEED_LOWER_COPY_C__A0_REG = LO8(HI16(seed));
                LFSR_SEED_LOWER_COPY_B__A0_REG = HI8(seed);
                LFSR_SEED_LOWER_COPY_A__A0_REG = LO8(seed);

            #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
                LFSR_SEED_LOWER_COPY_A__A1_REG = HI8(HI16(seed));
                LFSR_SEED_LOWER_COPY_C__A0_REG = LO8(HI16(seed));
                LFSR_SEED_LOWER_COPY_B__A0_REG = HI8(seed);
                LFSR_SEED_LOWER_COPY_A__A0_REG = LO8(seed);

            #else                                           /* 64 bits PRS */
                LFSR_SEED_LOWER_COPY_D__A0_REG = HI8(HI16(seed));
                LFSR_SEED_LOWER_COPY_C__A0_REG = LO8(HI16(seed));
                LFSR_SEED_LOWER_COPY_B__A0_REG = HI8(seed);
                LFSR_SEED_LOWER_COPY_A__A0_REG = LO8(seed);

            #endif  /* End (LFSR_PRS_SIZE <= 32u) */
        }

    #endif  /* End (LFSR_PRS_SIZE <= 32u) */

#endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */


#if(LFSR_PRS_SIZE <= 32u) /* 8-32 bits PRS */
    /*******************************************************************************
    * Function Name: LFSR_Read
    ********************************************************************************
    *
    * Summary:
    *  Reads PRS value.
    *
    * Parameters:
    *  void
    *
    * Return:
    *  Returns PRS value.
    *
    * Side Effects:
    *  The seed value is cut according to mask = 2^(Resolution) - 1.
    *  For example if PRS Resolution is 14 bits the mask value is:
    *  mask = 2^(14) - 1 = 0x3FFFu.
    *  The seed value = 0xFFFFu is cut:
    *  seed & mask = 0xFFFFu & 0x3FFFu = 0x3FFFu.
    *
    *******************************************************************************/
    uint16 LFSR_Read(void) 
    {
        /* Read PRS */
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)

            uint16 seed;

            #if (LFSR_PRS_SIZE <= 16u)          /* 16 bits PRS */
                seed = ((uint16) LFSR_SEED_A__A1_REG) << 8u;
                seed |= LFSR_SEED_A__A0_REG;

            #elif (LFSR_PRS_SIZE <= 24u)        /* 24 bits PRS */
                seed = ((uint32) (LFSR_SEED_B__A1_REG)) << 16u;
                seed |= ((uint32) (LFSR_SEED_B__A0_REG)) << 8u;
                seed |= LFSR_SEED_A__A0_REG;

            #else                                           /* 32 bits PRS */
                seed = ((uint32) LFSR_SEED_B__A1_REG) << 24u;
                seed |= ((uint32) LFSR_SEED_A__A1_REG) << 16u;
                seed |= ((uint32) LFSR_SEED_B__A0_REG) << 8u;
                seed |= LFSR_SEED_A__A0_REG;

            #endif  /* End (LFSR_PRS_SIZE <= 8u) */

            return (seed  & LFSR_MASK);

        #else

            return (CY_GET_REG16(LFSR_SEED_PTR) & LFSR_MASK);

        #endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */
    }


    /*******************************************************************************
    * Function Name: LFSR_WriteSeed
    ********************************************************************************
    *
    * Summary:
    *  Writes seed value.
    *
    * Parameters:
    *  seed:  Seed value.
    *
    * Return:
    *  void
    *
    * Side Effects:
    *  The seed value is cut according to mask = 2^(Resolution) - 1.
    *  For example if PRS Resolution is 14 bits the mask value is:
    *  mask = 2^(14) - 1 = 0x3FFFu.
    *  The seed value = 0xFFFFu is cut:
    *  seed & mask = 0xFFFFu & 0x3FFFu = 0x3FFFu.
    *
    *******************************************************************************/
    void LFSR_WriteSeed(uint16 seed) 
    {
        /* Masks the Seed to cut unused bits */
        seed &= LFSR_MASK;

        /* Writes Seed */
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)

            #if (LFSR_PRS_SIZE <= 16u)          /* 16 bits PRS */
                LFSR_SEED_A__A1_REG = HI8(seed);
                LFSR_SEED_A__A0_REG = LO8(seed);

            #elif (LFSR_PRS_SIZE <= 24u)        /* 24 bits PRS */
                LFSR_SEED_B__A1_REG = LO8(HI16(seed));
                LFSR_SEED_B__A0_REG = HI8(seed);
                LFSR_SEED_A__A0_REG = LO8(seed);

            #else                                           /* 32 bits PRS */
                LFSR_SEED_B__A1_REG = HI8(HI16(seed));
                LFSR_SEED_A__A1_REG = LO8(HI16(seed));
                LFSR_SEED_B__A0_REG = HI8(seed);
                LFSR_SEED_A__A0_REG = LO8(seed);
            #endif  /* End (LFSR_PRS_SIZE <= 32u) */

            /* Resets triggers */
            #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
                if((LFSR_sleepState & LFSR_NORMAL_SEQUENCE) != 0u)
                {
                    LFSR_EXECUTE_DFF_RESET;
                }
            #else
                LFSR_EXECUTE_DFF_RESET;
            #endif  /* (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */

        #else

            CY_SET_REG16(LFSR_SEED_PTR, seed);

        #endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */
    }


    /*******************************************************************************
    * Function Name: LFSR_ReadPolynomial
    ********************************************************************************
    *
    * Summary:
    *  Reads PRS polynomial value.
    *
    * Parameters:
    *  void
    *
    * Return:
    *  Returns PRS polynomial value.
    *
    *******************************************************************************/
    uint16 LFSR_ReadPolynomial(void)
                                
    {
        /* Reads polynomial */
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)

            uint16 polynomial;

            #if (LFSR_PRS_SIZE <= 16u)          /* 16 bits PRS */
                polynomial = ((uint16) LFSR_POLYNOM_A__D1_REG) << 8u;
                polynomial |= (LFSR_POLYNOM_A__D0_REG);

            #elif (LFSR_PRS_SIZE <= 24u)        /* 24 bits PRS */
                polynomial = ((uint32) LFSR_POLYNOM_B__D1_REG) << 16u;
                polynomial |= ((uint32) LFSR_POLYNOM_B__D0_REG) << 8u;
                polynomial |= LFSR_POLYNOM_A__D0_REG;

            #else                                           /* 32 bits PRS */
                polynomial = ((uint32) LFSR_POLYNOM_B__D1_REG) << 24u;
                polynomial |= ((uint32) LFSR_POLYNOM_A__D1_REG) << 16u;
                polynomial |= ((uint32) LFSR_POLYNOM_B__D0_REG) << 8u;
                polynomial |= LFSR_POLYNOM_A__D0_REG;

            #endif  /* End (LFSR_PRS_SIZE <= 32u) */

            return polynomial;

        #else

            return CY_GET_REG16(LFSR_POLYNOM_PTR);

        #endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */
    }


    /*******************************************************************************
    * Function Name: LFSR_WritePolynomial
    ********************************************************************************
    *
    * Summary:
    *  Writes PRS polynomial value.
    *
    * Parameters:
    *  polynomial:  PRS polynomial.
    *
    * Return:
    *  void
    *
    * Side Effects:
    *  The polynomial value is cut according to mask = 2^(Resolution) - 1.
    *  For example if PRS Resolution is 14 bits the mask value is:
    *  mask = 2^(14) - 1 = 0x3FFFu.
    *  The polynomial value = 0xFFFFu is cut:
    *  polynomial & mask = 0xFFFFu & 0x3FFFu = 0x3FFFu.
    *
    *******************************************************************************/
    void LFSR_WritePolynomial(uint16 polynomial)
                                          
    {
        /* Mask polynomial to cut unused bits */
        polynomial &= LFSR_MASK;

        /* Write polynomial */
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)

            #if (LFSR_PRS_SIZE <= 16u)          /* 16 bits PRS */

                LFSR_POLYNOM_A__D1_REG = HI8(polynomial);
                LFSR_POLYNOM_A__D0_REG = LO8(polynomial);

            #elif (LFSR_PRS_SIZE <= 24u)        /* 24 bits PRS */
                LFSR_POLYNOM_B__D1_REG = LO8(HI16(polynomial));
                LFSR_POLYNOM_B__D0_REG = HI8(polynomial);
                LFSR_POLYNOM_A__D0_REG = LO8(polynomial);

            #else                                           /* 32 bits PRS */
                LFSR_POLYNOM_B__D1_REG = HI8(HI16(polynomial));
                LFSR_POLYNOM_A__D1_REG = LO8(HI16(polynomial));
                LFSR_POLYNOM_B__D0_REG = HI8(polynomial);
                LFSR_POLYNOM_A__D0_REG = LO8(polynomial);

            #endif  /* End (LFSR_PRS_SIZE <= 32u) */

            /* Resets triggers */
            #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
                if((LFSR_sleepState & LFSR_NORMAL_SEQUENCE) != 0u)
                {
                    LFSR_EXECUTE_DFF_RESET;
                }
            #else
                LFSR_EXECUTE_DFF_RESET;
            #endif  /* (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */

        #else

            CY_SET_REG16(LFSR_POLYNOM_PTR, polynomial);

        #endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */
    }

#else   /* 33-64 bits PRS */

    /*******************************************************************************
    *  Function Name: LFSR_ReadUpper
    ********************************************************************************
    *
    * Summary:
    *  Reads upper half of PRS value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  void
    *
    * Return:
    *  Returns upper half of PRS value.
    *
    * Side Effects:
    *  The upper half of seed value is cut according to
    *  mask = 2^(Resolution - 32) - 1.
    *  For example if PRS Resolution is 35 bits the mask value is:
    *  2^(35 - 32) - 1 = 2^(3) - 1 = 0x0000 0007u.
    *  The upper half of seed value = 0x0000 00FFu is cut:
    *  upper half of seed & mask = 0x0000 00FFu & 0x0000 0007u = 0x0000 0007u.
    *
    *******************************************************************************/
    uint32 LFSR_ReadUpper(void) 
    {
        uint32 seed;

        /* Read PRS Upper */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            seed = LFSR_SEED_UPPER_C__A1_REG;

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            seed = ((uint32) LFSR_SEED_UPPER_C__A1_REG) << 8u;
            seed |= LFSR_SEED_UPPER_B__A1_REG;

        #elif (LFSR_PRS_SIZE <= 56u)        /* 56 bits PRS */
            seed = ((uint32) LFSR_SEED_UPPER_D__A1_REG) << 16u;
            seed |= ((uint32) LFSR_SEED_UPPER_C__A1_REG) << 8u;
            seed |= LFSR_SEED_UPPER_B__A1_REG;

        #else                                           /* 64 bits PRS */
            seed = ((uint32) LFSR_SEED_UPPER_D__A1_REG) << 24u;
            seed |= ((uint32) LFSR_SEED_UPPER_C__A1_REG) << 16u;
            seed |= ((uint32) LFSR_SEED_UPPER_B__A1_REG) << 8u;
            seed |= LFSR_SEED_UPPER_A__A1_REG;

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        return (seed & LFSR_MASK);
    }


    /*******************************************************************************
    *  Function Name: LFSR_ReadLower
    ********************************************************************************
    *
    * Summary:
    *  Reads lower half of PRS value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  void
    *
    * Return:
    *  Returns lower half of PRS value.
    *
    *******************************************************************************/
    uint32 LFSR_ReadLower(void) 
    {
        uint32 seed;

        /* Read PRS Lower */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            seed = ((uint32) LFSR_SEED_LOWER_B__A1_REG) << 24u;
            seed |= ((uint32) LFSR_SEED_LOWER_C__A0_REG) << 16u;
            seed |= ((uint32) LFSR_SEED_LOWER_B__A0_REG) << 8u;
            seed |= LFSR_SEED_LOWER_A__A0_REG;

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            seed = ((uint32) LFSR_SEED_LOWER_A__A1_REG) << 24u;
            seed |= ((uint32) LFSR_SEED_LOWER_C__A0_REG) << 16u;
            seed |= ((uint32) LFSR_SEED_LOWER_B__A0_REG) << 8u;
            seed |= LFSR_SEED_LOWER_A__A0_REG;

        #else                                           /* 64 bits PRS */
            seed = ((uint32) LFSR_SEED_LOWER_D__A0_REG) << 24u;
            seed |= ((uint32) LFSR_SEED_LOWER_C__A0_REG) << 16u;
            seed |= ((uint32) LFSR_SEED_LOWER_B__A0_REG) << 8u;
            seed |= LFSR_SEED_LOWER_A__A0_REG;

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        return seed;
    }


    /*******************************************************************************
    * Function Name: LFSR_WriteSeedUpper
    ********************************************************************************
    *
    * Summary:
    *  Writes upper half of seed value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  seed:  Upper half of seed value.
    *
    * Return:
    *  void
    *
    * Side Effects:
    *  The upper half of seed value is cut according to
    *  mask = 2^(Resolution - 32) - 1.
    *  For example if PRS Resolution is 35 bits the mask value is:
    *  2^(35 - 32) - 1 = 2^(3) - 1 = 0x0000 0007u.
    *  The upper half of seed value = 0x0000 00FFu is cut:
    *  upper half of seed & mask = 0x0000 00FFu & 0x0000 0007u = 0x0000 0007u.
    *
    *******************************************************************************/
    void LFSR_WriteSeedUpper(uint32 seed) 
    {
        /* Mask the Seed Upper half to cut unused bits */
        seed &= LFSR_MASK;

        /* Write Seed Upper */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            LFSR_SEED_UPPER_C__A1_REG = LO8(seed);

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            LFSR_SEED_UPPER_C__A1_REG = HI8(seed);
            LFSR_SEED_UPPER_B__A1_REG = LO8(seed);

        #elif (LFSR_PRS_SIZE <= 56u)        /* 56 bits PRS */
            LFSR_SEED_UPPER_D__A1_REG = LO8(HI16(seed));
            LFSR_SEED_UPPER_C__A1_REG = HI8(seed);
            LFSR_SEED_UPPER_B__A1_REG = HI8(seed);

        #else                                           /* 64 bits PRS */
            LFSR_SEED_UPPER_D__A1_REG = HI8(HI16(seed));
            LFSR_SEED_UPPER_C__A1_REG = LO8(HI16(seed));
            LFSR_SEED_UPPER_B__A1_REG = HI8(seed);
            LFSR_SEED_UPPER_A__A1_REG = LO8(seed);

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        /* Resets triggers */
        #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
            if((LFSR_sleepState & LFSR_NORMAL_SEQUENCE) != 0u)
            {
                LFSR_EXECUTE_DFF_RESET;
            }
        #else
            LFSR_EXECUTE_DFF_RESET;
        #endif  /* (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
    }


    /*******************************************************************************
    * Function Name: LFSR_WriteSeedLower
    ********************************************************************************
    *
    * Summary:
    *  Writes lower half of seed value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  seed:  Lower half of seed value.
    *
    * Return:
    *  void
    *
    *******************************************************************************/
    void LFSR_WriteSeedLower(uint32 seed) 
    {
        /* Write Seed Lower */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            LFSR_SEED_LOWER_B__A1_REG = HI8(HI16(seed));
            LFSR_SEED_LOWER_C__A0_REG = LO8(HI16(seed));
            LFSR_SEED_LOWER_B__A0_REG = HI8(seed);
            LFSR_SEED_LOWER_A__A0_REG = LO8(seed);

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            LFSR_SEED_LOWER_A__A1_REG = HI8(HI16(seed));
            LFSR_SEED_LOWER_C__A0_REG = LO8(HI16(seed));
            LFSR_SEED_LOWER_B__A0_REG = HI8(seed);
            LFSR_SEED_LOWER_A__A0_REG = LO8(seed);

        #else                                           /* 64 bits PRS */
            LFSR_SEED_LOWER_D__A0_REG = HI8(HI16(seed));
            LFSR_SEED_LOWER_C__A0_REG = LO8(HI16(seed));
            LFSR_SEED_LOWER_B__A0_REG = HI8(seed);
            LFSR_SEED_LOWER_A__A0_REG = LO8(seed);

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        /* Resets triggers */
        #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
            if((LFSR_sleepState & LFSR_NORMAL_SEQUENCE) != 0u)
            {
                LFSR_EXECUTE_DFF_RESET;
            }
        #else
            LFSR_EXECUTE_DFF_RESET;
        #endif  /* (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
    }


    /*******************************************************************************
    * Function Name: LFSR_ReadPolynomialUpper
    ********************************************************************************
    *
    * Summary:
    *  Reads upper half of PRS polynomial value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  void
    *
    * Return:
    *  Returns upper half of PRS polynomial value.
    *
    *******************************************************************************/
    uint32 LFSR_ReadPolynomialUpper(void) 
    {
        uint32 polynomial;

        /* Read Polynomial Upper */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            polynomial = LFSR_POLYNOM_UPPER_C__D1_REG;

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            polynomial = ((uint32) LFSR_POLYNOM_UPPER_C__D1_REG) << 8u;
            polynomial |= LFSR_POLYNOM_UPPER_B__D1_REG;

        #elif (LFSR_PRS_SIZE <= 56u)        /* 56 bits PRS */
            polynomial = ((uint32) LFSR_POLYNOM_UPPER_D__D1_REG) << 16u;
            polynomial |= ((uint32) LFSR_POLYNOM_UPPER_C__D1_REG) << 8u;
            polynomial |= LFSR_POLYNOM_UPPER_B__D1_REG;

        #else                                           /* 64 bits PRS */
            polynomial = ((uint32) LFSR_POLYNOM_UPPER_D__D1_REG) << 24u;
            polynomial |= ((uint32) LFSR_POLYNOM_UPPER_C__D1_REG) << 16u;
            polynomial |= ((uint32) LFSR_POLYNOM_UPPER_B__D1_REG) << 8u;
            polynomial |= LFSR_POLYNOM_UPPER_A__D1_REG;

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        return polynomial;
    }


    /*******************************************************************************
    * Function Name: LFSR_ReadPolynomialLower
    ********************************************************************************
    *
    * Summary:
    *  Reads lower half of PRS polynomial value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  void
    *
    * Return:
    *  Returns lower half of PRS polynomial value.
    *
    *******************************************************************************/
    uint32 LFSR_ReadPolynomialLower(void) 
    {
        uint32 polynomial;

        /* Read Polynomial Lower */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            polynomial = ( (uint32) LFSR_POLYNOM_LOWER_B__D1_REG) << 24u;
            polynomial |= ( (uint32) LFSR_POLYNOM_LOWER_C__D0_REG) << 16u;
            polynomial |= ( (uint32) LFSR_POLYNOM_LOWER_B__D0_REG) << 8u;
            polynomial |= LFSR_POLYNOM_LOWER_A__D0_REG;

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            polynomial = ((uint32) LFSR_POLYNOM_LOWER_A__D1_REG) << 24u;
            polynomial |= ((uint32) LFSR_POLYNOM_LOWER_C__D0_REG) << 16u;
            polynomial |= ((uint32) LFSR_POLYNOM_LOWER_B__D0_REG) << 8u;
            polynomial |= LFSR_POLYNOM_LOWER_A__D0_REG;

        #else                                           /* 64 bits PRS */
            polynomial = ((uint32) LFSR_POLYNOM_LOWER_D__D0_REG) << 24u;
            polynomial |= ((uint32) LFSR_POLYNOM_LOWER_C__D0_REG) << 16u;
            polynomial |= ((uint32) LFSR_POLYNOM_LOWER_B__D0_REG) << 8u;
            polynomial |= LFSR_POLYNOM_LOWER_A__D0_REG;

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        return polynomial;
    }


    /*******************************************************************************
    * Function Name: LFSR_WritePolynomialUpper
    ********************************************************************************
    *
    * Summary:
    *  Writes upper half of PRS polynomial value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  polynomial:  Upper half PRS polynomial value.
    *
    * Return:
    *  void
    *
    * Side Effects:
    *  The upper half of polynomial value is cut according to
    *  mask = 2^(Resolution - 32) - 1.
    *  For example if PRS Resolution is 35 bits the mask value is:
    *  2^(35 - 32) - 1 = 2^(3) - 1 = 0x0000 0007u.
    *  The upper half of polynomial value = 0x0000 00FFu is cut:
    *  upper half of polynomial & mask = 0x0000 00FFu & 0x0000 0007u = 0x0000 0007u.
    *
    *******************************************************************************/
    void LFSR_WritePolynomialUpper(uint32 polynomial)
                                                
    {
        /* Mask the polynomial upper half to cut unused bits */
        polynomial &= LFSR_MASK;

        /* Write Polynomial Upper */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            LFSR_POLYNOM_UPPER_C__D1_REG = LO8(polynomial);

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            LFSR_POLYNOM_UPPER_C__D1_REG = HI8(polynomial);
            LFSR_POLYNOM_UPPER_B__D1_REG = LO8(polynomial);

        #elif (LFSR_PRS_SIZE <= 56u)        /* 56 bits PRS */
            LFSR_POLYNOM_UPPER_D__D1_REG = LO8(HI16(polynomial));
            LFSR_POLYNOM_UPPER_C__D1_REG = HI8(polynomial);
            LFSR_POLYNOM_UPPER_B__D1_REG = LO8(polynomial);

        #else                                           /* 64 bits PRS */
            LFSR_POLYNOM_UPPER_D__D1_REG = HI8(HI16(polynomial));
            LFSR_POLYNOM_UPPER_C__D1_REG = LO8(HI16(polynomial));
            LFSR_POLYNOM_UPPER_B__D1_REG = HI8(polynomial);
            LFSR_POLYNOM_UPPER_A__D1_REG = LO8(polynomial);

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        /* Resets triggers */
        #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
            if((LFSR_sleepState & LFSR_NORMAL_SEQUENCE) != 0u)
            {
                LFSR_EXECUTE_DFF_RESET;
            }
        #else
            LFSR_EXECUTE_DFF_RESET;
        #endif  /* (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
    }


    /*******************************************************************************
    * Function Name: LFSR_WritePolynomialLower
    ********************************************************************************
    *
    * Summary:
    *  Writes lower half of PRS polynomial value. Only generated for 33-64-bit PRS.
    *
    * Parameters:
    *  polynomial:  Lower half of PRS polynomial value.
    *
    * Return:
    *  void
    *
    *******************************************************************************/
    void LFSR_WritePolynomialLower(uint32 polynomial)
                                                
    {
        /* Write Polynomial Lower */
        #if (LFSR_PRS_SIZE <= 40u)          /* 40 bits PRS */
            LFSR_POLYNOM_LOWER_B__D1_REG = HI8(HI16(polynomial));
            LFSR_POLYNOM_LOWER_C__D0_REG = LO8(HI16(polynomial));
            LFSR_POLYNOM_LOWER_B__D0_REG = HI8(polynomial);
            LFSR_POLYNOM_LOWER_A__D0_REG = LO8(polynomial);

        #elif (LFSR_PRS_SIZE <= 48u)        /* 48 bits PRS */
            LFSR_POLYNOM_LOWER_A__D1_REG = HI8(HI16(polynomial));
            LFSR_POLYNOM_LOWER_C__D0_REG = LO8(HI16(polynomial));
            LFSR_POLYNOM_LOWER_B__D0_REG = HI8(polynomial);
            LFSR_POLYNOM_LOWER_A__D0_REG = LO8(polynomial);

        #else                                           /* 64 bits PRS */
            LFSR_POLYNOM_LOWER_D__D0_REG = HI8(HI16(polynomial));
            LFSR_POLYNOM_LOWER_C__D0_REG = LO8(HI16(polynomial));
            LFSR_POLYNOM_LOWER_B__D0_REG = HI8(polynomial);
            LFSR_POLYNOM_LOWER_A__D0_REG = LO8(polynomial);

        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

        /* Resets triggers */
        #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
            if((LFSR_sleepState & LFSR_NORMAL_SEQUENCE) != 0u)
            {
                LFSR_EXECUTE_DFF_RESET;
            }
        #else
            LFSR_EXECUTE_DFF_RESET;
        #endif  /* (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
    }
#endif  /* End (LFSR_PRS_SIZE <= 32u) */


/* [] END OF FILE */
