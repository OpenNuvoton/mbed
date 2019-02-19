/*
 * Copyright (c) 2019-2020, Nuvoton Technology Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PARTITION_M2351
#define PARTITION_M2351

#include "partition_M2351_mem.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define NU_TZ_SECURE_FLASH_SIZE     NU_ROM_SIZE_S
#define NU_TZ_SECURE_SRAM_SIZE      NU_RAM_SIZE_S

#if defined(__CC_ARM) || (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))

extern int Image$$ER_IROM_NSC$$Base;
extern int Image$$ER_IROM_NSC_PAD$$Limit;
#define NU_TZ_NSC_REGION_START  ((uint32_t) &Image$$ER_IROM_NSC$$Base)
#define NU_TZ_NSC_REGION_SIZE   (((uint32_t) &Image$$ER_IROM_NSC_PAD$$Limit) - ((uint32_t) &Image$$ER_IROM_NSC$$Base))

#elif defined(__ICCARM__)

#error("NSC region symbols not defined with IAR toolchain")

#elif defined(__GNUC__)

extern int Image$$ER_IROM_NSC$$Base;
extern int Image$$ER_IROM_NSC_PAD$$Limit;
#define NU_TZ_NSC_REGION_START  ((uint32_t) &Image$$ER_IROM_NSC$$Base)
#define NU_TZ_NSC_REGION_SIZE   (((uint32_t) &Image$$ER_IROM_NSC_PAD$$Limit) - ((uint32_t) &Image$$ER_IROM_NSC$$Base))

#endif


/*
//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
*/


/*
    SRAMNSSET
*/
/*
// Bit 0..16
// <o.0..16> Secure SRAM Size              <0=> 0 KB
//                                         <0x2000=> 8KB
//                                         <0x4000=> 16KB
//                                         <0x6000=> 24KB
//                                         <0x8000=> 32KB
//                                         <0xa000=> 40KB
//                                         <0xc000=> 48KB
//                                         <0xe000=> 56KB
//                                         <0x10000=> 64KB
//                                         <0x12000=> 72KB
//                                         <0x14000=> 80KB
//                                         <0x16000=> 88KB
//                                         <0x18000=> 96KB
*/
#define SCU_SECURE_SRAM_SIZE      NU_TZ_SECURE_SRAM_SIZE
#define NON_SECURE_SRAM_BASE    (0x30000000 + SCU_SECURE_SRAM_SIZE)



/*--------------------------------------------------------------------------------------------------------*/

/*
    NSBA
*/
#define FMC_INIT_NSBA          1
/*
//     <o>Secure Flash ROM Size <0x800-0x7FFFF:0x800>
*/

#define FMC_SECURE_ROM_SIZE      NU_TZ_SECURE_FLASH_SIZE

#define FMC_NON_SECURE_BASE     (0x10000000 + FMC_SECURE_ROM_SIZE)

/*--------------------------------------------------------------------------------------------------------*/


/*
// <h> Peripheral Secure Attribution Configuration
*/

