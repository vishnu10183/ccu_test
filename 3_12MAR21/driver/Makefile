obj-m += driver_ultraS_3.o

KDIR = /lib/modules/$(shell uname -r)/build


all:
	make -C $(KDIR) M=$(shell pwd) modules

install:
	make -C $(KDIR) M=$(shell pwd) module_install

clean:
	make -C $(KDIR) M=$(shell pwd) clean