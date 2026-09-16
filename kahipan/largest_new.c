#include<stdio.h>
int main()
{
    printf("Program for finding the largest number\n");
    printf("Please enter three numbers: \n");

    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);

    if (a>b)
    {
      if (a>c)
      {
         printf("The largest number is: %d", a);
      }
    }
    else if (b>c)
    {
         printf("The largest number is: %d", b);
    }
    else
    {
         printf("The largest number is: %d", c);
    }
}
