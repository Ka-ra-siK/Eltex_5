#Текст с терминала:

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ make

make -C /lib/modules/5.15.0-27-generic/build M=/home/karasik/Eltex/Lab_3_Chardev modules

make[1]: вход в каталог «/usr/src/linux-headers-5.15.0-27-generic»

  CC [M]  /home/karasik/Eltex/Lab_3_Chardev/chardev.o
  
  MODPOST /home/karasik/Eltex/Lab_3_Chardev/Module.symvers
  
  CC [M]  /home/karasik/Eltex/Lab_3_Chardev/chardev.mod.o
  
  LD [M]  /home/karasik/Eltex/Lab_3_Chardev/chardev.ko
  
  BTF [M] /home/karasik/Eltex/Lab_3_Chardev/chardev.ko
  
Skipping BTF generation for /home/karasik/Eltex/Lab_3_Chardev/chardev.ko due to unavailability of vmlinux

make[1]: выход из каталога «/usr/src/linux-headers-5.15.0-27-generic»

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo insmod chardev.ko

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo cat /dev/chardev

I already told you 0 times Hello world!

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo cat /dev/chardev 

I already told you 1 times Hello world!

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo cat /dev/chardev 

I already told you 2 times Hello world!

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo cat /dev/chardev 

I already told you 3 times Hello world!

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo cat /dev/chardev 

I already told you 4 times Hello world!

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo cat /dev/chardev 

I already told you 5 times Hello world!

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ sudo rmmod chardev.ko

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ make clean

make -C /lib/modules/5.15.0-27-generic/build M=/home/karasik/Eltex/Lab_3_Chardev clean

make[1]: вход в каталог «/usr/src/linux-headers-5.15.0-27-generic»

  CLEAN   /home/karasik/Eltex/Lab_3_Chardev/Module.symvers
  
make[1]: выход из каталога «/usr/src/linux-headers-5.15.0-27-generic»

karasik@karasik-PC:~/Eltex/Lab_3_Chardev$ ls

chardev.c  Makefile
