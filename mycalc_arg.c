
//This program is performing aritmetic operations using arguments in main function
// my_calc_arg.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int my_stoi (char []);					//function prototype

int main(int argc, char * argv[])
{

	printf("%s", argv[1]);				// Taking arguments from user
	printf("%s", argv[2]);
	printf("%s\n", argv[3]);

	int res;
	char op = argv[2][0];

	switch(op)
	{
		case '+':res = my_stoi(argv[1]) + my_stoi(argv[3]);	// performing different arithmetic operations
			 break;
	
	
		case '-':res = my_stoi(argv[1]) - my_stoi(argv[3]);	
			 break;
	
	
		case '*':res = my_stoi(argv[1]) * my_stoi(argv[3]);	
			 break;
	
	
		case '/':res = my_stoi(argv[1]) / my_stoi(argv[3]);	
			 break;


		case '%':res = my_stoi(argv[1]) % my_stoi(argv[3]);	
			 break;
	}

	printf("\nResult is %d\n", res);
}

int my_stoi (char  str1[])						// logic for converting string to integer value
{
//	int u = strlen (str1);

	int d = 0;
	while (str1[d] != 0) // loop for finging length of a string
	{
		d++;
	}
	int u = d;

	int i = u-1, num = 0, p = 1;

	while(i >= 0)
	{
		num = (str1[i] - '0') * p + num;

		i--;
		p = p * 10;
	}
	return num;
}
