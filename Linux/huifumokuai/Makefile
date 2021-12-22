CONFIG_MODULE_SIG=n
#KERNELDIR:=/home/zjy/kernel/linux-source-4.15.0
#KERNELDIR:=/home/zjy/kernel/linux-4.4.1
KERNELDIR:=/lib/modules/$(shell uname -r)/build
PWD:=`pwd`
all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
obj-m:=force_rmmod.o
