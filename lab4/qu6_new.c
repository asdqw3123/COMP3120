#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int p1[2], p2[2];
	int pid;
	char output[100] = "HELLO";
	char input[100] = {0,};

	pipe(p1);
	pipe(p2);

	close(p2[1]);
	dup2(p1[0],p2[0]);
	close(p1[0]);

	pid = fork();
	if(pid==0)
	{
		write(p1[1],output,100);
		printf("\nc : HELLO\n\n");
	}
	else
	{	wait();
		pid = fork();
		if(pid == 0)
		{
			read(p2[0],input,100);
			printf("\np : %s\n\n",input);
		}
		else {
		 wait();
		}
	}
	return 0;
}
