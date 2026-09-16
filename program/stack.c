#include<stdio.h>
	int f(void);
	int f1(void);
	int f2(void);
int main()
{

	f();
};

int f(void)
{
	printf("I am in function f\n");
	f1();
	return 3;
}

int f1(void)
{
	printf("I am in fucntion f1\n");
	f2();
	return 2;
}

int f2(void)
{
	printf("I am in function f2\n");
	return 1;
}
