//This program is doing string concatenation using pointers
// string_cat_pointers.c

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	
	char str_concat (char *, char *);              // function prototype

	char *array1 = (char *) malloc (20);
	char *array2 = (char *) malloc (20);

	printf("Program for String Concatenation using Pointers\n");

	printf("Please insert a first string having less than 20 alphabets\n");
	scanf("%s", &array1[0]);


	printf("Please insert a second string having less than 20 alphabets\n");
	scanf("%s", &array2[0]);

	//strcat(array1, array2); normal way concatenation
	
	str_concat(array1, array2);                    // function call

	printf("String after concatenation is: %s", array1);
	
	free(array1);
	free(array2);
}


char str_concat (char *str1, char *str2)               //function defination
{	
	int i = 0;

	while (str1[i] != '\0') i++;
	
	int j = 0;

	while(str2[j] != '\0')
	{
		str1[i] = str2[j];
		j++;
		i++;	
	}

	str1[i] = '\0';
} 
