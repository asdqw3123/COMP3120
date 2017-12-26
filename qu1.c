#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x=100;
	int pid = fork();
	
	if(pid==0)
	{
		x = pid;
		printf("I'm child : x = %d\n",x);
	}
	else
	{	
		wait();
		x = pid;
		printf("I'm parent : x = %d\n",x);
	}
	return 0;
}
