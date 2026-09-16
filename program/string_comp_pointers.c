
//This program is doing string comparison using pointers
// string_comp_pointer.c

#include <stdio.h>
#include<stdlib.h>
int main()
{

	int str_length(char *);

	int str_compare(char *, char []);

	char *arr_source = (char *) malloc(10);

	if (arr_source == NULL)
		printf("Requested size to array is not allocated\n");
	
	printf("\nProgram for string compare using pointers\n");

	printf("\nEnter first word of upto 10 alphabets\n");
	scanf("%s", &arr_source[0]);

	int size_arr_source = str_length(arr_source);

	char arr_dest[10];
	printf("\nEnter second word of upto 10 alphabets\n");

	int j = scanf("%s", &arr_dest[0]);
        printf("scanf returns = %d", j);		

	int size_arr_dest = str_length(arr_dest);
	
	if ((size_arr_source <= 10) && (size_arr_dest <= 10))
	{
		int i = str_compare(arr_source, arr_dest);
	
		if(i > 0)
			printf("\nBoth strings matched\n");
		else
			printf("\nStrings Mismatched\n");
	}
	else
	{
		printf("\nSorry, either 1 or both words having more than 10 alphabets is not allowed\n");
		return -1;
	}
	return 0;
	free(arr_source);
}

int str_compare(char *str1, char str2[])
{
	     int i = 0;
             while ((str1[i] != 0) || (str2[i] != 0))
	     {
		     if (str1[i] != str2[i])
		     {
			      i = -1;
			      break;
			     
		     }
		     i++;
	     }  
	     return i;
}

int str_length(char *str1)
{
	int j = 0;
	while (str1[j] != 0) j++;
	return j;
}

