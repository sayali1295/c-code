#include<stdio.h>
int main()
{
	char alpha1[100];
	char alpha2[20];
	char alpha3[20];
	char ch1;
	char ch2;

	fgets(&alpha1[0], sizeof(alpha1), stdin);
//	fgets(&alpha2[0], sizeof(alpha2), stdin);
//	fgets(&alpha3[0], sizeof(alpha3), stdin);

	
	printf("%s", alpha1);
	
/*	printf("%s", alpha1);
	scanf("%c", &ch1);

	printf("%s", alpha2);
	scanf("%c", &ch2);

	printf("%s", alpha3);*/

	return 0;
}
