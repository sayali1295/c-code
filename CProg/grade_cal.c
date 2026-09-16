#include<stdio.h>
int main()
{
   int math,sci,eng,sst;
   float total;
   float percent;
   char grade;

   printf("Grades calculator\n");
   printf("Please enter the marks of 4 subjects: Maths, Sci, Eng & Sst out of 100 \n");

   scanf("%d", &math);
   printf("Marks of maths : %d", math);
   scanf("%d", &sci);
   printf("Marks of Science : %d", sci);
   scanf("%d", &eng);
   printf("Marks of english : %d", eng);
   scanf("%d", &sst);
   printf("Marks of sst : %d\n\n", sst);


   total = math + sci + eng + sst;
   percent = ((total / 400) * 100);

   printf("The total of all marks: %f\n", total);
   printf("The percentage of student is: %f\n", percent);

   if(percent >= 90)
   {
    grade = 'A';
    printf("Well done! you got grade : %c", grade);
   } 
   else if (percent >= 75)
   {
    grade = 'B';
    printf("Good! you got grade : %c", grade);
   }
   else if (percent >= 40)
   {
     grade = 'C';
     printf("You got grade : %c", grade);
   }
   else
   {
     grade = 'D';
     printf("Work hard!, you got grade : %c", grade);
   }
}
