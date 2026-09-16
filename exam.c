#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main()
{
const char *s = "HOME";
char * env = getenv(s);
if (env != NULL)
{
	printf("%s", env);
}
else
{
	fprintf(stderr, "%s", strerror(errno));
}
return 0;
}
