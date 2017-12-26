#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int pid = fork();
	int i = 0;

	if(pid==0)
	{
		printf("hello\n");
	}
	else
	{	
		sleep(1);
		printf("goodbye\n");
	}
	return 0;
}
