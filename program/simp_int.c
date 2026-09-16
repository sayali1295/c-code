

#include<stdio.h>
int main ()
{
    printf("Program for finding simple interest\n");
    int p;
    float n, r; 

    printf("Please enter the value of loan amount: \n");
    scanf("%d", &p);

    printf("Now, enter for how many number of years you took an amount: \n");
    scanf("%f", &n);

    printf("Now, enter the rate of interest for your loan amount: \n");
    scanf("%f",&r);

    float simp_int = (p * n * r) / 100;

    printf("The simple interest calculated as: %f", simp_int);
}
