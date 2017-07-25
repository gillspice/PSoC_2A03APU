/*******************************************************************************
* File Name: LFSR.h
* Version 2.40
*
* Description:
*  This file provides constants and parameter values for the PRS component.
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

#if !defined(CY_PRS_LFSR_H)
#define CY_PRS_LFSR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */

#if !defined (CY_PSOC5A)
    #error Component PRS_v2_40 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5A) */

#define LFSR_PRS_SIZE                   (14u)
#define LFSR_RUN_MODE                   (0u)
#define LFSR_TIME_MULTIPLEXING_ENABLE   (0u)
#define LFSR_WAKEUP_BEHAVIOUR           (1u)

#define LFSR__CLOCKED 0
#define LFSR__APISINGLESTEP 1


#define LFSR__RESUMEWORK 1
#define LFSR__STARTAFRESH 0



/***************************************
*       Type defines
***************************************/

/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    
    #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
        /* Save dff register for time mult */
        #if (LFSR_TIME_MULTIPLEXING_ENABLE)
            uint8 dffStatus;
        #endif  /* End LFSR_TIME_MULTIPLEXING_ENABLE */
    
        /* Save A0 and A1 registers are none-retention */
        #if(LFSR_PRS_SIZE <= 32u)
            uint16 seed;
            
        #else
            uint32 seedUpper;
            uint32 seedLower;
            
        #endif  /* End (LFSR_PRS_SIZE <= 32u) */ 
        
    #endif  /* End (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
    
} LFSR_BACKUP_STRUCT;

extern uint8 LFSR_initVar;

extern LFSR_BACKUP_STRUCT LFSR_backup;

#if ((LFSR_TIME_MULTIPLEXING_ENABLE) && (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK))
    extern uint8 LFSR_sleepState;
#endif  /* End ((LFSR_TIME_MULTIPLEXING_ENABLE) && 
          (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)) */

                                     
/***************************************
*        Function Prototypes
****************************************/

void LFSR_Init(void) ;
void LFSR_Enable(void) ;
void LFSR_Start(void) ;
void LFSR_Stop(void) ;
void LFSR_SaveConfig(void) ;
void LFSR_Sleep(void) ;


#if ((LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) && (LFSR_TIME_MULTIPLEXING_ENABLE))
    void LFSR_RestoreConfig(void) ;
    void LFSR_Wakeup(void) ;
#else
    void LFSR_RestoreConfig(void) ;
    void LFSR_Wakeup(void) ;
#endif  /* End ((LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) && 
                (LFSR_TIME_MULTIPLEXING_ENABLE)) */

#if (LFSR_RUN_MODE == LFSR__APISINGLESTEP)
    void LFSR_Step(void) ;
#endif  /* End (LFSR_RUN_MODE == LFSR__APISINGLESTEP) */

#if (LFSR_PRS_SIZE <= 32u)    /* 8-32 bits PRS */
    uint16 LFSR_Read(void) ;
    void LFSR_WriteSeed(uint16 seed)  ;
    uint16 LFSR_ReadPolynomial(void) 
                                ;
    void LFSR_WritePolynomial(uint16 polynomial) 
                                          ;
    
#else                                    /* 33-64 bits PRS */
    uint32 LFSR_ReadUpper(void) ;
    uint32 LFSR_ReadLower(void) ;
    void LFSR_WriteSeedUpper(uint32 seed) ;
    void LFSR_WriteSeedLower(uint32 seed) ;
    uint32 LFSR_ReadPolynomialUpper(void) ;
    uint32 LFSR_ReadPolynomialLower(void) ;
    void LFSR_WritePolynomialUpper(uint32 polynomial) 
                                                ;
    void LFSR_WritePolynomialLower(uint32 polynomial) 
                                                ;
    
#endif  /* End (LFSR_PRS_SIZE <= 32u) */

#if (LFSR_RUN_MODE == LFSR__CLOCKED)
    #if (LFSR_PRS_SIZE <= 32u) /* 8-32 bits PRS */
        void LFSR_ResetSeedInit(uint16 seed)  
                                            ;
    #else
        void LFSR_ResetSeedInitUpper(uint32 seed) ;
        void LFSR_ResetSeedInitLower(uint32 seed) ;
    #endif  /* End (LFSR_PRS_SIZE <= 32u) */
#endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */


