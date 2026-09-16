#include<stdio.h>
int main()
{

	void swap_values (int *, int *);

	int i = 10;
	int j = 20;

	swap_values(&i, &j);

	printf("The value after swap is:%d %d", i , j);
}


void swap_values (int *a, int *b)
{
	*a = *a+*b;  
	*b = *a-*b;
	*a = *a-*b;
}	

