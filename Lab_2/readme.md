karasik@karasik-PC:~/Eltex_5/Lab_2$ make

karasik@karasik-PC:~/Eltex_5/Lab_2$ sudo su

root@karasik-PC:/home/karasik/Eltex_5/Lab_2# insmod proc.ko

root@karasik-PC:/home/karasik/Eltex_5/Lab_2# echo "Hello World" > /proc/hello

root@karasik-PC:/home/karasik/Eltex_5/Lab_2# cat /proc/hello

Hello World

root@karasik-PC:/home/karasik/Eltex_5/Lab_2# rmmod proc.ko

root@karasik-PC:/home/karasik/Eltex_5/Lab_2# make clean

root@karasik-PC:/home/karasik/Eltex_5/Lab_2# exit

exit

karasik@karasik-PC:~/Eltex_5/Lab_2$

