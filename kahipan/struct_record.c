#include<stdio.h>

struct emp
{
   char name;
   int age;
   int weight;
   float height;
   int is_deleted;
};


int main()
{
   typedef struct emp user;
   user z[5];
  
   printf("Program to keep record of a student\n");
   
   int i = 1;
   int j;
   char count = 'C';
   char name = 'N';
   char age = 'A';
   char weight = 'W';
   char height = 'H';
   char ch;

   while(1)
   {
      printf("\nPlease enter 1 to Add a record, 2 to Delete, 3 to View, 4 to Modify, 5 to Recover & 6 to exit\n\n");
      scanf(" %d", &j);

      if (!((j <= 6) && (j >= 1)))
      {
	printf("please enter valid data\n");
	scanf(" %c", &ch);
      	continue;
      }

          switch(j)
           {
              case 1:    //adding record
		          printf("Adding a new Record\n\n");
		          printf("Hello user, please enter your name, age, weight & height in foot\n");
                          scanf(" %c%d%d%f", &z[i].name, &z[i].age, &z[i].weight, &z[i].height);  
		          printf("Data recorded successfully\n");
			  z[i].is_deleted = 0;
			  i++;
			  break;

	      case 2:    //deleting record
			  printf("\n%c\t%c\t%c\t%c\t%c\n", count, name, age, weight, height);
			  int flag1 = 0;

			  for(int x = 1; x < i; x++)
			    {
				if (z[x].is_deleted == 0) // 0 - not deleted
				  {			
			            flag1 = 1;  
			            printf("%d\t%c\t%d\t%d\t%.1f\n", x, z[x].name, z[x].age, z[x].weight, z[x].height);
				  }
			    } 
			    if (flag1 == 1)
			    {		    
	                      printf("Please tell me, which record to delete among above\n");
                              int k;
	                      scanf("%d", &k);
                               
			        if((k <= 5) && (k >= 1))
				{
			          z[k].is_deleted = 1;//1 deleted
			          printf("Your record deleted successfully\n");
				}
                                else 
			        { 
			          char ch;
				  scanf("%c", &ch); 
			          printf("Wrong input, try again with correct input\n");
				  continue;
			        }
			     }
			    else
			    	printf("\nNo Record to delete\n");
			        break;
			 

	      case 3:     //Viewing record
			   printf("Viewing records\n\n");

			   printf("%c\t%c\t%c\t%c\t%c\n", count, name, age, weight, height);
   

                            for (int p = 1; p < i; p++)
			    {
		             if (z[p].is_deleted == 0)  //  0 - not deleted
			     	printf("%d\t%c\t%d\t%d\t%.1f\n", p, z[p].name, z[p].age, z[p].weight, z[p].height);
			    }
			   
		           break;

	      case 4:     //Modifying record 
                           
			   printf("%c\t%c\t%c\t%c\t%c\n", count, name, age, weight, height);

			   for(int a = 1; a < i; a++)
			    { 
			       if (z[a].is_deleted == 0) // 0 - not deleted
			       printf("%d\t%c\t%d\t%d\t%.1f\n", a, z[a].name, z[a].age, z[a].weight, z[a].height);
			    }
			    while(1)
			    {
	                    printf("Please tell me, which record to modify among above\n");
                            int q;
	                    scanf("%d", &q);
                              
			    if ((q <= 5) && (q >= 1))   //if1 start
			    {

			      printf("Now, tell me which field from record to be modified\n");

			      printf("1 name, 2 age, 3 weight, 4 height?\n");

                              int r;
			      scanf("%d", &r);

				if ((r <= 4) && (r >= 1))   // if2 start
				{
                                   		switch(r)
			            		 {
			                 		case 1: printf("New name added is: \n"); 
						 	scanf(" %c", &z[q].name);
				                 	break;

			                 		case 2: printf("New age added is: \n");
						 	scanf("%d", &z[q].age);
				                 	break;

			                 		case 3: printf("New weight added is: \n");
						 	scanf("%d", &z[q].weight);
				                 	break;

			                 		case 4: printf("New height added is: \n");
						 	scanf("%f", &z[q].height);
			 	                 	break;
			       	     		}//switch end

				 }    //if2end
				 else
				 {
				    char if2;
				    scanf("%c", &if2);  
			            printf("Wrong input, Try again with correct input\n");
				    continue;
			
				 } //else2 end
				   

			   

                                  printf("Modification DONE successfully\n\n");
		                  printf("The record after modification is given below\n");
                                  
			          printf("%c\t%c\t%c\t%c\t%c\n", count, name, age, weight, height);
                                  
				  for(int b = 1; b < i; b++)
				  {
			             if (z[b].is_deleted == 0) // 0 - not deleted
					  printf("%d\t%c\t%d\t%d\t%.1f\n", b, z[b].name, z[b].age, z[b].weight, z[b].height);
				  }
		                  
                              
			      break;

			    }
			else
			 {
		           char if1;
			   scanf("%c", &if1);
			   printf("Pressed wrong key, please give me correct input\n");
			 }  //else1 end
	     }// while end
    
              case 5:     //Recovering record
		           printf("Showing deleted records\n");

			   printf("%c\t%c\t%c\t%c\t%c\n", count, name, age, weight, height);
                            
			   for(int t = 1; t < i; t++)
			   {
			     if (z[t].is_deleted == 1) //- 1 deleted
			     printf("%d\t%c\t%d\t%d\t%.1f\n", t, z[t].name, z[t].age, z[t].weight, z[t].height);
			   }

                           printf("Now, select which record to recover?\n");
			   int v;
			   scanf("%d", &v);
                              
                           if (z[v].is_deleted == 1)
                           {

			     	switch(v)
			     	{
				 	case 1: z[v].is_deleted = 0; 
                                         printf("Your record recovered successfully\n");
					 break;

			         	case 2: z[v].is_deleted = 0;
                                         printf("Your record recovered successfully\n");
					 break;

				 	case 3: z[v].is_deleted = 0;
                                         printf("Your record recovered successfully\n");
					 break;

				 	case 4: z[v].is_deleted = 0;
                                         printf("Your record recovered successfully\n");
					 break;

				 	case 5: z[v].is_deleted = 0;
                                         printf("Your record recovered successfully\n");
					 break;
			     	}//switch close
                               //break;

                          }

                          else  
		  	  {	
			             printf("Sorry You have entered wrong input\n");
				     break;
			  }

	      case 6:     //exit
		          printf("You are exited.\n");
			  break;
    

             }//switch1
	  

   }//while1


}//main




