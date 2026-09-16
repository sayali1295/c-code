//This program is doing string copy using pointers
// str_cal_realoc.c


#include<stdio.h>
#include<stdlib.h>

int main()
{

	int mystr_length (char *);					//STRING LENGTH function prototype
	void mystr_copy (char *, char *);				//COPY function prototype

	char *arr_source = (char *) calloc(20, 20);

	if(arr_source == NULL) 
		printf("Requested size is not allocated\n");

	char *arr_dest = (char *) calloc(20, 20);

	if(arr_dest == NULL) 
		printf("Requested size is not allocated\n");
	
	printf("Program for copying String\n");

	printf("Please enter a word upto 30 alphabets\n");
	scanf("%s", &arr_source[0]);

	
	char *arr_dest_re = (char *) realloc(arr_dest, 10);
	
	char *arr_source_re = (char *) realloc(arr_source, 10);

	int size_arr_source = mystr_length (arr_source_re);
	
	if (size_arr_source <= 20)
	{
		mystr_copy(arr_source_re, arr_dest_re);
		printf("\nString copied in destination is : %s", arr_dest_re);
	}
	else									//COPY function call
		printf("\nSorry, entered word has more than 30 alphabets\n");
		return -1;

	free(arr_source);
	free(arr_dest);

	return 0;
}

void mystr_copy (char *str1, char *str2)				//COPY function defination
{
	int i = 0;
	while(str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i]= '\0';

}

int mystr_length (char *str1)						
{	
	int j = 0;

	while (str1[j] != 0) j++;
	return j;
}


