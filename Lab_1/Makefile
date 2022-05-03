all: staticDiv staticDivTest dyn-staticDiv dynStaticDivTest dynDiv dynDivTest clean

staticDiv: libdiv.a
	gcc programm.c -L. -ldiv -o staticDiv

libdiv.a:
	gcc -c funFirst.c funSecond.c
	ar rc libdiv.a funFirst.o funSecond.o
	ranlib libdiv.a

staticDivTest:
	./staticDiv 7 2
	./staticDiv

dyn-staticDiv: libdyndiv.so
	gcc programm.c -L. -ldiv -o dynStaticDiv
	LD_LIBRARY_PATH=/root:${LD_LIBRARY_PATH}
	export LD_LIBRARY_PATH

libdyndiv.so: labdivpic.o
	gcc -shared funFirst.c funSecond.c -o libdyndiv.so

labdivpic.o: 
	gcc -fPIC -c funFirst.c funSecond.c

dynStaticDivTest:
	./dynStaticDiv 7 2
	./dynStaticDiv

dynDiv: libdyn.so
	gcc programmDynamic.c -o dynDiv -ldl

libdyn.so: labdivpic.o
	gcc -shared funFirst.c funSecond.c -o libdyn.so

dynDivTest:
	./dynDiv 7 2
	./dynDiv

clean:
	rm -f *.o *.a *.so programm staticDiv dynStaticDiv dynDiv

 