/***************************************
*    Initial Parameter Constants
***************************************/

#if (LFSR_PRS_SIZE <= 32u)
    #define LFSR_DEFAULT_POLYNOM            (0x3500u)
    #define LFSR_DEFAULT_SEED               (0x3FFFu)
    
#else
    #define LFSR_DEFAULT_POLYNOM_UPPER      (0x0u)
    #define LFSR_DEFAULT_POLYNOM_LOWER      (0x3500u)
    #define LFSR_DEFAULT_SEED_UPPER         (0x0u)
    #define LFSR_DEFAULT_SEED_LOWER         (0x3FFFu)
    
#endif  /* End (LFSR_PRS_SIZE <= 32u) */


/***************************************
*           API Constants
***************************************/

#define LFSR_MASK                           (0x3FFFu)


/***************************************
*             Registers
***************************************/


#if (LFSR_RUN_MODE == LFSR__CLOCKED)
    #define LFSR_EXECUTE_DFF_RESET  \
        (LFSR_CONTROL_REG |= (LFSR_INIT_STATE | LFSR_CTRL_RESET_COMMON))
    
    #define LFSR_EXECUTE_DFF_SET    \
        (LFSR_CONTROL_REG |= LFSR_CTRL_RESET_COMMON)

#else
    #define LFSR_EXECUTE_DFF_RESET  \
        do { \
            LFSR_CONTROL_REG |= (LFSR_INIT_STATE | LFSR_CTRL_RESET_COMMON | \
            LFSR_CTRL_RISING_EDGE );  \
            LFSR_CONTROL_REG &= ((uint8)~(LFSR_CTRL_RESET_COMMON | \
            LFSR_CTRL_RISING_EDGE));    \
        } while (0)
    
    #define LFSR_EXECUTE_DFF_SET    \
        do { \
            LFSR_CONTROL_REG |= (LFSR_CTRL_RESET_COMMON | \
            LFSR_CTRL_RISING_EDGE);\
            LFSR_CONTROL_REG &= ((uint8)~(LFSR_CTRL_RESET_COMMON | \
            LFSR_CTRL_RISING_EDGE));    \
        } while (0)

    #define LFSR_EXECUTE_STEP       \
        do { \
            LFSR_CONTROL_REG |= LFSR_CTRL_RISING_EDGE; \
            LFSR_CONTROL_REG &= ((uint8)~LFSR_CTRL_RISING_EDGE);    \
        } while (0)
    
#endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */

