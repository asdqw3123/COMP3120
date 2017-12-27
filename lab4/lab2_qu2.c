#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

int cnt = 0;
int p_cnt=0;

void *count_h();

pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;

int main()
{
	int max = 0, i = 0;
	struct timeval startt, endt;
	pthread_t *thread;

	srand(time(NULL));
	
	max = rand()%100+1;
	thread = (pthread_t*)malloc(sizeof(pthread_t)*max);
	
	gettimeofday(&startt,NULL);
	for(i=0;i<max;i++)
	{
		pthread_create(&thread[i],NULL,count_h,NULL);
		pthread_join(thread[i],NULL);
	}
	gettimeofday(&endt,NULL);
	printf("thread : %d , time : %lf , cnt : %d\n",max,endt.tv_sec+endt.tv_usec*0.000001 - startt.tv_sec-startt.tv_usec*0.000001, cnt);
}

void *count_h()
{
	for(;cnt<912783672;)
	{
	pthread_mutex_lock(&counter_lock);
	//for(;cnt<912783672;cnt++);
	cnt++;
	pthread_mutex_unlock(&counter_lock);
	}
}
