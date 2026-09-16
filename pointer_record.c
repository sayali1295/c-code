
//This program is for keeping record of 10 students by pointers
//pointer_record.c

#include<stdio.h>

struct emp 
{
	char name[10];
	int age;
        int weight;
	float height;	
	int is_deleted;
};
int i=1;
int main()
{

	typedef struct emp user_t;
     
	user_t *z, e[5];

//	int i = 1;

	int input;

	char s_srno[] = "SrNo";
	char s_name[] = "Name";
	char s_age[] = "Age";
	char s_weight[] = "Weight";
	char s_height[] = "Height";
	int j = 1;
	char ch_input;
	

	printf("Program for managing student record\n\n");

	while(1)
	{	
	printf("Press 1: Adding Record\nPress 2: Deleting Record\nPress 3: Viewing Record\nPress 4: Modifying record\nPress 5: Recovering Record\n\n");
	scanf("%i", &input);

	if (!((input <= 6) && (input >= 1)))
	{
        	printf("please enter valid data\n");
       		scanf(" %c", &ch_input);
        	continue;
	}

	switch(input)
	{
		case 1:	//Adding Record
			z = &e[i];
		

			printf("Adding a New Record\n");
			printf("Please enter your name, age, weight & height(in ft.)\n");
			scanf("%s%i%i%f", &z->name[0], &z->age, &e[i].weight, &e[i].height);
			printf("Data recorded successfully\n\n");

			z -> is_deleted = 0;

			printf("\nRecorded data is: %d\t%s\t%i\t%i\t%.1f\n\n", i, e[i].name, e[i].age, e[i].weight, z->height);
			i++;
			

			break;

		case 2: //Deleting record

			printf("\n%s\t%s\t%s\t%s\t%s\n", s_srno, s_name, s_age, s_weight, s_height);
		
			int flag1 = 0;

			for(int x = 1; x < i; x++)
			{
				z = &e[x];
				if (z->is_deleted == 0) // 0 - not deleted
				{			
					flag1 = 1;  
					printf("%d\t%s\t%d\t%d\t%.1f\n\n", x, z->name, z->age, z->weight, z->height);
				}
			} 
			if (flag1 == 1)
			{		    
				printf("Please tell me, which record to delete among above\n");

				int k;
				scanf("%d", &k);
			
				z = &e[k];

                           	z -> is_deleted = 1;//1 deleted
						    
				printf("\nYour record deleted successfully\n\n");
			}
			else
				printf("\nNo Record to delete\n\n");
				break;


		case 3: //Viewing Record

			printf("Viewing Records\n");

			printf("\n%s\t%s\t%s\t%s\t%s\n", s_srno, s_name, s_age, s_weight, s_height);

			int flag_v = 0;

			for(int h = 1; h < i; h++)
			{
				z = &e[h];
				flag_v = 1;
				if (z->is_deleted == 0) // 0 - not deleted			
					printf("%d\t%s\t%d\t%d\t%.1f\n\n", h, e[h].name, e[h].age, e[h].weight, e[h].height);
			}

			if (flag_v != 1)
				printf("No record to view\n\n");
			break;


		case 4: //Modifying Record
			
			printf("\n%s\t%s\t%s\t%s\t%s\n", s_srno, s_name, s_age, s_weight, s_height);

			int flag_m = 0;

			for(int a = 1; a < i; a++ )
			{ 
				z = &e[a];
				
				if (z->is_deleted == 0) // 0 - not deleted
					flag_m = 1;
					printf("%d\t%s\t%d\t%d\t%.1f\n", a, z->name, z->age, z->weight, e[a].height);
			}
			
			if(flag_m != 1)
			{	
				printf("Sorry, I have no record to modify\n\n");
				break;
			}
			else
			{
			//	while(1)
			//	{
				printf("Please tell me, which record to modify among above\n");
				int q;
				
				if (scanf("%d", &q) == 1) //if q start
				{
					if ((q < i) && (!(q <= 0)))
					{
						z = &e[q];
						printf("Tell me which field from record to be modified\n");
				
						printf("1 name, 2 age, 3 weight, 4 height?\n");
				
						int r;
						scanf("%i", &r);

					//	z = &e[r];

						if ((r >= 1) && (r < 5)) // if r start
						{
							switch(r)
							{
			       	         			case 1: printf("New name added is: \n"); 
									scanf("%s", z->name);
				               				break;

			                 			case 2: printf("New age added is: \n");
						 			scanf("%d", &e[q].age);
				                			break;

			                 			case 3: printf("New weight added is: \n");
						 			scanf("%d", &e[q].weight);
				                 			break;

								case 4: printf("New height added is: \n");
									scanf("%f", &e[q].height);
									break;
							}  //switch r end

						printf("\nModification DONE successfully\n\n");

						} //if r end
						else if ((r > 4) || (r <= 0))
						{
							printf("Wrong Input, Try again with correct input\n\n");
							break;
						}
						else
						{
							char ch_r;
							scanf(" %c", &ch_r);
							printf("Please enter mentioned field Sr.No. only\n\n");
							break;
						}
					}
					else // else q end
						printf("Please enter mentioned Sr.No. only\n\n");

				}  // if q end	
				else
				{
					char ch_m;
					scanf(" %c", &ch_m);
					printf("Invalid input, please enter record Sr.No. correctly\n\n");
					break;	
				}
		
			} // else flag end

			break;
			//	} // while modify end

		case 5:	//Recovering record

			printf("Showing deleted records if present\n");
			
			printf("\n%s\t%s\t%s\t%s\t%s\n", s_srno, s_name, s_age, s_weight, s_height);

			int flag_r = 0;

			for(int t = 1; t < i; t++)//Atleast one rec shd be present
			{
				z = &e[t];

				if (z->is_deleted == 1) //- 1 deleted
				{
					flag_r = 1;
					printf("%d\t%s\t%d\t%d\t%.1f\n\n", t, z->name, z->age, z->weight, e[t].height);
					break;
				}
			}

			if(flag_r == 1)
			{
			
				printf("Select which record to recover among above?\n");

				int v;

				if ((scanf("%d", &v)) == 1)
				{
					z = &e[v];

					if (z->is_deleted == 1)
                        		{
						e[v].is_deleted = 0;
						printf("Record recovered successfully\n\n");
						break;
					}
					else  
					{
						printf("Please enter record Sr.No. correctly\n\n");
						break;
					}
				}
				else
				{	
					char ch;
					scanf(" %c", &ch);
					printf("Invalid input, Enter an integer\n\n");
					break;
				}
			}
			else
			{
				printf("\nSorry, I have no record to recover\n\n");
				break;
			}
			break;

		case 6: //exit

			printf("You are exited from menu\n\n");
			break;


	}//switch end
}//while end

} //main end
