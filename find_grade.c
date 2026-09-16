#include<stdio.h>
int main()
{
   printf("Maths Grade Calculator\n");
   printf("Please enter the marks of 4 students \n");

   int m1;
   scanf("%d", &m1);
   printf("Student 1 mark collected as: %d", m1);

   int m2;
   scanf("%d", &m2);
   printf("Student 2 mark collected as: %d", m2);

   int m3;
   scanf("%d", &m3);
   printf("Student 3 mark collected as: %d", m3);

   int m4;
   scanf("%d", &m4);
   printf("Student 4 mark collected as: %d\n", m4);

   char grade1, grade2, grade3, grade4;
   
   if(m1>=90)
   {
      grade1 = 'A';
   } 
   else if(m1>=75)
      {
        grade1 = 'B';
      }
   else if (m1>=50)
      {
        grade1 = 'C';
      } 
   else
   {
       grade1 = 'D';
   }

   if (m2>=90)
   {
      grade2 = 'A';
   }
   else if(m2>=75)
   {
       grade2 = 'B';
   }
   else if(m2>=50)
   {
       grade2 = 'C';
   }
   else
   {
       grade2 = 'D';
   }

  if (m3>=90)
  {
      grade3 = 'A';
  }
  else if(m3>=75)
  {
     grade3 ='B';
  }
  else if (m3>=50)
  {
    grade3 = 'C';
  }
  else
  {
     grade3 = 'D';
  }

  if (m4>=90)
  {
    grade4 = 'A';
  }
  else if (m4>=75)
  {
    grade4 ='B';
  }
  else if (m4>=50)
  {
     grade4 = 'C';
  }
  else
  {
    grade4 = 'D';
  }
 
    printf("The grade of student 1 is: %c\n", grade1);
    printf("The grade of student 2 is: %c\n", grade2);
    printf("The grade of student 3 is: %c\n", grade3);
    printf("The grade of student 4 is: %c\n", grade4);
  }
