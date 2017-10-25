#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t trd_lohan;
pthread_t trd_kepiting;
pthread_t trd_input;

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
	while(1)
	{
		sleep(20);
		stt_kepiting-=10;
		if(stt_kepiting > 100 || stt_lohan <=0)
		{
			status=1;
			break;

		}
	}
}

void* masuk()
{
	int pilihan;
	while(1)
	{
		printf("1. Beri makan lohan.\n");
		printf("2. Beri makan kepiting\n");
		printf("Masukan pilihan Anda ");

		system(clear);
		if(pilihan==1)
		{
			stt_lohan +=10;
			if(stt_lohan > 100 || stt_lohan <=0)
			{
				status=1;
				break;
			}
		}
		if(pilihan==2)
		{
			stt_kepiting += 10;
			if(stt_kepiting > 100 || stt_kepiting <= 0)
			{
				status=1;
				break;
			}

		}
	}
}

int main()
{
	system("clear");
	pthread_create(&(trd_lohan), NULL, &lohan, NULL);
	pthread_create(&(trd_kepiting), NULL, &kepiting, NULL);
	pthread_create(&(trd_input), NULL, &masuk, NULL);

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
