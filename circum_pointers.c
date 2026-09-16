#include<stdio.h>
#define PI 3.14
int main()
{
	float circum_circle(float *);

	float radius = 2.5;

	float circum = circum_circle(&radius);

	printf("The circumference of circle is: %.2f", circum);
}


float circum_circle(float *r)
{
	float c = 2 * PI * (*r);

	return c;

}
