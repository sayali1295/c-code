
// This program is performing arithmetic calculations using arguments of main function
//(by including mycalc_arg.c file which contains logic to convert string to int value)
//new.c

#include<stdio.h>
#include<stdlib.h>
#include "mycalc_arg.c"

int main(int argc, char * argv[])
{
	int f = my_stoi(argv[1]) +  my_stoi(argv[3]);
	printf("%d", f);
}

/*int my_stoi (char  str1[])
{
	//logic
	int i = 0, num = 0, p =1;
	while(str1[i] != 0)
	{
		num = (str1[i] - '0')* p + num;

		i++;
		p= p *10;
	}

//	int num1 = ch - '0';


	int size_n1 = sizeof n1;
	int size_n2 = sizeof n2;

	if (size_n1 <= 5    )
	

	return num;
}*/
