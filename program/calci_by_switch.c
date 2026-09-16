#include<stdio.h>
int main()
{

   int num1, num2, var, flag;
   char input;
   
   printf("Welcome to Mini Calculator\n");

   while(1)
   {//start
        flag = 0;
   	printf("Enter two numbers\n");
   	scanf("%d%d", &num1, &num2);

   	printf("\nPlease enter A for Addition, S for Subtraction, M for Multiplication & D for Division\n");
   	scanf(" %c", &input);
	
   	switch(input)
   	{
	   
       		case 'A':
       		case 'a':
	     		var = num1 + num2;
			break;

       		case 'S':
       		case 's': 
	        	var  = num1 - num2;
			break;

       		case 'M':
       		case 'm':	
	       		var = num1 * num2;
			break;

       		case 'D':
       		case 'd':	
			var = num1 / num2;
			break;

       		default:
			printf("\nWrong input\n");
			flag = 2;
			break;
   	}
	if ( flag != 2)
                printf("Result is %d\n", var);
   }//end
    
   



/*printf("Please enter on how many numbers operation is to be performed");
scanf("%d", &n);

for(int i = 0; i <= n-1; i++)
{
  scanf("%d", &)
}*/

return 0;



}
