
//This program is performing sub string finding in a long string using POINTERS
// find_str_arg.c

#include<stdio.h>
#include<stdlib.h>

int find_str (char [], char []);				// function prototype

int main(int argc, char * argv[])
{

        int res = find_str (argv[1], argv[2]);

	if (res < 0)						//here we are printing string found or not
		printf("String does not found\n");
	else
		printf("String %s located at position %d\n", argv[1], res);
}

int find_str (char sub[], char str[])				//function defination
{
	int i = 0;
	int j = 0;

	while (str[j] != 0)					//outer loop for long string
	{		
		i = 0;
		while (sub[i] != 0)				//inner loop for sub string
		{
			if (sub[i] != str[i+j])			//login for finding sub string inside long string
			{
				break;
			}	
		i++;	
		}

		if (sub[i] == 0)
			return j;

		j++;
	}

	return -1;
}


