#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *args[] = {"ls",NULL};
	int pid = fork();

	if(pid==0)
	{
		execvp("ls",args);
	}
	else
	{
		wait();
	}
	return 0;
}
