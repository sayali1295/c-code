// This program is for different types of writing an array
//arr_print_types.c
#include<stdio.h>
int main()
{
	
	char a[] = "Pluto";

	printf("%c", *(a+1));   //types to write array
/*	printf("%c", *(1+a));
	printf("%c", a[1]);
	printf("%c", 1[a]); */

	printf("%s", (a+1));

/*	int size = sizeof (a);

	for (int i = 0; i < size; i++)
	{
	//	printf("%c", a[i]);

		printf("%c", i[a]);
	}*/


}
