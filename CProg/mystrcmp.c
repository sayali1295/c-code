#include <stdio.h>
/*int main()
{
	int str_compare(char str1[], char str2[]);
	char str1[]="abcdie";
	char str2[]="abcdie9";
	int i = str_compare(str1, str2);
	printf("%d", i);
	return 0;
}*/

int str_compare(char str1[], char str2[])
{
	     int i = 0;
             while ((str1[i] != 0) || (str2[i] != 0))
	     {
		     if (str1[i] != str2[i])
		     {
			      i = -1;
			      break;
			     
		     }
		     i++;
	     }  
	     return i;

}

