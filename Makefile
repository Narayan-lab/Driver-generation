-include rules.mk
COPTS=-c
INCDIR1=.
SRCS += adc_drv.c

default:
	$(COMPILER) $(COPTS) -I$(INCDIR) -I$(INCDIR1) -I$(ENV_INC_DIR) $(SRCS) -Wall
clean:
	rm -f *.o

