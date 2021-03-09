ccflags-y += -std=gnu99
ccflags-y += -Wdeclaration-after-statement
ccflags-y += -lwiringPi
obj-m := us_service.o

KDIR = /lib/modules/$(shell uname -r)/build


all:
	make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) clean
