#include<stdio.h>
int main()
{

	void mystr_copy (char[], char[]);

	char arr_source[7];
	char arr_dest[7];

	printf("Program for copying String\n");

	printf("Please enter a word having 6 alphabets\n");
	scanf("%s", &arr_source[0]);

//	int size = sizeof (arr_source) / sizeof (arr_source[0]);
//	printf("size = %d", size);

	mystr_copy(arr_source, arr_dest);

	printf("String copied is : %s", arr_dest);
}

void mystr_copy (char str1[], char str2[])
{
	int i = 0;
	while(str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i]= '\0';

}