#if (LFSR_TIME_MULTIPLEXING_ENABLE)
    
    #if (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK)
        #define LFSR_STATUS                     (*(reg8 *) LFSR_Sts_StsReg__STATUS_REG )
        #define LFSR_STATUS_PTR                 ( (reg8 *) LFSR_Sts_StsReg__STATUS_REG )
    #endif  /* End (LFSR_WAKEUP_BEHAVIOUR == LFSR__RESUMEWORK) */
    
    #if (LFSR_PRS_SIZE <= 16u)      /* 16 bits PRS */
        /* Polynomial */
        #define LFSR_POLYNOM_A__D1_REG          (*(reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        #define LFSR_POLYNOM_A__D1_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        #define LFSR_POLYNOM_A__D0_REG          (*(reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        #define LFSR_POLYNOM_A__D0_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        /* Seed */
        #define LFSR_SEED_A__A1_REG             (*(reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        #define LFSR_SEED_A__A1_PTR         	( (reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        #define LFSR_SEED_A__A0_REG             (*(reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        #define LFSR_SEED_A__A0_PTR         	( (reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        /* Seed COPY */
        #define LFSR_SEED_COPY_A__A1_REG        (*(reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        #define LFSR_SEED_COPY_A__A1_PTR    	( (reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        #define LFSR_SEED_COPY_A__A0_REG        (*(reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        #define LFSR_SEED_COPY_A__A0_PTR    	( (reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        
    #elif (LFSR_PRS_SIZE <= 24u)      /* 24 bits PRS */
        /* Polynomial */
        #define LFSR_POLYNOM_B__D1_REG          (*(reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_B__D1_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_B__D0_REG          (*(reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_B__D0_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_A__D0_REG          (*(reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        #define LFSR_POLYNOM_A__D0_PTR     	 	( (reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        /* Seed */
        #define LFSR_SEED_B__A1_REG             (*(reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_B__A1_PTR         	( (reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_B__A0_REG             (*(reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_B__A0_PTR     	    ( (reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_A__A0_REG             (*(reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        #define LFSR_SEED_A__A0_PTR 	        ( (reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        /* Seed COPY */
        #define LFSR_SEED_COPY_B__A1_REG        (*(reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_COPY_B__A1_PTR 	    ( (reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_COPY_B__A0_REG        (*(reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_COPY_B__A0_PTR	    ( (reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_COPY_A__A0_REG        (*(reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        #define LFSR_SEED_COPY_A__A0_PTR    	( (reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        
    #elif (LFSR_PRS_SIZE <= 32u)      /* 32 bits PRS */
        /* Polynomial */
        #define LFSR_POLYNOM_B__D1_REG          (*(reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_B__D1_PTR    		( (reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_A__D1_REG          (*(reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        #define LFSR_POLYNOM_A__D1_PTR     		( (reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        #define LFSR_POLYNOM_B__D0_REG          (*(reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_B__D0_PTR		    ( (reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_A__D0_REG          (*(reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        #define LFSR_POLYNOM_A__D0_PTR  	    ( (reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        /* Seed */
        #define LFSR_SEED_B__A1_REG             (*(reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_B__A1_PTR    		    ( (reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_A__A1_REG         	(*(reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        #define LFSR_SEED_A__A1_PTR      	    ( (reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        #define LFSR_SEED_B__A0_REG             (*(reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_B__A0_PTR     	    ( (reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_A__A0_REG             (*(reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        #define LFSR_SEED_A__A0_PTR     	    ( (reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        /* Seed COPY */
        #define LFSR_SEED_COPY_B__A1_REG        (*(reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_COPY_B__A1_PTR  		( (reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_COPY_A__A1_REG        (*(reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        #define LFSR_SEED_COPY_A__A1_PTR   	 	( (reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        #define LFSR_SEED_COPY_B__A0_REG        (*(reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_COPY_B__A0_PTR  	  	( (reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_COPY_A__A0_REG        (*(reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        #define LFSR_SEED_COPY_A__A0_PTR   	 	( (reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        
    #elif (LFSR_PRS_SIZE <= 40u)      /* 40 bits PRS */
        /* Polynomial Upper */
        #define LFSR_POLYNOM_UPPER_C__D1_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        #define LFSR_POLYNOM_UPPER_C__D1_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        /* Polynomial Lower */
        #define LFSR_POLYNOM_LOWER_B__D1_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_LOWER_B__D1_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_REG            (*(reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_PTR        	( (reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        /* Seed Upper */
        #define LFSR_SEED_UPPER_C__A1_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        #define LFSR_SEED_UPPER_C__A1_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        /* Seed Lower */
        #define LFSR_SEED_LOWER_B__A1_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_LOWER_B__A1_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_LOWER_C__A0_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_C__A0_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_REG               (*(reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_PTR           	( (reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        /* Seed COPY Upper */
        #define LFSR_SEED_UPPER_COPY_C__A1_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        #define LFSR_SEED_UPPER_COPY_C__A1_PTR      	( (reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        /* Seed COPY Lower */
        #define LFSR_SEED_LOWER_COPY_B__A1_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_LOWER_COPY_B__A1_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_PTR      	( (reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_REG          (*(reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        
    #elif (LFSR_PRS_SIZE <= 48u)      /* 48 bits PRS */
        /* Polynomial Upper */
        #define LFSR_POLYNOM_UPPER_C__D1_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        #define LFSR_POLYNOM_UPPER_C__D1_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        #define LFSR_POLYNOM_UPPER_B__D1_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_UPPER_B__D1_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        /* Polynomial Lower */
        #define LFSR_POLYNOM_LOWER_A__D1_REG            (*(reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        #define LFSR_POLYNOM_LOWER_A__D1_PTR        	( (reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_REG            (*(reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_PTR        	( (reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        /* Seed Upper */
        #define LFSR_SEED_UPPER_C__A1_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        #define LFSR_SEED_UPPER_C__A1_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        #define LFSR_SEED_UPPER_B__A1_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_UPPER_B__A1_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        /* Seed Lower */
        #define LFSR_SEED_LOWER_A__A1_REG               (*(reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        #define LFSR_SEED_LOWER_A__A1_PTR           	( (reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        #define LFSR_SEED_LOWER_C__A0_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_C__A0_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_REG               (*(reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_PTR           	( (reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        /* Seed COPY Upper */
        #define LFSR_SEED_UPPER_COPY_C__A1_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        #define LFSR_SEED_UPPER_COPY_C__A1_PTR      	( (reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        #define LFSR_SEED_UPPER_COPY_B__A1_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_UPPER_COPY_B__A1_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        /* Seed COPY Lower */
        #define LFSR_SEED_LOWER_COPY_A__A1_REG          (*(reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        #define LFSR_SEED_LOWER_COPY_A__A1_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_PTR      	( (reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_REG          (*(reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        
    #elif (LFSR_PRS_SIZE <= 56u)      /* 56 bits PRS */
        /* Polynom Upper */
        #define LFSR_POLYNOM_UPPER_D__D1_REG            (*(reg8 *) LFSR_b3_PRSdp_d__D1_REG )
        #define LFSR_POLYNOM_UPPER_D__D1_PTR        	( (reg8 *) LFSR_b3_PRSdp_d__D1_REG )
        #define LFSR_POLYNOM_UPPER_C__D1_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        #define LFSR_POLYNOM_UPPER_C__D1_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        #define LFSR_POLYNOM_UPPER_B__D1_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_UPPER_B__D1_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        /* Polynom Lower */
        #define LFSR_POLYNOM_LOWER_D__D0_REG            (*(reg8 *) LFSR_b3_PRSdp_d__D0_REG )
        #define LFSR_POLYNOM_LOWER_D__D0_PTR        	( (reg8 *) LFSR_b3_PRSdp_d__D0_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_REG            (*(reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_PTR        	( (reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        /* Seed Upper */
        #define LFSR_SEED_UPPER_D__A1_REG               (*(reg8 *) LFSR_b3_PRSdp_d__A1_REG )
        #define LFSR_SEED_UPPER_D__A1_PTR           	( (reg8 *) LFSR_b3_PRSdp_d__A1_REG )
        #define LFSR_SEED_UPPER_C__A1_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        #define LFSR_SEED_UPPER_C__A1_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        #define LFSR_SEED_UPPER_B__A1_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_UPPER_B__A1_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        /* Seed Lower */
        #define LFSR_SEED_LOWER_D__A0_REG               (*(reg8 *) LFSR_b3_PRSdp_d__A0_REG )
        #define LFSR_SEED_LOWER_D__A0_PTR           	( (reg8 *) LFSR_b3_PRSdp_d__A0_REG )
        #define LFSR_SEED_LOWER_C__A0_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_C__A0_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_REG               (*(reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_PTR           	( (reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        /* COPY Seed Upper */
        #define LFSR_SEED_UPPER_COPY_D__A1_REG          (*(reg8 *) LFSR_b3_PRSdp_d__F1_REG )
        #define LFSR_SEED_UPPER_COPY_D__A1_PTR      	( (reg8 *) LFSR_b3_PRSdp_d__F1_REG )
        #define LFSR_SEED_UPPER_COPY_C__A1_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        #define LFSR_SEED_UPPER_COPY_C__A1_PTR      	( (reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        #define LFSR_SEED_UPPER_COPY_B__A1_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_UPPER_COPY_B__A1_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        /* COPY Seed Lower */
        #define LFSR_SEED_LOWER_COPY_D__A0_REG          (*(reg8 *) LFSR_b3_PRSdp_d__F0_REG )
        #define LFSR_SEED_LOWER_COPY_D__A0_PTR      	( (reg8 *) LFSR_b3_PRSdp_d__F0_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_PTR      	( (reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_REG          (*(reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        
    #else                                        /* 64 bits PRS */
        /* Polynom Upper */
        #define LFSR_POLYNOM_UPPER_D__D1_REG            (*(reg8 *) LFSR_b3_PRSdp_d__D1_REG )
        #define LFSR_POLYNOM_UPPER_D__D1_PTR        	( (reg8 *) LFSR_b3_PRSdp_d__D1_REG )
        #define LFSR_POLYNOM_UPPER_C__D1_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        #define LFSR_POLYNOM_UPPER_C__D1_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D1_REG )
        #define LFSR_POLYNOM_UPPER_B__D1_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_UPPER_B__D1_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D1_REG )
        #define LFSR_POLYNOM_UPPER_A__D1_REG            (*(reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        #define LFSR_POLYNOM_UPPER_A__D1_PTR        	( (reg8 *) LFSR_b0_PRSdp_a__D1_REG )
        /* Polynom Lower */
        #define LFSR_POLYNOM_LOWER_D__D0_REG            (*(reg8 *) LFSR_b3_PRSdp_d__D0_REG )
        #define LFSR_POLYNOM_LOWER_D__D0_PTR        	( (reg8 *) LFSR_b3_PRSdp_d__D0_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_REG            (*(reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_C__D0_PTR        	( (reg8 *) LFSR_b2_PRSdp_c__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_REG            (*(reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_B__D0_PTR        	( (reg8 *) LFSR_b1_PRSdp_b__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_REG            (*(reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        #define LFSR_POLYNOM_LOWER_A__D0_PTR        	( (reg8 *) LFSR_b0_PRSdp_a__D0_REG )
        /* Seed Upper */
        #define LFSR_SEED_UPPER_D__A1_REG               (*(reg8 *) LFSR_b3_PRSdp_d__A1_REG )
        #define LFSR_SEED_UPPER_D__A1_PTR           	( (reg8 *) LFSR_b3_PRSdp_d__A1_REG )
        #define LFSR_SEED_UPPER_C__A1_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        #define LFSR_SEED_UPPER_C__A1_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A1_REG )
        #define LFSR_SEED_UPPER_B__A1_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_UPPER_B__A1_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A1_REG )
        #define LFSR_SEED_UPPER_A__A1_REG               (*(reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        #define LFSR_SEED_UPPER_A__A1_PTR           	( (reg8 *) LFSR_b0_PRSdp_a__A1_REG )
        /* Seed Lower */
        #define LFSR_SEED_LOWER_D__A0_REG               (*(reg8 *) LFSR_b3_PRSdp_d__A0_REG )
        #define LFSR_SEED_LOWER_D__A0_PTR           	( (reg8 *) LFSR_b3_PRSdp_d__A0_REG )
        #define LFSR_SEED_LOWER_C__A0_REG               (*(reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_C__A0_PTR           	( (reg8 *) LFSR_b2_PRSdp_c__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_REG               (*(reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_B__A0_PTR           	( (reg8 *) LFSR_b1_PRSdp_b__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_REG               (*(reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        #define LFSR_SEED_LOWER_A__A0_PTR           	( (reg8 *) LFSR_b0_PRSdp_a__A0_REG )
        /* COPY Seed Upper */
        #define LFSR_SEED_UPPER_COPY_D__A1_REG          (*(reg8 *) LFSR_b3_PRSdp_d__F1_REG )
        #define LFSR_SEED_UPPER_COPY_D__A1_PTR      	( (reg8 *) LFSR_b3_PRSdp_d__F1_REG )
        #define LFSR_SEED_UPPER_COPY_C__A1_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        #define LFSR_SEED_UPPER_COPY_C__A1_PTR      	( (reg8 *) LFSR_b2_PRSdp_c__F1_REG )
        #define LFSR_SEED_UPPER_COPY_B__A1_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_UPPER_COPY_B__A1_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F1_REG )
        #define LFSR_SEED_UPPER_COPY_A__A1_REG          (*(reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        #define LFSR_SEED_UPPER_COPY_A__A1_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__F1_REG )
        /* COPY Seed Lower */
        #define LFSR_SEED_LOWER_COPY_D__A0_REG          (*(reg8 *) LFSR_b3_PRSdp_d__F0_REG )
        #define LFSR_SEED_LOWER_COPY_D__A0_PTR      	( (reg8 *) LFSR_b3_PRSdp_d__F0_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_REG          (*(reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_C__A0_PTR    		( (reg8 *) LFSR_b2_PRSdp_c__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_REG          (*(reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_B__A0_PTR      	( (reg8 *) LFSR_b1_PRSdp_b__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_REG          (*(reg8 *) LFSR_b0_PRSdp_a__F0_REG )
        #define LFSR_SEED_LOWER_COPY_A__A0_PTR      	( (reg8 *) LFSR_b0_PRSdp_a__F0_REG )
    #endif  /* End (LFSR_PRS_SIZE <= 8u) */

