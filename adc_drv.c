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

/*!@file adc_drv.c
 * @brief Driver functions.
 */

#include "adc_yheader.h"
#include "adc_yregacc.h"
#include "env.h"

int adc_gstatus;



/*!
 * \brief This function configure the ADC clock
* \param[in] prescale
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int configure_adc_clock(unsigned int prescale,
					struct adc_prv_data *pdata)
{

	REGW32_FIELD(ADC_ADC_CCR, ADCPRE, prescale);

	return Y_SUCCESS;
}




/*!
 * \brief this function Configure the ADC parameters
* \param[in] resolution
* \param[in] data_alignment
* \param[in] cont_bit
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int configure_adc_parameters(unsigned int resolution,
					unsigned int data_alignment,
					unsigned int cont_bit,
					struct adc_prv_data *pdata)
{

	REGW32_FIELD(ADC_ADC_CR1, RES, resolution);
	REGW32_FIELD(ADC_ADC_CR2, ALIGN, data_alignment);
	REGW32_FIELD(ADC_ADC_CR2, CONT, cont_bit);

	return Y_SUCCESS;
}




/*!
 * \brief This function is for Channel selection
* \param[in] channel_selection
* \param[in] sample_rate1
* \param[in] seq
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int config_channel(unsigned int channel_selection,
				unsigned int sample_rate1,
				unsigned int seq,
				struct adc_prv_data *pdata)
{

	REGW32_FIELD(ADC_ADC_SQR1, L, channel_selection);
	REGW32_FIELD(ADC_ADC_SMPR1, SMP12, sample_rate1);
	REGW32_FIELD(ADC_ADC_SQR3, SQ1, seq);

	return Y_SUCCESS;
}




/*!
 * \brief This function is for ADC conversion
* \param[in] adon_bit
* \param[out] data
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int adc_conv(unsigned int adon_bit,
			unsigned int *data,
			struct adc_prv_data *pdata)
{

	if (adon_bit == 1) {
		REGW32_FIELD(ADC_ADC_CR2, ADON, 1);
		REGW32_FIELD(ADC_ADC_CR2, SWSTART, 1);
		
	}

	/* Poll */
	while (1) {
	//	if (REGR32_FIELD(ADC_ADC_SR, EOC) == 1) {
		//	*data = REGR32_FIELD(ADC_ADC_DR, DATA);
			//REGW32_FIELD(ADC_ADC_CR2, EOCS, 0);
			//break;
		//}
	}
	CALL_TIMER(5000);

	return Y_SUCCESS;
}




static struct adc_device_apis adc_drv_apis = {
	.adc_conv = adc_conv,
	.config_channel = config_channel,
	.configure_adc_parameters = configure_adc_parameters,
	.configure_adc_clock = configure_adc_clock
};




/*!
* \brief Initialization routine
* \details init routine of the driver that handles device initialization,
 	  and driver variables required for the driver to operate.
*
* \param[in] None
* \return Returns successful execution of the routine
* \retval Y_SUCCESS Function executed successfully
*/


int adc_init(struct adc_prv_data *pdata,void *context)
{
	pdata->base_addr = (void *)0x40012000;
	pdata->context = context;


	return Y_SUCCESS ;
}

void *adc_alloc_pdata(void)
{
  void *ret = NULL;

  ret = mem_alloc(sizeof (struct adc_prv_data), NO_DMA_ALLOC, NULL, NO_ALIGN);
	return ret;
}

void adc_free_pdata(struct adc_prv_data *pdata)
{
   mem_free(pdata, NO_DMA_ALLOC, 0);
}

struct adc_device_apis *adc_device_open()
{
	return &adc_drv_apis;
	
}



