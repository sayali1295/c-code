
//This program is performing sub string finding in a long string using POINTERS
// my_strstr.c

#include<stdio.h>
#include<stdlib.h>

char * find_str (char *, char *);				// function prototype

int main(int argc, char * argv[])
{

        char * res = NULL;
	
	if (argc == 3)
	{
		res = find_str (argv[2], argv[1]);   
		printf("%s", res);
	}
	else
		printf("Wrong syntax\n");
		printf("Correct syntax : tool_name <long string (string to be searched here)> <substring (string to search)>");

/*	if (*res == null)					//here we are printing string found or not
		printf("(null)\n");
	else
	{
		printf("%s", argv[1]);

		while (argv[2][res] != 0)
		{
			printf("%s", argv[2]);
			res++;
		}
	}*/
}

char * find_str (char * str, char * sub)			//function defination
								
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
			return &str[j];

		j++;
	}
	return (void *)0;

}


