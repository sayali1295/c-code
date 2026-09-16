#include<stdio.h>
int main()
{
	printf("2D Array printing\n");
	char array[3][3];
	int r, c;

//Entering elements in array
	printf("Entering Elements\n\n");
	
	for(r = 0; r < 3; r++)
	{
		for(c = 0; c < 3; c++)
		{
			printf("Element at r%dc%d is: ", r, c);
			scanf(" %c", &array[r][c]);
		}
	}
//Displaying elements in array
	
	printf("Displaying Elements\n\n");

	for(r = 0; r < 3; r++)
	{
		for(c = 0; c < 3; c++)
		{
			printf("%c\t", array[r][c]);	
		}
		printf("\n");
	}

				
	return 0;

}
