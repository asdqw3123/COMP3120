#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int f = open("qu2_text.txt",O_RDWR | O_CREAT,00777);
	int pid = fork();

	if(pid==0)
	{
		write(f,"\nI'm child hahaha\n",18);
	}
	else
	{
		write(f,"\nI'm parent hahaha\n",19);
	}

	close(f);
	return 0;
}