#else
    #if (CY_PSOC3 || CY_PSOC5)
        #if (LFSR_PRS_SIZE <= 32u)         /* 8-32 bits PRS */
            /* Polynomial */
            #define LFSR_POLYNOM_PTR      ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__D0_REG )
            /* Seed */
            #define LFSR_SEED_PTR         ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__A0_REG )
            /* Seed COPY */
            #define LFSR_SEED_COPY_PTR    ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__F0_REG )
            
        #endif  /* End (LFSR_PRS_SIZE <= 32u) */
    #else /* PSoC4 */
        #if (LFSR_PRS_SIZE <= 8u)         /* 8 bits PRS */
            /* Polynomial */
            #define LFSR_POLYNOM_PTR      ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__D0_REG )
            /* Seed */
            #define LFSR_SEED_PTR         ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__A0_REG )
            /* Seed COPY */
            #define LFSR_SEED_COPY_PTR    ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__F0_REG )
            
        #elif (LFSR_PRS_SIZE <= 16u)         /* 16 bits PRS */
            /* Polynomial */
            #define LFSR_POLYNOM_PTR      ( (reg16 *)\
                                            LFSR_sC16_PRSdp_u0__16BIT_D0_REG )
            /* Seed */
            #define LFSR_SEED_PTR         ( (reg16 *)\
                                            LFSR_sC16_PRSdp_u0__16BIT_A0_REG )
            /* Seed COPY */
            #define LFSR_SEED_COPY_PTR    ( (reg16 *)\
                                            LFSR_sC16_PRSdp_u0__16BIT_F0_REG )

        #elif (LFSR_PRS_SIZE <= 24u)         /* 24 bits PRS */
            /* Polynomial */
            #define LFSR_POLYNOM_PTR      ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__D0_REG )
            /* Seed */
            #define LFSR_SEED_PTR         ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__A0_REG )
            /* Seed COPY */
            #define LFSR_SEED_COPY_PTR    ( (reg16 *)\
                                                LFSR_sC16_PRSdp_u0__F0_REG )
         
         #else                                          /* 32 bits PRS */
            /* Polynomial */
            #define LFSR_POLYNOM_PTR      ( (reg16 *)\
                                            LFSR_sC16_PRSdp_u0__32BIT_D0_REG )
            /* Seed */
            #define LFSR_SEED_PTR         ( (reg16 *)\
                                            LFSR_sC16_PRSdp_u0__32BIT_A0_REG )
            /* Seed COPY */
            #define LFSR_SEED_COPY_PTR    ( (reg16 *)\
                                            LFSR_sC16_PRSdp_u0__32BIT_F0_REG )
         
        #endif  /* End (LFSR_PRS_SIZE <= 32u) */

    #endif  /* End (CY_PSOC3 || CY_PSOC5) */
    
#endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */


#if (LFSR_RUN_MODE == LFSR__CLOCKED)
    /* Aux control */
    #if (LFSR_TIME_MULTIPLEXING_ENABLE)    
        #if (LFSR_PRS_SIZE <= 16u)      /* 8-16 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            
        #elif (LFSR_PRS_SIZE <= 24u)      /* 24-39 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_REG      (*(reg8 *) LFSR_b1_PRSdp_b__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_PTR      ( (reg8 *) LFSR_b1_PRSdp_b__DP_AUX_CTL_REG )
            
        #elif (LFSR_PRS_SIZE <= 40u)      /* 40-55 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_REG      (*(reg8 *) LFSR_b1_PRSdp_b__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_PTR      ( (reg8 *) LFSR_b1_PRSdp_b__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_REG      (*(reg8 *) LFSR_b2_PRSdp_c__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_PTR      ( (reg8 *) LFSR_b2_PRSdp_c__DP_AUX_CTL_REG )

        #else                                         /* 56-64 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_b0_PRSdp_a__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_REG      (*(reg8 *) LFSR_b1_PRSdp_b__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_PTR      ( (reg8 *) LFSR_b1_PRSdp_b__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_REG      (*(reg8 *) LFSR_b2_PRSdp_c__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_PTR      ( (reg8 *) LFSR_b2_PRSdp_c__DP_AUX_CTL_REG )
			#define LFSR_AUX_CONTROL_D_REG      (*(reg8 *) LFSR_b3_PRSdp_d__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_D_PTR      ( (reg8 *) LFSR_b3_PRSdp_d__DP_AUX_CTL_REG )     
																							
        #endif  /* End (LFSR_PRS_SIZE <= 8u) */
    
    #else
        #if (LFSR_PRS_SIZE <= 8u)      /* 8 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_sC8_PRSdp_u0__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_sC8_PRSdp_u0__DP_AUX_CTL_REG )
            
        #elif (LFSR_PRS_SIZE <= 16u)      /* 16 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_sC16_PRSdp_u0__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_sC16_PRSdp_u0__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_REG      (*(reg8 *) LFSR_sC16_PRSdp_u1__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_PTR      ( (reg8 *) LFSR_sC16_PRSdp_u1__DP_AUX_CTL_REG )
            
        #elif (LFSR_PRS_SIZE <= 24u)      /* 24-39 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_sC24_PRSdp_u0__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_sC24_PRSdp_u0__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_REG      (*(reg8 *) LFSR_sC24_PRSdp_u1__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_PTR      ( (reg8 *) LFSR_sC24_PRSdp_u1__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_REG      (*(reg8 *) LFSR_sC24_PRSdp_u2__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_PTR      ( (reg8 *) LFSR_sC24_PRSdp_u2__DP_AUX_CTL_REG )
                
        #elif (LFSR_PRS_SIZE <= 32u)      /* 40-55 bits PRS */
            #define LFSR_AUX_CONTROL_A_REG      (*(reg8 *) LFSR_sC32_PRSdp_u0__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_A_PTR      ( (reg8 *) LFSR_sC32_PRSdp_u0__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_REG      (*(reg8 *) LFSR_sC32_PRSdp_u1__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_B_PTR      ( (reg8 *) LFSR_sC32_PRSdp_u1__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_REG      (*(reg8 *) LFSR_sC32_PRSdp_u2__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_C_PTR      ( (reg8 *) LFSR_sC32_PRSdp_u2__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_D_REG      (*(reg8 *) LFSR_sC32_PRSdp_u3__DP_AUX_CTL_REG )
            #define LFSR_AUX_CONTROL_D_PTR      ( (reg8 *) LFSR_sC32_PRSdp_u3__DP_AUX_CTL_REG )
    
        #else                                         /* 56-64 bits PRS */
            /* Not supported */                    
        #endif  /* End (LFSR_PRS_SIZE <= 8u) */
    
    #endif  /* End (LFSR_TIME_MULTIPLEXING_ENABLE) */
    
