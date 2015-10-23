/*******************************************************************************
* File Name: Iambic_Clock_1.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Iambic_Clock_1_H)
#define CY_CLOCK_Iambic_Clock_1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Iambic_Clock_1_Start(void) ;
void Iambic_Clock_1_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Iambic_Clock_1_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Iambic_Clock_1_StandbyPower(uint8 state) ;
void Iambic_Clock_1_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Iambic_Clock_1_GetDividerRegister(void) ;
void Iambic_Clock_1_SetModeRegister(uint8 modeBitMask) ;
void Iambic_Clock_1_ClearModeRegister(uint8 modeBitMask) ;
uint8 Iambic_Clock_1_GetModeRegister(void) ;
void Iambic_Clock_1_SetSourceRegister(uint8 clkSource) ;
uint8 Iambic_Clock_1_GetSourceRegister(void) ;
#if defined(Iambic_Clock_1__CFG3)
void Iambic_Clock_1_SetPhaseRegister(uint8 clkPhase) ;
uint8 Iambic_Clock_1_GetPhaseRegister(void) ;
#endif /* defined(Iambic_Clock_1__CFG3) */

#define Iambic_Clock_1_Enable()                       Iambic_Clock_1_Start()
#define Iambic_Clock_1_Disable()                      Iambic_Clock_1_Stop()
#define Iambic_Clock_1_SetDivider(clkDivider)         Iambic_Clock_1_SetDividerRegister(clkDivider, 1u)
#define Iambic_Clock_1_SetDividerValue(clkDivider)    Iambic_Clock_1_SetDividerRegister((clkDivider) - 1u, 1u)
#define Iambic_Clock_1_SetMode(clkMode)               Iambic_Clock_1_SetModeRegister(clkMode)
#define Iambic_Clock_1_SetSource(clkSource)           Iambic_Clock_1_SetSourceRegister(clkSource)
#if defined(Iambic_Clock_1__CFG3)
#define Iambic_Clock_1_SetPhase(clkPhase)             Iambic_Clock_1_SetPhaseRegister(clkPhase)
#define Iambic_Clock_1_SetPhaseValue(clkPhase)        Iambic_Clock_1_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Iambic_Clock_1__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Iambic_Clock_1_CLKEN              (* (reg8 *) Iambic_Clock_1__PM_ACT_CFG)
#define Iambic_Clock_1_CLKEN_PTR          ((reg8 *) Iambic_Clock_1__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Iambic_Clock_1_CLKSTBY            (* (reg8 *) Iambic_Clock_1__PM_STBY_CFG)
#define Iambic_Clock_1_CLKSTBY_PTR        ((reg8 *) Iambic_Clock_1__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Iambic_Clock_1_DIV_LSB            (* (reg8 *) Iambic_Clock_1__CFG0)
#define Iambic_Clock_1_DIV_LSB_PTR        ((reg8 *) Iambic_Clock_1__CFG0)
#define Iambic_Clock_1_DIV_PTR            ((reg16 *) Iambic_Clock_1__CFG0)

/* Clock MSB divider configuration register. */
#define Iambic_Clock_1_DIV_MSB            (* (reg8 *) Iambic_Clock_1__CFG1)
#define Iambic_Clock_1_DIV_MSB_PTR        ((reg8 *) Iambic_Clock_1__CFG1)

/* Mode and source configuration register */
#define Iambic_Clock_1_MOD_SRC            (* (reg8 *) Iambic_Clock_1__CFG2)
#define Iambic_Clock_1_MOD_SRC_PTR        ((reg8 *) Iambic_Clock_1__CFG2)

#if defined(Iambic_Clock_1__CFG3)
/* Analog clock phase configuration register */
#define Iambic_Clock_1_PHASE              (* (reg8 *) Iambic_Clock_1__CFG3)
#define Iambic_Clock_1_PHASE_PTR          ((reg8 *) Iambic_Clock_1__CFG3)
#endif /* defined(Iambic_Clock_1__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Iambic_Clock_1_CLKEN_MASK         Iambic_Clock_1__PM_ACT_MSK
#define Iambic_Clock_1_CLKSTBY_MASK       Iambic_Clock_1__PM_STBY_MSK

/* CFG2 field masks */
#define Iambic_Clock_1_SRC_SEL_MSK        Iambic_Clock_1__CFG2_SRC_SEL_MASK
#define Iambic_Clock_1_MODE_MASK          (~(Iambic_Clock_1_SRC_SEL_MSK))

#if defined(Iambic_Clock_1__CFG3)
/* CFG3 phase mask */
#define Iambic_Clock_1_PHASE_MASK         Iambic_Clock_1__CFG3_PHASE_DLY_MASK
#endif /* defined(Iambic_Clock_1__CFG3) */

#endif /* CY_CLOCK_Iambic_Clock_1_H */


/* [] END OF FILE */
