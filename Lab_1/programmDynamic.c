#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
//Операции деления по модулю и нацело.
extern int divMod(int first, int second);

extern int divNum(int first, int second);

int main(int argc, char **argv){
	int n1, n2, num1, num2;
	void *libraryHandler;
	int (*divMod)(int, int);
	int (*divNum)(int, int);

	if (argc == 1){
		num1 = 3;
		num2 = 2;
	}
	else{
		sscanf(argv[1], "%d", &num1);
		sscanf(argv[2], "%d", &num2);
	}

	//загрузка библиотек
	libraryHandler = dlopen("./libdyn.so",RTLD_LAZY);
	if(!libraryHandler){
		fprintf(stderr,"dlopen() error: %s\n", dlerror());
		exit(1);
	}

	divMod = dlsym(libraryHandler, "divMod");
	divNum = dlsym(libraryHandler, "divNum");
	n1 = (divMod)(num1, num2);
	n2 = (divNum)(num1, num2);


	printf("divMod(%d, %d) = %d\n", num1, num2, n1);
	printf("divNum(%d, %d) = %d\n", num1, num2, n2);

	return 0;
}