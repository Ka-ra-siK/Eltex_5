#include <stdio.h>
//Операции деления по модулю и нацело.
extern int divMod(int first, int second);

extern int divNum(int first, int second);

int main(int argc, char **argv){
	int n1, n2, num1, num2;

	if (argc == 1){
		num1 = 3;
		num2 = 2;
		n1 = divMod(num1, num2);
		n2 = divNum(num1, num2);
	}
	else{
		sscanf(argv[1], "%d", &num1);
		sscanf(argv[2], "%d", &num2);
		n1 = divMod(num1, num2);
		n2 = divNum(num1, num2);
	}

	printf("divMod(%d, %d) = %d\n", num1, num2, n1);
	printf("divNum(%d, %d) = %d\n", num1, num2, n2);

	return 0;
}