/*
    PNSSET0
*/
/*
// Module 0..31
//   <o.9>  USBH       <0=> Secure <1=> Non-Secure
//   <o.13>  SD0   <0=> Secure <1=> Non-Secure
//   <o.16>  EBI    <0=> Secure <1=> Non-Secure
//   <o.24>  PDMA1      <0=> Secure <1=> Non-Secure
*/
#define SCU_INIT_PNSSET0_VAL      0xFFFFFFFF
/*
    PNSSET1
*/
/*
// Module 0..31
//   <o.17>  CRC       <0=> Secure <1=> Non-Secure
//   <o.18>  CRPT   <0=> Secure <1=> Non-Secure
*/
#define SCU_INIT_PNSSET1_VAL      0xFFFFFFFF
/*
    PNSSET2
*/
/*
// Module 0..31
//   <o.1>  RTC       <0=> Secure <1=> Non-Secure
//   <o.3>  EADC   <0=> Secure <1=> Non-Secure
//   <o.5>  ACMP01     <0=> Secure <1=> Non-Secure
//
//   <o.7>  DAC      <0=> Secure <1=> Non-Secure
//   <o.8>  I2S0      <0=> Secure <1=> Non-Secure
//   <o.13>  OTG      <0=> Secure <1=> Non-Secure
//   <o.17>  TMR23      <0=> Secure <1=> Non-Secure
//   <h> EPWM
//   <o.24>  EPWM0      <0=> Secure <1=> Non-Secure
//   <o.25>  EPWM1      <0=> Secure <1=> Non-Secure
//   <o.26>  BPWM0      <0=> Secure <1=> Non-Secure
//   <o.27>  BPWM1      <0=> Secure <1=> Non-Secure
//   </h>
*/
#define SCU_INIT_PNSSET2_VAL      0xFFFFFFFD
/*
    PNSSET3
*/
/*
// Module 0..31
//   <h>  SPI
//   <o.0>  QSPI0       <0=> Secure <1=> Non-Secure
//   <o.1>  SPI0   <0=> Secure <1=> Non-Secure
//   <o.2>  SPI1      <0=> Secure <1=> Non-Secure
//   <o.3>  SPI2    <0=> Secure <1=> Non-Secure
//   <o.4>  SPI3      <0=> Secure <1=> Non-Secure
//   </h>
//   <h> UART
//   <o.16>  UART0      <0=> Secure <1=> Non-Secure
//   <o.17>  UART1      <0=> Secure <1=> Non-Secure
//   <o.18>  UART2      <0=> Secure <1=> Non-Secure
//   <o.19>  UART3      <0=> Secure <1=> Non-Secure
//   <o.20>  UART4      <0=> Secure <1=> Non-Secure
//   <o.21>  UART5      <0=> Secure <1=> Non-Secure
//   </h>
*/
#define SCU_INIT_PNSSET3_VAL      0xFFFFFFFF
/*
    PNSSET4
*/
/*
// Module 0..31
//   <h> I2C
//   <o.0>  I2C0       <0=> Secure <1=> Non-Secure
//   <o.1>  I2C1   <0=> Secure <1=> Non-Secure
//   <o.2>  I2C2      <0=> Secure <1=> Non-Secure
//   </h>
//   <h> Smart Card
//   <o.16>  SC0      <0=> Secure <1=> Non-Secure
//   <o.17>  SC1      <0=> Secure <1=> Non-Secure
//   <o.18>  SC2      <0=> Secure <1=> Non-Secure
//   </h>
*/
#define SCU_INIT_PNSSET4_VAL      0xFFFFFFFF
/*
    PNSSET5
*/
/*
// Module 0..31
//   <o.0>  CAN0       <0=> Secure <1=> Non-Secure
//   <h> QEI
//   <o.16>  QEI0   <0=> Secure <1=> Non-Secure
//   <o.17>  QEI1      <0=> Secure <1=> Non-Secure
//   </h>
//   <h> ECAP
//   <o.20>  ECAP0    <0=> Secure <1=> Non-Secure
//   <o.21>  ECAP1      <0=> Secure <1=> Non-Secure
//   </h>
//   <o.25>  TRNG    <0=> Secure <1=> Non-Secure
*/
#define SCU_INIT_PNSSET5_VAL      0xFFFFFFFF
/*
    PNSSET6
*/
/*
// Module 0..31
//   <o.0>  USBD       <0=> Secure <1=> Non-Secure
//   <h> USCI
//   <o.16>  USCI0   <0=> Secure <1=> Non-Secure
//   <o.17>  USCI1      <0=> Secure <1=> Non-Secure
//   </h>
*/
#define SCU_INIT_PNSSET6_VAL      0xFFFFFFFF
/*
// </h>
*/



/*
// <h> GPIO Secure Attribution Configuration
*/

/*
    IONSSET
*/
/*
// Bit 0..31
//   <o.0>  PA       <0=> Secure <1=> Non-Secure
//   <o.1>  PB   <0=> Secure <1=> Non-Secure
//   <o.2>  PC      <0=> Secure <1=> Non-Secure
//   <o.3>  PD    <0=> Secure <1=> Non-Secure
//   <o.4>  PE      <0=> Secure <1=> Non-Secure
//   <o.5>  PF      <0=> Secure <1=> Non-Secure
//   <o.6>  PG      <0=> Secure <1=> Non-Secure
//   <o.7>  PH      <0=> Secure <1=> Non-Secure
*/
#define SCU_INIT_IONSSET_VAL      0xFFFFFFFF
/*
// </h>
*/

/* ---------------------------------------------------------------------------------------------------- */

/*
// <e>Secure Attribute Unit (SAU) Control
*/
#define SAU_INIT_CTRL 1

/*
//   <q> Enable SAU
//   <i> To enable Secure Attribute Unit (SAU).
*/
#define SAU_INIT_CTRL_ENABLE 1

