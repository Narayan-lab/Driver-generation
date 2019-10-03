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

#ifndef __adc__YHEADER__

#define __adc__YHEADER__

/* Macro definitions*/

#define Y_TRUE 1
#define Y_FALSE 0
#define Y_SUCCESS 0
#define Y_FAILURE 1
#define Y_INV_WR 1
#define Y_INV_RD 2
#define Y_INV_ARG 3
#define Y_MAX_THRD_XEEDED 4
#ifndef _STDIO_H
#define NULL ((void *)0)
#define UINT_MAX (~0U)
#endif

/* TODO: Proto-type of the functions */
void *adc_alloc_pdata(void);
static void *mem_alloc (unsigned int, int, unsigned int *, unsigned int);
static void mem_free (void *, int, int);

/* TODO: macros used in wrapper structure for allcoation */
#define DMA_ALLOC    0
#define NO_DMA_ALLOC 1

/* TODO: Error macros used when function returns error */
#define ENOMEM   12
#define EIO      13

/* Macros for descriptor align and buffer align*/
#define  NO_ALIGN 0
/* TODO Macros to map code for delay */
#define CALL_TIMER(x)





/* C data types typedefs */





struct adc_prv_data {
	  
	unsigned int mem_start_addr;
	unsigned int mem_size;
	unsigned int irq_number;
	unsigned char *base_addr;

	void *context;
};


struct adc_device_apis {
	int (*adc_conv)(unsigned int, unsigned int *, struct adc_prv_data *);
	int (*config_channel)(unsigned int, unsigned int, unsigned int, struct adc_prv_data *);
	int (*configure_adc_parameters)(unsigned int, unsigned int, unsigned int, struct adc_prv_data *);
	int (*configure_adc_clock)(unsigned int, struct adc_prv_data *);
};



/* <<< 10 EXPFEAT */

/* <<< 40 INIFINI */


#endif
