
//This is a TESTING program which is performing string finding in a sentence using POINTERS
// find.c

#include<stdio.h>
#include<stdlib.h>

int find_str (char *, char *);


int main(int argc, char * argv[])
{

	char * arr1 = "place";
	char * arr2 = "gvbhhhhhhhhh";

        int res = find_str (&arr1[0], &arr2[0]);
	printf("%d", res);
}

int find_str (char * sub, char * str)
{
	int i = 0;
	int j = 0;

	while (str[j] != 0)
	{		
		i = 0;
		while (sub[i] != 0)
		{
			if (sub[i] != str[i+j])
			{
				break;
			}	
		i++;	
		}

		if (sub[i] == 0)
			return 0;

		j++;
		
	}

	return -1;
}


