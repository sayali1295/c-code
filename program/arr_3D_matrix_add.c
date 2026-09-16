//This program is to add two 3 * 3 matrix
//arr_3D_matrix_add.c

#include<stdio.h>
#define SIZE 3
int main()
{

	int r, c;
	int mat_a [SIZE][SIZE] = {
		{1, 2, 5},
	    	{4, 3, 6},
		{6, 2, 7}	
	};

	int mat_b [SIZE][SIZE] = {
		{3, 4, 6},
		{2, 1, 8},
		{1, 4, 3}
	};

	int mat_c [SIZE][SIZE];
	int i, j, k;

	printf("3D 3*3 Matrix addition\n");

	//matrix addition

	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			mat_c[i][j] = mat_c[i][j] + (mat_a[i][j] + mat_b[i][j]);
		}
	}

	//Resultant matrix is given below
	
	printf("\nNew matrix after addition is:\n");

	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			printf("%d\t", mat_c[i][j]);
		}
		printf("\n");
	}
return 0;
}
