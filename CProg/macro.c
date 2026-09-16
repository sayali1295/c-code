#include <stdio.h>
int main()
{
	int  j=90;

#ifdef  Value

	j = 30;

#endif

#ifdef   logic
	j=100;
#endif

	printf("Value is %d", j); 
	return 0;
}

