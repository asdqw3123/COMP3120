#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *pro(char *pid)
{
	int i=0, total=0;
	FILE *f1, *f2;
	char fname[50] = "/proc/", fname2[50] = {0,};
	char temp[50];

	strcat(fname, pid);
	strcat(fname, "/stat");
	strcat(fname2, fname);
	strcat(fname2, "us");

	while(1)
	{
		f1 = fopen(fname, "r+");
		f2 = fopen(fname2, "r+");
		total = 0;

		for(i=0; i<15; i++)
		{
			fscanf(f1, "%s", temp);
			if(i==13 || i==14) {
				total += atoi(temp);
			}
		}

		while(1)
		{
			fgets(temp, 50, f2);
			if( strstr(temp, "VmSize")) break;
		}

		printf("\nCPU : /proc/%s : %d\n", pid, total*100);
		printf("%s\n", temp);
	
		fclose(f1);
		fclose(f2);

		sleep(1);
	}
}

int main(int ac, char *av[])
{
	pthread_t *thread;

	if(ac < 2)
	{
		printf("usage : ./profile <pid>\n");
		exit(1);
	}


	pthread_create(&thread, NULL, pro, av[1]);
	pthread_join(thread, NULL);
	
	return 0;
}
