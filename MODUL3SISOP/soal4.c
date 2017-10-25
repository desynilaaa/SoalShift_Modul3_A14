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

void *baca(void *ptr)
{
    while(status==0);
    for(i=0; i<3; i++)
    {
        for(j=0; j<nomor[i];j++)
        {
            hasil= hasil*(j+1);
        }
        stack[i]=hasil;
        hasil=1;
    }

    int flag, temp;
    for(i=0; i<3; i++)
    {
        flag = 1;
        for(j=3-1; j>i; j--)
        {
            if(stack[j] < stack[j-1])
            {
                temp =stack[j];
                stack[j]=stack[j-1];
                stack[j-1]=temp;
                flag = 0;
            }
        }
        if(flag==1) break;
    }

    for(i=0; i<3; i++)
    {
        printf("Hasil dari %d! = %d \n", nomor[i],stack[i]);
    }
}

int main()
{
    pthread_create(&t1, NULL, &tulis, NULL);
    pthread_create(&t2, NULL, &baca, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}