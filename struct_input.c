#include<stdio.h>

//Program of struture by taking i/p from user

struct emp
{
   char name;
   int age, weight;
};

int main()
{
   typedef struct emp user;
   user a;
	   
      printf("Please enter your name, age and weight\n");
      scanf("%c%d%d", &a.name, &a.age, &a.weight);
      
      printf("Hello User, Your name I stored is: %c", a.name);

      printf(", age is: %d", a.age);

      printf(" & weight is: %d\n", a.weight);

      return 0;

}

