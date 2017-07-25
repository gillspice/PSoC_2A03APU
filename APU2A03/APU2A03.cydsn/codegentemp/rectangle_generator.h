/*******************************************************************************
* File Name: rectangle_generator.h
* Version 2.30
*
* Description:
*  This header file contains definitions associated with the Shift Register
*  component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/


#if !defined(CY_SHIFTREG_rectangle_generator_H)
#define CY_SHIFTREG_rectangle_generator_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ShiftReg_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define rectangle_generator_FIFO_SIZE          (4u)
#define rectangle_generator_USE_INPUT_FIFO     (0u)
#define rectangle_generator_USE_OUTPUT_FIFO    (0u)
#define rectangle_generator_SR_SIZE            (16u)


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;

    uint16 saveSrA0Reg;
    uint16 saveSrA1Reg;

    #if(CY_UDB_V0)
        uint16 saveSrIntMask;
    #endif /* (CY_UDB_V0) */

} rectangle_generator_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  rectangle_generator_Start(void)                              ;
void  rectangle_generator_Stop(void)                               ;
void  rectangle_generator_Init(void)                               ;
void  rectangle_generator_Enable(void)                             ;
void  rectangle_generator_RestoreConfig(void)                      ;
void  rectangle_generator_SaveConfig(void)                         ;
void  rectangle_generator_Sleep(void)                              ;
void  rectangle_generator_Wakeup(void)                             ;
void  rectangle_generator_EnableInt(void)                          ;
void  rectangle_generator_DisableInt(void)                         ;
void  rectangle_generator_SetIntMode(uint8 interruptSource)        ;
uint8 rectangle_generator_GetIntStatus(void)                       ;
void  rectangle_generator_WriteRegValue(uint16 shiftData) \
                                                                ;
uint16 rectangle_generator_ReadRegValue(void) ;
uint8    rectangle_generator_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != rectangle_generator_USE_INPUT_FIFO)
    cystatus rectangle_generator_WriteData(uint16 shiftData) \
                                                                ;
#endif /* (0u != rectangle_generator_USE_INPUT_FIFO) */

#if(0u != rectangle_generator_USE_OUTPUT_FIFO)
    uint16 rectangle_generator_ReadData(void) ;
#endif /* (0u != rectangle_generator_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 rectangle_generator_initVar;


/***************************************
*           API Constants
***************************************/

#define rectangle_generator_LOAD                   (0x01u)
#define rectangle_generator_STORE                  (0x02u)
#define rectangle_generator_RESET                  (0x04u)

#define rectangle_generator_IN_FIFO                (0x01u)
#define rectangle_generator_OUT_FIFO               (0x02u)

#define rectangle_generator_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define rectangle_generator_RET_FIFO_NOT_EMPTY     (0x01u)

