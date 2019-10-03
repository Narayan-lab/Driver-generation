/**********************************************************************
 *
 * Copyright (c) Vayavya Labs Pvt. Ltd.  2018
 *
 * THIS IS A DEVICE DRIVER GENERATED USING VAYAVYA LABS' DDGen TOOL.
 * THIS DRIVER WAS GENERATED FOR THE FOLLOWING SPECS:
 *
 * Device: pwm
 * Device Manufacturer: NXP_semiconductor
 * Operating System: None
 *
 * DPS Reference ID: 1152058:244:784:1748
 * RTS Reference ID: 51903:14:4294967295:21
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

#ifndef __ENV_H__

#define __ENV_H__

/* TODO: Replace outln do{ }while (0)
 * with approriate native print function
 */
#define outln(x...) do {} while (0)
#ifdef YDEBUG
#define DBGPR(x...) outln(x...)
#else
#define DBGPR(x...) do {} while (0)
#endif
/* TODO: Replace with approriate native print function */
#define DEBUG_MSG printf


/* Common read write Macros for No_OS */
static inline unsigned char read8(const volatile void *reg_addr, void *context)
{
	return *(const volatile unsigned char *)(reg_addr);
}

static inline void write8(const unsigned char value, volatile void *reg_addr, void *context)
{
	*(volatile unsigned char *)(reg_addr) = value;
}

static inline unsigned short read16(const volatile void *reg_addr, void *context)
{
	return *(const volatile unsigned short *)(reg_addr);
}

static inline void write16(const unsigned short value, volatile void *reg_addr, void *context)
{
	*(volatile unsigned short *)(reg_addr) = value;
}

static inline unsigned int read32(const volatile void *reg_addr, void *context)
{
	return *(const volatile unsigned int *)(reg_addr);
}

static inline void write32(const unsigned int value, volatile void *reg_addr, void *context)
{
	*(volatile unsigned int *)(reg_addr) = value;
}

static void *mem_alloc(unsigned int size, int dma_mem_req, unsigned int *dma_addr, unsigned int alloc_align)
{
	return NULL;
}
static void mem_free(void *ptr, int dma_mem_req, int dma_addr)
{
}

#endif
