
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
     
	user_t *z, e[10];

	int i = 1;
        z = &e[i];

	int input;

	printf("Program for managing student record\n\n");

	printf("Press 1 : Adding Record\nPress 2: Deleting Record\nPress 3: Viewing Record\nPress 4: Modifying record\nPress 5: Recovering Record\n");
	scanf("%i", &input);

	switch(input)
	{
		case 1: printf("Adding a New Record\n");

			printf("Please enter your name, age, weight & height(in ft.)\n");

			scanf("%s%i%i%f", &z->name[0], &z->age, &e[i].weight, &e[i].height);

			printf("Data recorded successfully\n");
			
			printf("Recorded data is: %s\t%i\t%i\t%.1f", e[i].name, e[i].age, e[i].weight, z->height);
			i++;
	}
}
