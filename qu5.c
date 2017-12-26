#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pid = fork();
	int re = 0;
	if(pid==0)
	{
		printf("ch : %d\n", re);
		exit(1);
	}
	else
	{
		re = wait(1);
		printf("pe : %d\n",re);
	}

	return 0 ;
}
