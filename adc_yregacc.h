/**********************************************************************
 *
 * Copyright (c) Vayavya Labs Pvt. Ltd.  2019
 *
 * THIS IS A DEVICE DRIVER GENERATED USING VAYAVYA LABS' DDGen TOOL.
 * THIS DRIVER WAS GENERATED FOR THE FOLLOWING SPECS:
 *
 * Device: adc
 * Device Manufacturer:  STMicroelectronics
 * Operating System: None
 *
 * DPS Reference ID: 887760:200:784:1884
 * RTS Reference ID: 47571:14:4294967295:21
 *
 * THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND. TO
 * THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, VAYAVYA LABS Pvt Ltd.
 * DISCLAIMS ALL WARRANTIES, EXPRESSED OR IMPLIED, INCLUDING, BUT NOT
 * LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT, WITH REGARD
 * TO THE SOFTWARE.
 *
 * VAYAVYA LABS Pvt.Ltd. SHALL BE RELIEVED OF ANY AND ALL OBLIGATIONS
 * WITH RESPECT TO THIS SECTION FOR ANY PORTIONS OF THE SOFTWARE THAT
 * ARE REVISED, CHANGED, MODIFIED, OR MAINTAINED BY ANYONE OTHER THAN
 * VAYAVYA LABS Pvt.Ltd.
 *
 ***********************************************************************/

#ifndef __adc__REGACC__H__

#define __adc__REGACC__H__


#define BASE_ADDRESS pdata->base_addr

/* Register offset macros */
#define ADC_ADC_CCR (BASE_ADDRESS + 0x304)
#define ADC_ADC_DR (BASE_ADDRESS + 0x4c)
#define ADC_ADC_SQR3 (BASE_ADDRESS + 0x34)
#define ADC_ADC_SQR1 (BASE_ADDRESS + 0x2c)
#define ADC_ADC_SMPR1 (BASE_ADDRESS + 0xc)
#define ADC_ADC_CR2 (BASE_ADDRESS + 0x8)
#define ADC_ADC_CR1 (BASE_ADDRESS + 0x4)
#define ADC_ADC_SR (BASE_ADDRESS + 0)


/* Register field MASK macros */
#define ADC_ADC_CCR_ADCPRE_MASK 0x30000
#define ADC_ADC_DR_DATA_MASK 0xffff
#define ADC_ADC_SQR3_SQ1_MASK 0x1f
#define ADC_ADC_SQR1_L_MASK 0xf00000
#define ADC_ADC_SMPR1_SMP12_MASK 0x1c0
#define ADC_ADC_CR2_SWSTART_MASK 0x40000000
#define ADC_ADC_CR2_ALIGN_MASK 0x800
#define ADC_ADC_CR2_EOCS_MASK 0x400
#define ADC_ADC_CR2_CONT_MASK 0x2
#define ADC_ADC_CR2_ADON_MASK 0x1
#define ADC_ADC_CR1_RES_MASK 0x3000000
#define ADC_ADC_SR_EOC_MASK 0x2


/* Register field LPOS macros */
#define ADC_ADC_CCR_ADCPRE_LPOS 16
#define ADC_ADC_DR_DATA_LPOS 0
#define ADC_ADC_SQR3_SQ1_LPOS 0
#define ADC_ADC_SQR1_L_LPOS 20
#define ADC_ADC_SMPR1_SMP12_LPOS 6
#define ADC_ADC_CR2_SWSTART_LPOS 30
#define ADC_ADC_CR2_ALIGN_LPOS 11
#define ADC_ADC_CR2_EOCS_LPOS 10
#define ADC_ADC_CR2_CONT_LPOS 1
#define ADC_ADC_CR2_ADON_LPOS 0
#define ADC_ADC_CR1_RES_LPOS 24
#define ADC_ADC_SR_EOC_LPOS 1

#define REGR32(reg) read32((const volatile void *)reg, pdata->context)

#define REGW32(reg, value) write32(value, (volatile void *)reg, pdata->context)

#define REGR32_FIELD(offset, field) ((REGR32(offset) &\
	(offset##_##field##_MASK)) >> (offset##_##field##_LPOS))

#define REGW32_FIELD(offset, field, value)\
	(REGW32(offset, ((REGR32(offset) &\
	(~(offset##_##field##_MASK))) |\
	((value) << (offset##_##field##_LPOS)))))


#define GET_VALUE(data, lbit, hbit) ((data >> lbit) & (~(~0 << (hbit - lbit+1))))

#endif