#define rectangle_generator_RET_FIFO_PARTIAL       (0x01u)
#define rectangle_generator_RET_FIFO_EMPTY         (0x02u)
#define rectangle_generator_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define rectangle_generator__LEFT 0
#define rectangle_generator__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define rectangle_generator_SR_MASK    (0xFFFFu) /* Unsigned is added to parameter */
#define rectangle_generator_INT_SRC    (0u)
#define rectangle_generator_DIRECTION  (1u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define rectangle_generator_SR_CONTROL_REG (* (reg8 *) \
                                           rectangle_generator_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define rectangle_generator_SR_CONTROL_PTR (  (reg8 *) \
                                           rectangle_generator_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define rectangle_generator_SR_STATUS_REG      (* (reg8 *) rectangle_generator_bSR_StsReg__STATUS_REG)
#define rectangle_generator_SR_STATUS_PTR      (  (reg8 *) rectangle_generator_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define rectangle_generator_SR_STATUS_MASK_REG (* (reg8 *) rectangle_generator_bSR_StsReg__MASK_REG)
#define rectangle_generator_SR_STATUS_MASK_PTR (  (reg8 *) rectangle_generator_bSR_StsReg__MASK_REG)

/* Aux control register */
#define rectangle_generator_SR_AUX_CONTROL_REG (* (reg8 *) rectangle_generator_bSR_StsReg__STATUS_AUX_CTL_REG)
#define rectangle_generator_SR_AUX_CONTROL_PTR (  (reg8 *) rectangle_generator_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define rectangle_generator_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define rectangle_generator_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__F0_REG )

    #define rectangle_generator_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__A0_REG )

    #define rectangle_generator_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__A1_REG )

    #define rectangle_generator_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__F1_REG )

#else
    #if(rectangle_generator_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define rectangle_generator_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__F0_REG )

        #define rectangle_generator_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__A0_REG )

        #define rectangle_generator_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__A1_REG )

        #define rectangle_generator_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__F1_REG )

    #elif(rectangle_generator_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define rectangle_generator_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__16BIT_F0_REG )

        #define rectangle_generator_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__16BIT_A0_REG )

        #define rectangle_generator_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__16BIT_A1_REG )

        #define rectangle_generator_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(rectangle_generator_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define rectangle_generator_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__F0_REG )

        #define rectangle_generator_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__A0_REG )

        #define rectangle_generator_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__A1_REG )

        #define rectangle_generator_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        rectangle_generator_bSR_sC16_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define rectangle_generator_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__32BIT_F0_REG )

        #define rectangle_generator_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__32BIT_A0_REG )

        #define rectangle_generator_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__32BIT_A1_REG )

        #define rectangle_generator_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  rectangle_generator_bSR_sC16_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (rectangle_generator_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define rectangle_generator_INTERRUPTS_ENABLE      (0x10u)
#define rectangle_generator_LOAD_INT_EN            (0x01u)
#define rectangle_generator_STORE_INT_EN           (0x02u)
#define rectangle_generator_RESET_INT_EN           (0x04u)
#define rectangle_generator_CLK_EN                 (0x01u)

#define rectangle_generator_RESET_INT_EN_MASK      (0xFBu)
#define rectangle_generator_LOAD_INT_EN_MASK       (0xFEu)
#define rectangle_generator_STORE_INT_EN_MASK      (0xFDu)
#define rectangle_generator_INTS_EN_MASK           (0x07u)

#define rectangle_generator_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != rectangle_generator_USE_INPUT_FIFO)

    #define rectangle_generator_IN_FIFO_MASK       (0x18u)

    #define rectangle_generator_IN_FIFO_FULL       (0x00u)
    #define rectangle_generator_IN_FIFO_EMPTY      (0x01u)
    #define rectangle_generator_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define rectangle_generator_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != rectangle_generator_USE_INPUT_FIFO) */

#define rectangle_generator_OUT_FIFO_MASK          (0x60u)

#define rectangle_generator_OUT_FIFO_EMPTY         (0x00u)
#define rectangle_generator_OUT_FIFO_FULL          (0x01u)
#define rectangle_generator_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define rectangle_generator_OUT_FIFO_NOT_EMPTY     (0x02u)

#define rectangle_generator_IN_FIFO_SHIFT_MASK     (0x03u)
#define rectangle_generator_OUT_FIFO_SHIFT_MASK    (0x05u)

#define rectangle_generator_DISABLED               (0u)
#define rectangle_generator_DEFAULT_A0             (0u)
#define rectangle_generator_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define rectangle_generator_IS_ENABLED         (0u != (rectangle_generator_SR_CONTROL & rectangle_generator_CLK_EN))

#define rectangle_generator_GET_OUT_FIFO_STS   ((rectangle_generator_SR_STATUS & rectangle_generator_OUT_FIFO_MASK) >> \
                                              rectangle_generator_OUT_FIFO_SHIFT_MASK)

#define rectangle_generator_GET_IN_FIFO_STS    ((rectangle_generator_SR_STATUS & rectangle_generator_IN_FIFO_MASK)  >> \
                                              rectangle_generator_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define rectangle_generator_SR_CONTROL     (rectangle_generator_SR_CONTROL_REG)
#define rectangle_generator_SR_STATUS      (rectangle_generator_SR_STATUS_REG)
#define rectangle_generator_SR_STATUS_MASK (rectangle_generator_SR_STATUS_MASK_REG)
#define rectangle_generator_SR_AUX_CONTROL (rectangle_generator_SR_AUX_CONTROL_REG)

#define rectangle_generator_IN_FIFO_SHFT_MASK  (rectangle_generator_IN_FIFO_SHIFT_MASK)
#define rectangle_generator_OUT_FIFO_SHFT_MASK (rectangle_generator_OUT_FIFO_SHFIT_MASK)

#define rectangle_generator_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_rectangle_generator_H) */


/* [] END OF FILE */
