#ifndef __adc__APPHDR__H__

#define __adc__APPHDR__H__



/* General status and error macros */
#define Y_TRUE 1
#define Y_FALSE 0
#define Y_SUCCESS 0
#define Y_FAILURE 1
#define Y_INV_WR 1
#define Y_INV_RD 2
#define Y_INV_ARG 3
#define Y_MAX_THRD_XEEDED 4


struct adc_prv_data {
	  
	unsigned int mem_start_addr;
	unsigned int mem_size;
	unsigned int irq_number;
	unsigned char *base_addr;

	void *context;
};

int adc_init(struct adc_prv_data *, void *);



void *adc_alloc_pdata(void);
void *adc_free_pdata(struct adc_prv_data *);
struct adc_device_apis;
struct adc_device_apis *adc_device_open(void);
struct adc_device_apis {
	int (*adc_conv)(unsigned int, unsigned int *, struct adc_prv_data *);
	int (*config_channel)(unsigned int, unsigned int, unsigned int, struct adc_prv_data *);
	int (*configure_adc_parameters)(unsigned int, unsigned int, unsigned int, struct adc_prv_data *);
	int (*configure_adc_clock)(unsigned int, struct adc_prv_data *);
};


/* <<< 10 EXPFEAT */

/* <<< 40 INIFINI */
#endif
