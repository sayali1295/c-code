#include<stdio.h>
int main()
{
	int sum (int a, int b);
    	int j = sum(10, 20);
    	printf("The sum is: %d", j);
   
} 
  
int sum (int a, int b)
{	
  int result = a + b;
  return result;
}
