#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
	int i;
	struct timeval startt, endt;

	gettimeofday(&startt,NULL);
	for(i=0;i<978986797;i++);

	gettimeofday(&endt,NULL);

	printf("start time : %lf\n", startt.tv_sec + startt.tv_usec*0.000001);
	printf("  end time : %lf\n", endt.tv_sec + endt.tv_usec*0.000001);
	printf(" ---   %lf   ---\n", (endt.tv_sec + endt.tv_usec*0.000001)-(startt.tv_sec + startt.tv_usec*0.000001));
	
	return 0;
}
