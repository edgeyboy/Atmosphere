/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <vapours.hpp>

#define EMC_ADDRESS(x)  (0x7001B000 + x)
#define EMC0_ADDRESS(x) (0x7001E000 + x)
#define EMC1_ADDRESS(x) (0x7001F000 + x)

#define EMC_CFG                    (0x00C)
#define EMC_ADR_CFG                (0x010)
#define EMC_TIMING_CONTROL         (0x028)
#define EMC_SELF_REF               (0x0E0)
#define EMC_MRW                    (0x0E8)
#define EMC_FBIO_CFG5              (0x104)
#define EMC_MRW3                   (0x138)
#define EMC_AUTO_CAL_CONFIG        (0x2A4)
#define EMC_REQ_CTRL               (0x2B0)
#define EMC_EMC_STATUS             (0x2B4)
#define EMC_CFG_DIG_DLL            (0x2BC)
#define EMC_ZCAL_INTERVAL          (0x2E0)
#define EMC_PMC_SCRATCH3           (0x448)
#define EMC_FBIO_CFG7              (0x584)
#define EMC_PMACRO_CFG_PM_GLOBAL_0 (0xC30)
#define EMC_PMACRO_TRAINING_CTRL_0 (0xCF8)
#define EMC_PMACRO_TRAINING_CTRL_1 (0xCFC)

#define EMC_REG_BITS_MASK(NAME)                                      REG_NAMED_BITS_MASK    (EMC, NAME)
#define EMC_REG_BITS_VALUE(NAME, VALUE)                              REG_NAMED_BITS_VALUE   (EMC, NAME, VALUE)
#define EMC_REG_BITS_ENUM(NAME, ENUM)                                REG_NAMED_BITS_ENUM    (EMC, NAME, ENUM)
#define EMC_REG_BITS_ENUM_SEL(NAME, __COND__, TRUE_ENUM, FALSE_ENUM) REG_NAMED_BITS_ENUM_SEL(EMC, NAME, __COND__, TRUE_ENUM, FALSE_ENUM)

#define DEFINE_EMC_REG(NAME, __OFFSET__, __WIDTH__)                                                                                                                  REG_DEFINE_NAMED_REG           (EMC, NAME, __OFFSET__, __WIDTH__)
#define DEFINE_EMC_REG_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE)                                                                                                         REG_DEFINE_NAMED_BIT_ENUM      (EMC, NAME, __OFFSET__, ZERO, ONE)
#define DEFINE_EMC_REG_TWO_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE)                                                                                         REG_DEFINE_NAMED_TWO_BIT_ENUM  (EMC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE)
#define DEFINE_EMC_REG_THREE_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)                                                               REG_DEFINE_NAMED_THREE_BIT_ENUM(EMC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)
#define DEFINE_EMC_REG_FOUR_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN) REG_DEFINE_NAMED_FOUR_BIT_ENUM (EMC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN)

DEFINE_EMC_REG_BIT_ENUM(CFG_DYN_SELF_REF, 28, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(CFG_DRAM_ACPD,    29, NO_POWERDOWN, ACTIVE_POWERDOWN);

DEFINE_EMC_REG_BIT_ENUM(ADR_CFG_EMEM_NUMDEV, 0, N1, N2);

DEFINE_EMC_REG_BIT_ENUM(TIMING_CONTROL_TIMING_UPDATE, 0, DISABLED, ENABLED);

DEFINE_EMC_REG_BIT_ENUM(SELF_REF_SELF_REF_CMD, 0, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(SELF_REF_ACTIVE_SELF_REF, 8, DISABLED, ENABLED);
DEFINE_EMC_REG_TWO_BIT_ENUM(SELF_REF_SREF_DEV_SELECTN, 30, BOTH, DEV1, DEV0, RESERVED);

DEFINE_EMC_REG(MRW_OP,  0, 8);
DEFINE_EMC_REG(MRW_MA, 16, 8);
DEFINE_EMC_REG_TWO_BIT_ENUM(MRW_CNT, 26, SHORT, LONG, EXT1, EXT2);
DEFINE_EMC_REG_TWO_BIT_ENUM(MRW_DEV_SELECTN, 30, BOTH, DEV1, DEV0, RESERVED);

DEFINE_EMC_REG_TWO_BIT_ENUM(FBIO_CFG5_DRAM_TYPE, 0, DDR4, LPDDR4, LPDDR2, DDR2);

DEFINE_EMC_REG_BIT_ENUM(AUTO_CAL_CONFIG_AUTO_CAL_MEASURE_STALL,  9, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(AUTO_CAL_CONFIG_AUTO_CAL_UPDATE_STALL,  10, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(AUTO_CAL_CONFIG_AUTO_CAL_START,         31, DISABLE, ENABLE);

DEFINE_EMC_REG(REQ_CTRL_STALL_ALL_READS,  0, 1);
DEFINE_EMC_REG(REQ_CTRL_STALL_ALL_WRITES, 1, 1);

DEFINE_EMC_REG_TWO_BIT_ENUM(EMC_STATUS_DRAM_IN_SELF_REFRESH, 8, DISABLED, DEV0_ENABLED, DEV1_ENABLED, BOTH_ENABLED);

DEFINE_EMC_REG_BIT_ENUM(EMC_STATUS_DRAM_DEV0_IN_SELF_REFRESH, 8, DISABLED, ENABLED);

DEFINE_EMC_REG_BIT_ENUM(EMC_STATUS_NO_OUTSTANDING_TRANSACTIONS, 2, WAITING, COMPLETED);
DEFINE_EMC_REG_BIT_ENUM(EMC_STATUS_TIMING_UPDATE_STALLED, 23, DONE, BUSY);

DEFINE_EMC_REG_BIT_ENUM(CFG_DIG_DLL_CFG_DLL_EN, 0, DISABLED, ENABLED);

DEFINE_EMC_REG(ZCAL_INTERVAL_LO,  0, 10);
DEFINE_EMC_REG(ZCAL_INTERVAL_HI, 10, 14);

DEFINE_EMC_REG(PMC_SCRATCH3_DDR_CNTRL, 0, 19);
DEFINE_EMC_REG_BIT_ENUM(PMC_SCRATCH3_WEAK_BIAS, 30, DISABLED, ENABLED);

DEFINE_EMC_REG_BIT_ENUM(FBIO_CFG7_CH1_ENABLE, 2, DISABLE, ENABLE);

DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE0, 16, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE1, 17, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE2, 18, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE3, 19, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE4, 20, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE5, 21, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE6, 22, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_BYTE7, 23, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_CMD0,  24, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_CMD1,  25, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_CMD2,  26, DISABLE, ENABLE);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_CFG_PM_GLOBAL_0_DISABLE_CFG_CMD3,  27, DISABLE, ENABLE);

DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_0_CH0_TRAINING_ENABLED,        0, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_0_CH0_TRAINING_TRAIN_QPOP,     1, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_0_CH0_TRAINING_RX_E_DIRECT_ZI, 2, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_0_CH0_TRAINING_E_WRPTR,        3, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_0_CH0_TRAINING_DRV_DQS,        4, DISABLED, ENABLED);

DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_1_CH1_TRAINING_ENABLED,        0, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_1_CH1_TRAINING_TRAIN_QPOP,     1, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_1_CH1_TRAINING_RX_E_DIRECT_ZI, 2, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_1_CH1_TRAINING_E_WRPTR,        3, DISABLED, ENABLED);
DEFINE_EMC_REG_BIT_ENUM(PMACRO_TRAINING_CTRL_1_CH1_TRAINING_DRV_DQS,        4, DISABLED, ENABLED);
