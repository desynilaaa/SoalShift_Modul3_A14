#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t trd_lohan;
pthread_t trd_kepiting;
pthread_t input;

int stt_kepiting=100;
int stt_lohan=100;
int status;

void* lohan()
{
	while(1)
	{
		sleep(10);
		stt_lohan-=15;
		if(stt_lohan > 100 || stt_lohan <=0)
			{
				status=1;
				break;
			}
	}
}

void* kepiting()
{
	
}

int main()
{
	system("clear");
	pthread_create(&(trd_lohan), NULL, &lohan, NULL);
	pthread_create(&(trd_kepiting), NULL, &kepiting, NULL);

	while(1)
	{
		if(status==1)
		{
			system("clear");
			printf("GAME OVER\n");
			return 0;
		}
	
	}
}
