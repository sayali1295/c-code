#include<stdio.h>

#ifdef int_array
int main()
{
	int array[]= {12, 45, 65, 35, 69, 23};
	int i = 0;

	while(i < 6)
	{
		printf("%i\t", array[i]);
		i++;
	}
}
#endif


#ifdef char_array1
int main()
{
	char array[]= {'V', 'E', 'N', 'U', 'S'};
	int i = 0;

	while(i < 5)
	{
		printf("%c\t", array[i]);
		i++;
	}
}
#endif


#ifdef char_array2
int main()
{
	char array[] = {'M', 'A', 'R', 'S', '\0'};
	int i = 0;

	while(array[i] != '\0')
	{
		printf("%c\t", array[i]);
		i++;
	}
}
#endif

#ifdef array_fun1
int main()
{	
	
	int find_strlength(char arr[]);

	char arr1[] = {'S', 'A', 'T', 'U', 'R', 'N', '\0'};
	char arr2[] = {"JUPITER"};
	
	int j = find_strlength (arr1);
	int k = find_strlength (arr2);

	printf("The length of array is: %i\n",j);
	
	printf("The length of string is: %i",k);

	return 0;
}
int find_strlength (char arr[])
{
		int i = 0;
		while(arr[i] != '\0')
		{
			i++;
		} 		
		return i;	
}
#endif



#ifdef array_fun2


int main()
{
        int  display_array (int arr[], int s);
	printf("Integer array by function\n");

	printf("Now, enter integer numbers to store in array:\n");
	int i;
	int array_int[5];

	int size = sizeof(array_int)/sizeof(int);;

	for(i = 0; i < size ; i++)
	{
		scanf("%d", &array_int[i]);
	}

	
	int j = display_array (array_int, size);

	return 0;
}

int display_array (int arr[], int s)
{
		int i = 0;

		printf("The entered elements in array is given below\n");
	
		while(i < s)
		{      
			printf("%d\t", arr[i]);
			i++;
		}
		return i;
}

#endif



#ifdef array_fun3


int main()
{
	char display_array (char arr[], int s);

	printf("Array by function\n");
	
	int size;
	printf("Please enter size of array:  ");
	scanf("%i", &size);

	printf("\nNow enter characters as per your given size:\n");

	char array_character[size];

	for(int i = 0; i < size; i++)
	{
		scanf(" %c", &array_character[i]);
	}
	
	char j = display_array (array_character, size);


	return 0;
}

char display_array (char arr[], int s)
{
	int i = 0;

	printf("The entered characters in array is given below\n");
	
	while(i < s)
	{      
		printf("%c\t", arr[i]);
		i++;
	}
	return i;
}

#endif

