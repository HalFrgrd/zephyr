/*
 * Copyright (c) 2023 Nuvoton Technology Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _NUVOTON_NPCX_SOC_H_
#define _NUVOTON_NPCX_SOC_H_

/* CMSIS required definitions */
#define __FPU_PRESENT  CONFIG_CPU_HAS_FPU
#define __MPU_PRESENT  CONFIG_CPU_HAS_ARM_MPU

/* NPCX4 SCFG multi-registers */
#define NPCX_DEVALT_OFFSET(n)		(0x010 + n)
#define NPCX_PUPD_EN_OFFSET(n)		(0x02b + n)
#define NPCX_LV_GPIO_CTL_OFFSET(n)	(0x150 + n)
#define NPCX_DEVALT_LK_OFFSET(n)	(0x210 + n)

/* NPCX4 MIWU multi-registers */
#define NPCX_WKEDG_OFFSET(n)		(0x000 + (n * 0x010))
#define NPCX_WKAEDG_OFFSET(n)		(0x001 + (n * 0x010))
#define NPCX_WKMOD_OFFSET(n)		(0x002 + (n * 0x010))
#define NPCX_WKPND_OFFSET(n)		(0x003 + (n * 0x010))
#define NPCX_WKPCL_OFFSET(n)		(0x004 + (n * 0x010))
#define NPCX_WKEN_OFFSET(n)		(0x005 + (n * 0x010))
#define NPCX_WKST_OFFSET(n)		(0x006 + (n * 0x010))
#define NPCX_WKINEN_OFFSET(n)		(0x007 + (n * 0x010))

/* NPCX4 ADC multi-registers */
#define NPCX_CHNDAT_OFFSET(n)		(0x040 + n * 2)
#define NPCX_THRCTL_OFFSET(n)		(0x080 + n * 2)
#define NPCX_THEN_OFFSET		0x090
#define THEN(base)			(*(volatile uint16_t *)(base + NPCX_THEN_OFFSET))

/* NPCX4 ADC register fields */
#define NPCX_THRCTL_L_H			15
#define NPCX_THRCTL_CHNSEL		FIELD(10, 5)
#define NPCX_THRCTL_THRVAL		FIELD(0, 10)

/* NPCX4 FIU register fields */
#define NPCX_FIU_EXT_CFG_SPI1_2DEV	6

/* NPCX4 supported group mask of DEVALT_LK */
#define NPCX_DEVALT_LK_GROUP_MASK \
	(BIT(0) | BIT(2) | BIT(3) | BIT(4) | \
	 BIT(5) | BIT(6) | BIT(11) | BIT(13) | \
	 BIT(15) | BIT(16) | BIT(17) | BIT(18) | \
	 BIT(19) | BIT(21))	/* DEVALT0_LK - DEVALTN_LK */

/* NPCX4 Clock Configuration */
#define MAX_OFMCLK 120000000

#include <reg/reg_access.h>
#include <reg/reg_def.h>
#include <soc_dt.h>
#include <soc_clock.h>
#include <soc_pins.h>
#include <soc_power.h>

/* NPCX4 Clock definitions */
#if DT_NODE_HAS_PROP(DT_NODELABEL(pcc), apb4_prescaler)
/* APB4 clock divider if supported */
#define APB4DIV_VAL (DT_PROP(DT_NODELABEL(pcc), apb4_prescaler) - 1)
#endif

#if (CORE_CLK > (MAX_OFMCLK / 2))
#define FIU1DIV_VAL 1 /* If CORE_CLK > MAX_OFMCLK / 2, FIU1_CLK = CORE_CLK/2 */
#else
#define FIU1DIV_VAL 0 /* Else, FIU1_CLK = CORE_CLK */
#endif

#endif /* _NUVOTON_NPCX_SOC_H_ */
