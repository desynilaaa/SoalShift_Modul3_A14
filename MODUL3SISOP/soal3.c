#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t thmenu, thtambah, thkurang1, thkurang2;
int stt_lohan=100,stt_kepiting=100,pilihan;

void *menu()
{
	printf ("1.Beri makan lohan =%d\n",stt_lohan);
	printf ("2.Beri makan kepiting =%d\n",stt_kepiting);
	printf ("Mau memberi makan siapa?  ");
	scanf("%d",&pilihan);
	printf("-------------\n");
	if (stt_lohan<=50)
	{
		printf("lohan sudah lapar\n");
	}
	else 
	{
		printf("lohan masih kenyang\n");
	}

	if (stt_kepiting<=50)
	{
		printf ("kepiting sudah lapar\n");
	}
	else 
	{
		printf("kepiting masih kanyang\n");
	}
}
void *kurang1()
{
	sleep(10);
	stt_lohan -=15;
}

void *kurang2()
{
	sleep(20);
	stt_kepiting -=20;
}

void *tambah()
{
	if (pilihan==1)
	{
 		stt_lohan +=10;
 	}
	else if (pilihan==2)
	{
 		stt_kepiting +=10;
 	}
}

int main()
{
	while(1)
	{
		pthread_create(&(thmenu),NULL,&menu,NULL);
		pthread_create(&(thkurang1),NULL,&kurang1,NULL);
		pthread_create(&(thkurang2),NULL,&kurang2,NULL);
		pthread_create(&(thtambah),NULL,&tambah,NULL);
		if((stt_lohan<=0||stt_lohan>100)||(stt_kepiting<=0||stt_kepiting>100))
		{
			printf("\n GAME OVER! \n"); 
			break;
		}
		pthread_join(thmenu,NULL);
	}
}