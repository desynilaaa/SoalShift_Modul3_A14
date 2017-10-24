#include <stdio.h>
#include <pthread.h>

int i=1;
int nomor[4];
pthread_t t1;
pthread_t t2;
pthread_mutex_t lock;
int status=0;
int hasil=1;
int stack[4];
int j=1;

void *tulis(void *ptr)
{
	status = 0;
	printf("Masukkan angka ");
	for(i=0; i<3;i++)
	{
		scanf("%d", &nomor[i]);
	}

	int flag, temp;
	for(i=0; i<3; i++)
    {
        flag = 1;
        for(j=3-1; j>i; j--)
        {
            if(nomor[j] < nomor[j-1])
            {
                temp =nomor[j];
                nomor[j]=nomor[j-1];
                nomor[j-1]=temp;
                flag = 0;
            }
        }
        if(flag==1) break;
    }
	status =1;
	return NULL;
}