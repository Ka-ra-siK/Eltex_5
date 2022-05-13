#Текст с консоли:

karasik@karasik-PC:~/Eltex/Lab_3_Netlink$ make

karasik@karasik-PC:~/Eltex/Lab_3_Netlink$ sudo insmod network.ko

karasik@karasik-PC:~/Eltex/Lab_3_Netlink$ ./netlink 

Sending message to kernel pid=8441

Waiting for message from kernel

Received message payload: Hello from kernel

karasik@karasik-PC:~/Eltex/Lab_3_Netlink$ sudo rmmod network.ko

karasik@karasik-PC:~/Eltex/Lab_3_Netlink$ make clean
