
//This program is for keeping record of 10 employees by pointers
//record_struct_in_struct.c

#include<stdio.h>

struct emp 
{
	char name[10];
	int age;

	struct  
	{
		char add1[20];
		char add2[20];	
		char add3[20];	
	}address;

	int is_deleted;
};

int i = 1; // i is a global vairable here

int main()
{

	typedef struct emp user_t;

	user_t *z, e[5];

	int input;

	char s_srno[] = "SrNo";
	char s_name[] = "Name";
	char s_age[] = "Age";
	char s_address[] = "Address";
	int j = 1;
	char ch_input;
	char buff;
//	char line = '|';
	

	printf("Program for managing student record\n\n");

	while(1)
	{	
	printf("Press 1: Adding Record\nPress 2: Deleting Record\nPress 3: Viewing Record\nPress 4: Modifying record\nPress 5: Recovering Record\n\n");

	scanf("%d",&input);
	if (input < 1 || input > 6)
	{
	  printf("Please enter valid input\n\n");
          continue;
	}
	else if (input == 6)
	{
		printf("You are exited\n");
		break;
	}

	else if (input > 0 && input < 6)
	{
	       //Switch case
		printf("Please enter valid input\n\n");
		continue;
	}
	else
	{
		printf("Please enter valid input\n\n");
		continue;
	}

	switch(input)
	{
		case 1:	//Adding Record

			z = &e[i];
		
			printf("Adding a New Record\n");
			printf("Please enter your name, age & address\n");
			scanf("%s%i", &z->name[0], &z->age);
			scanf("%c", &buff);
			
			fgets (e[i].address.add1, sizeof (e[i].address.add1), stdin );	
			fgets (e[i].address.add2, sizeof (e[i].address.add2), stdin );
			fgets (e[i].address.add3, sizeof (e[i].address.add3), stdin );

			printf("Data recorded successfully as given below\n\n");

			z -> is_deleted = 0;
			
		/*	printf("\n%s%c\t%s%c\t\t\t%s%c\t\t\t%s\n", s_srno, line, s_name, line, s_age, line, s_address);

			printf("\n%d%c\t%s\t\t\t%c%i%c\t%s\n\t\t\t\t\t\t%c%s\n\t\t\t\t\t\t%c%s\n\n", i, line, e[i].name, line, e[i].age, line,
					e[i].address.add1, line, e[i].address.add2, line, e[i].address.add3); // showing recorded data here*/
			
			printf("\n%s\t\t%s\t\t\t%s\t\t%s\n", s_srno, s_name, s_age, s_address);

			printf("\n%d\t\t%s\t\t\t%i\t\t%s\n\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t%s\n\n", i, e[i].name, e[i].age,
					e[i].address.add1, e[i].address.add2, e[i].address.add3); // showing recorded data here
			i++;
			break;

		case 2: //Deleting record

			printf("\n%s\t\t%s\t\t\t%s\t\t%s\n", s_srno, s_name, s_age, s_address);
		
			int flag1 = 0;

			for(int x = 1; x < i; x++)
			{
				z = &e[x];
				if (z->is_deleted == 0) // 0 - not deleted
				{			
					flag1 = 1;  
			printf("\n%d\t\t%s\t\t\t%i\t\t%s\n\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t%s\n\n", x, z->name, z->age, z->address.add1,
					z->address.add2, z->address.add3);
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

			printf("\n%s\t\t%s\t\t\t%s\t\t%s\n", s_srno, s_name, s_age, s_address);

			int flag_v = 0;

			for(int h = 1; h < i; h++)
			{
				z = &e[h];
				flag_v = 1;
				if (z->is_deleted == 0) // 0 - not deleted			
					printf("\n%d\t\t%s\t\t\t%i\t\t%s\n\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t%s\n\n", h, z->name, z->age, z->address.add1,
						z->address.add2, z->address.add3);
			}

			if (flag_v != 1)
				printf("No record to view\n\n");
			break;


		case 4: //Modifying Record
			
			printf("\n%s\t\t%s\t\t\t%s\t\t%s\n", s_srno, s_name, s_age, s_address);

			int flag_m = 0;

			for(int a = 1; a < i; a++ )
			{ 
				z = &e[a];
				
				if (z->is_deleted == 0) // 0 - not deleted
					flag_m = 1;
					printf("\n%d\t\t%s\t\t\t%i\t\t%s\n\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t%s\n\n", a, z->name, z->age, z->address.add1,
						z->address.add2, z->address.add3);
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
				
						printf("1 name, 2 age, 3 address?\n");
				
						int r;
						scanf("%i", &r);

					//	z = &e[r];

						if ((r >= 1) && (r < 4)) // if r start
						{
							switch(r)
							{
			       	         			case 1: printf("New name added is: \n"); 
									scanf("%s", z->name);
				               				break;

			                 			case 2: printf("New age added is: \n");
						 			scanf("%d", &e[q].age);
				                			break;

			                 			case 3: printf("New address added is: \n");
									scanf("%c", &buff);
									fgets (e[q].address.add1, sizeof (e[q].address.add1), stdin );	
									fgets (e[q].address.add2, sizeof (e[q].address.add2), stdin );
									fgets (e[q].address.add3, sizeof (e[q].address.add3), stdin );
				                 			break;

							}  //switch r end

						printf("\nModification DONE successfully\n\n");

						} //if r end
						else if ((r > 3) || (r <= 0))
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
			
			printf("\n%s\t\t%s\t\t\t%s\t\t%s\n", s_srno, s_name, s_age, s_address);

			int flag_r = 0;

			for(int t = 1; t < i; t++)//Atleast one rec shd be present
			{
				z = &e[t];

				if (z->is_deleted == 1) //- 1 deleted
				{
					flag_r = 1;
					printf("\n%d\t\t%s\t\t\t%i\t\t%s\n\t\t\t\t\t\t\t%s\n\t\t\t\t\t\t\t%s\n\n", t, z->name, z->age, z->address.add1,
						z->address.add2, z->address.add3);
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
} // main end
