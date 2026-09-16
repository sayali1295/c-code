#include<stdio.h>
#define PI 3.14

float circum (float r)
{
    float result = 2 * PI * r;
    return result;
}

int main()
{
  float c = circum(2.5);
  printf("The circumfere
		  nce of a circle is: %.2f", c);
}
