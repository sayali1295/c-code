#include<stdio.h>
int main()
{
	
	char a[] = "Pluto";

	printf("%c", *(a+1));
	printf("%c", *(1+a));
	printf("%c", a[1]);
	printf("%c", 1[a]);

}
