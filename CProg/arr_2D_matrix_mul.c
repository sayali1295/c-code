//This program is to multiply two 2*2 matrix
//arr_2D_matrix_mul.c

#include<stdio.h>
#define SIZE 2
int main()
{
	int mat_a [SIZE][SIZE] = {
		{1, 2},
	    	{4, 3}
	};

	int mat_b [SIZE][SIZE] = {
		{3, 4},
		{2, 1}
	};

	int mat_c [SIZE][SIZE];
	int i, j, k;

	printf("2D 2*2 Matrix multiplication\n");

	//matrix multiplication

	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			for(k = 0; k < SIZE; k++)
			{
				mat_c[i][j] = mat_c[i][j] + (mat_a[i][k] * mat_b[k][j]);
			}
		}
	}

	//Resultant matrix is given below
	
	printf("\nNew matrix after multiplication is:\n");

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
