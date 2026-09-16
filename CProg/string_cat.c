#include<stdio.h>
#include<string.h>
int main()
{
	
	char str_concat (char[], char[]);

	char array1[20];
	char array2[10];

	printf("Program for String Concatenation\n");

	printf("Please insert a first string having less than 10 alphabets\n");
	scanf("%s", &array1[0]);


	printf("Please insert a second string having less than 10 alphabets\n");
	scanf("%s", &array2[0]);

	//strcat(array1, array2); normal way concatenation
	
	str_concat(array1, array2);

	printf("String after concatenation is: %s", array1);
}


char str_concat (char str1[], char str2[])
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