/*
//   <o> All Memory Attribute When SAU is disabled
//     <0=> All Memory is Secure
//     <1=> All Memory is Non-Secure
//   <i> To set the ALLNS bit in SAU CTRL.
//   <i> When all Memory is Non-Secure (ALLNS is 1), IDAU can override memory map configuration.
*/
#define SAU_INIT_CTRL_ALLNS  0

/*
// </e>
*/


/*
// <h>Enable and Set Secure/Non-Secure region
*/
#define SAU_REGIONS_MAX   8                 /* Max. number of SAU regions */

/*
//   <e>SAU Region 0
//   <i> Setup SAU Region 0
*/
#define SAU_INIT_REGION0    0
/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START0     0x0003F000      /* start address of SAU region 0 */
/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END0       0x0003FFFF      /* end address of SAU region 0 */
/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC0       1
/*
//   </e>
*/

/*
//   <e>SAU Region 1
//   <i> Setup SAU Region 1
*/
#define SAU_INIT_REGION1    0
/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START1     0x10040000
/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END1       0x1007FFFF
/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC1       0
/*
//   </e>
*/

/*
//   <e>SAU Region 2
//   <i> Setup SAU Region 2
*/
#define SAU_INIT_REGION2    0
/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START2     0x2000F000
/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END2       0x2000FFFF
/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC2       1
/*
//   </e>
*/

/*
//   <e>SAU Region 3
//   <i> Setup SAU Region 3
*/
#define SAU_INIT_REGION3    1
/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START3     NU_TZ_NSC_REGION_START
/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END3       (NU_TZ_NSC_REGION_START + NU_TZ_NSC_REGION_SIZE - 1)
/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC3       1
/*
//   </e>
*/

/*
   <e>SAU Region 4
   <i> Setup SAU Region 4
*/
#define SAU_INIT_REGION4    1
/*
     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START4     FMC_NON_SECURE_BASE      /* start address of SAU region 4 */

/*
     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END4       0x1007FFFF      /* end address of SAU region 4 */

/*
     <o>Region is
         <0=>Non-Secure
         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC4       0
/*
   </e>
*/

/*
   <e>SAU Region 5
   <i> Setup SAU Region 5
*/
#define SAU_INIT_REGION5    1

/*
     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START5     0x00807E00

/*
     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END5       0x00807FFF

/*
     <o>Region is
         <0=>Non-Secure
         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC5       1
/*
   </e>
*/

/*
   <e>SAU Region 6
   <i> Setup SAU Region 6
*/
#define SAU_INIT_REGION6    1

/*
     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START6     NON_SECURE_SRAM_BASE

/*
     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END6       0x30017FFF

/*
     <o>Region is
         <0=>Non-Secure
         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC6       0
/*
   </e>
*/

/*
   <e>SAU Region 7
   <i> Setup SAU Region 7
*/
#define SAU_INIT_REGION7    1

/*
     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START7     0x50000000

/*
     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END7       0x5FFFFFFF

/*
     <o>Region is
         <0=>Non-Secure
         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC7       0
/*
   </e>
*/

/*
// </h>
*/

/*
// <e>Setup behavior of Sleep and Exception Handling
*/
#define SCB_CSR_AIRCR_INIT  1

/*
//   <o> Deep Sleep can be enabled by
//     <0=>Secure and Non-Secure state
//     <1=>Secure state only
//   <i> Value for SCB->CSR register bit DEEPSLEEPS
*/
#define SCB_CSR_DEEPSLEEPS_VAL  0

/*
//   <o>System reset request accessible from
//     <0=> Secure and Non-Secure state
//     <1=> Secure state only
//   <i> Value for SCB->AIRCR register bit SYSRESETREQS
*/
#define SCB_AIRCR_SYSRESETREQS_VAL  0

/*
//   <o>Priority of Non-Secure exceptions is
//     <0=> Not altered
//     <1=> Lowered to 0x80-0xFF
//   <i> Value for SCB->AIRCR register bit PRIS
*/
#define SCB_AIRCR_PRIS_VAL      0

/* Assign HardFault to be always secure for safe */
#define SCB_AIRCR_BFHFNMINS_VAL 0

/*
// </e>
*/


/*
// <h>Assign Interrupt to Secure or Non-secure Vector
*/


