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
		i=1;
	}
	else
	{	
		while(1)
		{
			if(i == 1) {
				pritnf("goodbye\n");
				break;
			}
		}
	}
	return 0;
}