#endif  /* End (LFSR_RUN_MODE == LFSR__CLOCKED) */

#define LFSR_CONTROL_REG               (*(reg8 *) LFSR_ClkSp_CtrlReg__CONTROL_REG )
#define LFSR_CONTROL_PTR               ( (reg8 *) LFSR_ClkSp_CtrlReg__CONTROL_REG )
    

/***************************************
*       Register Constants
***************************************/

/* Control register definitions */

#define LFSR_CTRL_ENABLE                    (0x01u)
#define LFSR_CTRL_RISING_EDGE               (0x02u)
#define LFSR_CTRL_RESET_COMMON              (0x04u)
#define LFSR_CTRL_RESET_CI                  (0x08u)
#define LFSR_CTRL_RESET_SI                  (0x10u)
#define LFSR_CTRL_RESET_SO                  (0x20u)
#define LFSR_CTRL_RESET_STATE0              (0x40u)
#define LFSR_CTRL_RESET_STATE1              (0x80u)

#define LFSR_INIT_STATE                     ( LFSR_CTRL_RESET_CI |\
                                                          LFSR_CTRL_RESET_SI |\
                                                          LFSR_CTRL_RESET_SO |\
                                                          LFSR_CTRL_RESET_STATE0 |\
                                                          LFSR_CTRL_RESET_STATE1 )
                                                          
/* Status register definitions */
#define LFSR_STS_RESET_CI                   (0x08u)
#define LFSR_STS_RESET_SI                   (0x10u)
#define LFSR_STS_RESET_SO                   (0x20u)
#define LFSR_STS_RESET_STATE0               (0x40u)
#define LFSR_STS_RESET_STATE1               (0x80u)

/* Aux Control register definitions */
#define LFSR_AUXCTRL_FIFO_SINGLE_REG        (0x03u)

#define LFSR_NORMAL_SEQUENCE                (0x01u)

#define LFSR_IS_PRS_ENABLE(reg)             (((reg) & LFSR_CTRL_ENABLE) != 0u)

#endif  /* End CY_PRS_LFSR_H */


/* [] END OF FILE */
