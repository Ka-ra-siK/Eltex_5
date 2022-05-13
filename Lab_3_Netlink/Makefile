obj-m += network.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	make netlink

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	rm -f netlink