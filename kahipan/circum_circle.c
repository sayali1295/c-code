
#include<stdio.h>
int main()
{
    printf("Program for finding circumference of a circle\n");
    printf("Please enter a value of radius: ");

    float r;
    scanf("%f", &r);

    float pie = 3.14; //using pie as 3.14

    float circum = 2 * pie * r;

    printf("The circumference of a circle is: %f", circum);

}
