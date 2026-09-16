#include<stdio.h>

struct emp
{
   int i;
   int j;
   char h;
};

int main()
{
 typedef struct emp user;

  user e;
  e.i = 10;
  e.j = 20;
  e.h = 'A';
  
  printf("The value of h is : %c\n", e.h);
  printf("The value of i is: %d\n", e.i);
  
  printf("The value of j is: %d\n", e.j);

  sizeof (e.i);
  sizeof (e.j);

  printf("The size of i is: %d\n", e.i);

  printf("The size of j is: %d\n", e.j);

  printf("The size of 10 is: %ld\n", sizeof (10));

  printf("The size of 20 is: %ld\n", sizeof (20));

  printf("The size of A is: %ld\n", sizeof ('A'));

  printf("The size of h is: %ld\n", sizeof (e.h));

  printf("The size of user is: %ld\n", sizeof (user));




return 0;
}
