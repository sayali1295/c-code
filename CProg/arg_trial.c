//This is a TRIAL program to take arguments in main function
// arg_trial.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* env[])
{
	
	int i = 0;
	char *user_name;

/*	while(env[i] != 0)
	{
		printf("%s\n", env[i]);
		i++;
	}*/
	printf("number of argument is %d\n", argc);
	printf("command name is %s\n", argv[0]);
	printf("first argument name is %s\n", argv[1]);
	printf("second argument name is %s\n", argv[2]);
	printf("Third argument name is %s\n", argv[3]);

//	setenv("USER", "akash", 1);
	
/*	user_name = getenv("USER");

	while(env[i] != 0)
	{
	//	printf("%s\n", env[i]);
	

		if ((strcmp(env[i], "USER=sayali")) == 0)
		{
			printf("value of i at USER %d", i);
			printf("%s", env[i]);
		}

		i++;
       		else			
		{	
			printf("User mismatched, Access Denied");
			break;
		}
	}*/



	
/*	setenv("USER", "akash", 1);

	while(env[i] != 0)
	{
		printf("%s\n", env[i]);
		i++;
	}
	
	user_name = getenv("USER");
	printf("user name is : %s\n", user_name);
	
	if (user_name != "sayali")*/
		
	return 0;
}

