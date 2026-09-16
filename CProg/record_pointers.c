
//This program is to keep record of students by pointers
//record_pointers.c

#include<stdio.h>
#include<string.h>

struct emp 
{
	char name[10];
	int age;
        int weight;
	float height;	
};

int main()
{

	typedef struct emp user_t;
	typedef int number;
	number t=89;
	printf("value \t%d\n",t);
		
     //   char str[10];
     
	user_t *z, e1[10];
        z = &e1;

	int i = 1;
	int input;

/*	char s = "SrNo";
	char t = "NAME";
	char u = "AGE";
	char v = "WEIGHT";
	char p = "HEIGHT";*/
	
	printf("Program for managing student record\n\n");

	printf("Press 1 : Adding Record\nPress 2: Deleting Record\nPress 3: Viewing Record\nPress 4: Modifying record\nPress 5: Recovering Record\n");
	scanf("%i", &input);

	switch(input)
	{
		case 1: printf("Adding a New Record\n");

			printf("Please enter your name, age, weight & height(in ft.)\n");
		//	scanf("%s", &str[0]);
		//	strcpy(z->name, str);
		//	scanf("%i%i%f", &z->age, &z->weight, &z->height);

			scanf("%s%i%i%f", &e1[i]->name, &e1[i]->age, &e1[i]->weight, &e1[i]->height);
		//	printf("%s\t%s\t%s\t%s\t%s\n", s, t, u, v, p);

			printf("Data recorded successfully\n");
		//	printf("Recorded data is: %s\t%i\t%i\t%.1f", z->name, z->age, z->weight, z->height);
			
			printf("Recorded data is: %s\t%i\t%i\t%.1f", &e1[i]->name, &e1[i]->age, &e1[i]->weight, &e1[i]->height);
			i++;
	}
}
