Lab 2:
karasik@karasik-PC:~/Eltex_5/Lab_2$ make
make -C /lib/modules/5.15.0-27-generic/build M=/home/karasik/Eltex_5/Lab_2 modules
make[1]: вход в каталог «/usr/src/linux-headers-5.15.0-27-generic»
CC [M] /home/karasik/Eltex_5/Lab_2/proc.o
/home/karasik/Eltex_5/Lab_2/proc.c: In function ‘read_proc’:
/home/karasik/Eltex_5/Lab_2/proc.c:17:5: warning: ignoring return value of ‘copy_to_user’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
17 | copy_to_user(buf,msg, count);
| ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/karasik/Eltex_5/Lab_2/proc.c: In function ‘write_proc’:
/home/karasik/Eltex_5/Lab_2/proc.c:25:5: warning: ignoring return value of ‘copy_from_user’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
25 | copy_from_user(msg,buf,count);
| ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MODPOST /home/karasik/Eltex_5/Lab_2/Module.symvers
CC [M] /home/karasik/Eltex_5/Lab_2/proc.mod.o
LD [M] /home/karasik/Eltex_5/Lab_2/proc.ko
BTF [M] /home/karasik/Eltex_5/Lab_2/proc.ko
Skipping BTF generation for /home/karasik/Eltex_5/Lab_2/proc.ko due to unavailability of vmlinux
make[1]: выход из каталога «/usr/src/linux-headers-5.15.0-27-generic»
karasik@karasik-PC:~/Eltex_5/Lab_2$ sudo su
[sudo] пароль для karasik:
root@karasik-PC:/home/karasik/Eltex_5/Lab_2# insmod proc.ko
root@karasik-PC:/home/karasik/Eltex_5/Lab_2# echo "Hello World" > /proc/hello
root@karasik-PC:/home/karasik/Eltex_5/Lab_2# cat /proc/hello
Hello World
root@karasik-PC:/home/karasik/Eltex_5/Lab_2# rmmod proc.ko
root@karasik-PC:/home/karasik/Eltex_5/Lab_2# make clean
make -C /lib/modules/5.15.0-27-generic/build M=/home/karasik/Eltex_5/Lab_2 clean
make[1]: вход в каталог «/usr/src/linux-headers-5.15.0-27-generic»
CLEAN /home/karasik/Eltex_5/Lab_2/Module.symvers
make[1]: выход из каталога «/usr/src/linux-headers-5.15.0-27-generic»
root@karasik-PC:/home/karasik/Eltex_5/Lab_2# exit
exit
karasik@karasik-PC:~/Eltex_5/Lab_2$
