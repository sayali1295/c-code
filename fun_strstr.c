
//This program is using (strstr) function to fing substring in long string
//fun_strstr.c


#include<stdio.h>
#include<string.h>

int main()
{
	char arr1[] = "place";
	char arr2[] = "sjdbspshbjbmsssplhsbsjn pabhjb plabnhbfbwbfcwbbfjs";

	char *s = strstr (&arr2[0], &arr1[0]);

	printf("%s", s);



return 0;

}