/*
    Initialize ITNS 0 (Interrupts 0..31)
*/
#define NVIC_INIT_ITNS0    1
/*
// BODOUT       Always secure
// IRC          Always secure
// PWRWU_       Always secure
// SRAM_PERR    Always secure
// CLKFAIL      Always secure

//   <o.6>  RTC                   <0=> Secure <1=> Non-Secure
//   <o.7>  TAMPER                <0=> Secure <1=> Non-Secure
// WDT  Always secure
// WWDT Always secure
//   <h> EINT
//   <o.10> EINT0                 <0=> Secure <1=> Non-Secure
//   <o.11> EINT1                 <0=> Secure <1=> Non-Secure
//   <o.12> EINT2                 <0=> Secure <1=> Non-Secure
//   <o.13> EINT3                 <0=> Secure <1=> Non-Secure
//   <o.14> EINT4                 <0=> Secure <1=> Non-Secure
//   <o.15> EINT5                 <0=> Secure <1=> Non-Secure
//   </h>
//   <h> GPIO
//   <o.16> GPA                   <0=> Secure <1=> Non-Secure
//   <o.17> GPB                   <0=> Secure <1=> Non-Secure
//   <o.18> GPC                   <0=> Secure <1=> Non-Secure
//   <o.19> GPD                   <0=> Secure <1=> Non-Secure
//   <o.20> GPE                   <0=> Secure <1=> Non-Secure
//   <o.21> GPF               <0=> Secure <1=> Non-Secure
//   </h>
//   <o.22> QSPI0              <0=> Secure <1=> Non-Secure
//   <o.23> SPI0              <0=> Secure <1=> Non-Secure
//   <h> EPWM
//   <o.24> BRAKE0            <0=> Secure <1=> Non-Secure
//   <o.25> EPWM0_P0          <0=> Secure <1=> Non-Secure
//   <o.26> EPWM0_P1          <0=> Secure <1=> Non-Secure
//   <o.27> EPWM0_P2          <0=> Secure <1=> Non-Secure
//   <o.28> BRAKE1            <0=> Secure <1=> Non-Secure
//   <o.29> EPWM1_P0          <0=> Secure <1=> Non-Secure
//   <o.30> EPWM1_P1          <0=> Secure <1=> Non-Secure
//   <o.31> EPWM1_P2          <0=> Secure <1=> Non-Secure
//   </h>
//
*/
#define NVIC_INIT_ITNS0_VAL      0xFFFFFFBF

/*
    Initialize ITNS 1 (Interrupts 0..31)
*/
#define NVIC_INIT_ITNS1    1
/*
//   <h> TIMER
// TMR0 Always secure
// TMR1 Always secure
//   <o.2>  TMR2              <0=> Secure <1=> Non-Secure
//   <o.3>  TMR3              <0=> Secure <1=> Non-Secure
//   </h>
//   <o.4>  UART0             <0=> Secure <1=> Non-Secure
//   <o.5>  UART1             <0=> Secure <1=> Non-Secure
//   <o.6>  I2C0              <0=> Secure <1=> Non-Secure
//   <o.7>  I2C1              <0=> Secure <1=> Non-Secure
// PDMA0 is secure only
//   <o.9>  DAC               <0=> Secure <1=> Non-Secure
//   <o.10> EADC0             <0=> Secure <1=> Non-Secure
//   <o.11> EADC1             <0=> Secure <1=> Non-Secure
//   <o.12> ACMP01            <0=> Secure <1=> Non-Secure

//   <o.14> EADC2             <0=> Secure <1=> Non-Secure
//   <o.15> EADC3             <0=> Secure <1=> Non-Secure
//   <o.16> UART2             <0=> Secure <1=> Non-Secure
//   <o.17> UART3             <0=> Secure <1=> Non-Secure

//   <o.19> SPI1              <0=> Secure <1=> Non-Secure
//   <o.20> SPI2              <0=> Secure <1=> Non-Secure
//   <o.21> USBD              <0=> Secure <1=> Non-Secure
//   <o.22> USBH              <0=> Secure <1=> Non-Secure
//   <o.23> USBOTG            <0=> Secure <1=> Non-Secure
//   <o.24> CAN0              <0=> Secure <1=> Non-Secure

//   <h> Smart Card
//   <o.26> SC0               <0=> Secure <1=> Non-Secure
//   <o.27> SC1               <0=> Secure <1=> Non-Secure
//   <o.28> SC2               <0=> Secure <1=> Non-Secure
//   </h>

//   <o.30> SPI3              <0=> Secure <1=> Non-Secure

//
*/
#define NVIC_INIT_ITNS1_VAL      0xFFFFFEFC

/*
    Initialize ITNS 2 (Interrupts 0..31)
*/
#define NVIC_INIT_ITNS2    1
/*
//   <o.0>  SDH0              <0=> Secure <1=> Non-Secure



//   <o.4>  I2S0              <0=> Secure <1=> Non-Secure

//
//   <o.7>  CRYPTO                <0=> Secure <1=> Non-Secure
//   <o.8>  GPG               <0=> Secure <1=> Non-Secure
//   <o.9>  EINT6             <0=> Secure <1=> Non-Secure
//   <o.10> UART4             <0=> Secure <1=> Non-Secure
//   <o.11> UART5             <0=> Secure <1=> Non-Secure
//   <o.12> USCI0             <0=> Secure <1=> Non-Secure
//   <o.13> USCI1             <0=> Secure <1=> Non-Secure
//   <o.14> BPWM0             <0=> Secure <1=> Non-Secure
//   <o.15> BPWM1             <0=> Secure <1=> Non-Secure


//   <o.18> I2C2              <0=> Secure <1=> Non-Secure

//   <o.20> QEI0              <0=> Secure <1=> Non-Secure
//   <o.21> QEI1              <0=> Secure <1=> Non-Secure
//   <o.22> ECAP0             <0=> Secure <1=> Non-Secure
//   <o.23> ECAP1             <0=> Secure <1=> Non-Secure
//   <o.24> GPH               <0=> Secure <1=> Non-Secure
//   <o.25> EINT7             <0=> Secure <1=> Non-Secure


//   <o.28> USBH              <0=> Secure <1=> Non-Secure



//
*/
#define NVIC_INIT_ITNS2_VAL      0xFFFFFFFF


/*
    Initialize ITNS 3 (Interrupts 0..31)
*/
#define NVIC_INIT_ITNS3    1
/*
//   <o.2>  PDMA1             <0=> Secure <1=> Non-Secure
// SCU  Always secure
//
//   <o.5>  TRNG              <0=> Secure <1=> Non-Secure
*/
#define NVIC_INIT_ITNS3_VAL      0xFFFFFFFF



/*
// </h>
*/

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)

/*
    max 128 SAU regions.
    SAU regions are defined in partition.h
 */

#if TFM_LVL == 0
#define SAU_INIT_REGION(n) \
    SAU->RNR  =  (n                                     & SAU_RNR_REGION_Msk); \
    SAU->RBAR =  (SAU_INIT_START##n                     & SAU_RBAR_BADDR_Msk); \
    SAU->RLAR =  (SAU_INIT_END##n                       & SAU_RLAR_LADDR_Msk) | \
                ((SAU_INIT_NSC##n << SAU_RLAR_NSC_Pos)  & SAU_RLAR_NSC_Msk)   | 1U
#else
#define SAU_INIT_REGION(n, tfm_n) \
    SAU->RNR  =  (tfm_n                                 & SAU_RNR_REGION_Msk); \
    SAU->RBAR =  (SAU_INIT_START##n                     & SAU_RBAR_BADDR_Msk); \
    SAU->RLAR =  (SAU_INIT_END##n                       & SAU_RLAR_LADDR_Msk) | \
                ((SAU_INIT_NSC##n << SAU_RLAR_NSC_Pos)  & SAU_RLAR_NSC_Msk)   | 1U
#endif


#if TFM_LVL > 0

#if SCB_AIRCR_SYSRESETREQS_VAL == 0
#warning ("TFM requests SCB_AIRCR_SYSRESETREQS_VAL be 1!!!")
#endif

#endif

#if SCB_AIRCR_SYSRESETREQS_VAL == 1
#warning ("Debugger (and other) resets fail when SCB_AIRCR_SYSRESETREQS_VAL == 1!!!")
#endif

/**
  * \brief   Setup SAU regions
  * \details Writes the region information contained in SAU_Region to the
  *          registers SAU_RNR, SAU_RBAR, and SAU_RLAR
  */
void TZ_SAU_Setup(void);

/**
  * \brief   Setup System Control Block
  */
void SCB_Setup(void);

/**
 * \brief   Setup NVIC interrupt target state
 */
void TZ_NVIC_Setup(void);

/**
  *\brief   Setup SCU Configuration Unit
  */
void SCU_Setup(void);

/**
  * \brief  Configure Non-secure flash boundary for the first time after Mass Erase or
  *         check if flash partition matches SCU.FNSADDR which has already configured
  *         and fixed until next Mass Erase.
  */
void FMC_NSBA_Setup(void);

#endif  /* #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

#ifdef __cplusplus
}
#endif

#endif  /* PARTITION_M2351 */
