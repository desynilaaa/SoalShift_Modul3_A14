include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t p1, p2;
int status=0, giliran=1, ranjau1[16], ranjau2[16], nilai1=0, nilai2=0;
char nama_p_1[50], nama_p_2[50];

void* pemainpertama()
{
	int a, b=0, c, d[4], e[4], f;
	for(a=0;a<16;a++){
	ranjau1[a] = 0;
}
while(1)
{
	while(giliran!=1){}
	system("clear");
	if(b==0){
	printf("Nama pemain pertama:\n");
	scanf("%s", nama_p_1);
	b=1;
	giliran = 2;
	continue;
}
else if(b==1)
{
	printf("Hai %s, Silahkan pasang ranjau anda\n", nama_p_1);
	printf("Mau pasang ranjau berapa (maksimal 4 ranjau)? \n");
	scanf("%d", &c);
	if(c>4 || c<=0){
	printf("Ranjau yang dipasang terlalu banyak, maksimal 4 ranjau\n");
	getchar();
	getchar();
	continue;
}
psg_ranjau_1:
	system("clear");
	printf("Lubang yang sudah ada ranjaunya : ");
	for(a=0;a<16;a++)
	{
		if(ranjau1[a] == 1)
		{
			printf("%d ", a+1);
		}
	}
	printf("\nMau pasang ranjau di lubang ke berapa? (1-16)\n");
	for(a=0;a<c;a++)
	{
		scanf("%d", &d[a]);
		d[a] = d[a] - 1;
		if(d[a]>=16 || d[a]<0)
		{
			printf("Lubang yang akan dimasukkan tidak tersedia, silahkan coba lagi\n");
			getchar();
			getchar();
			goto psg_ranjau_1;
		}
	}
	for(a=0;a<c;a++)
	{
		for(f=0;f<c;f++)
		{	
			if(a==f)
			{
				continue;
			}
			if(d[a] == d[f])
				{
				printf("Ranjau tidak bisa dipasang ke tempat yang sama, coba lagi\n");
				getchar();
				getchar();
				goto psg_ranjau_1;
			}
		}
	}
else if(b==2)
{
	tebak_ranjau_1:
	printf("Hai %s, Silahkan tebak ranjau yang disimpan di 4 lubang (1-16)\n", nama_p_1);
	for(a=0;a<4;a++)
	{
		scanf("%d", &e[a]);
		e[a] = e[a] - 1;
		if(e[a] >= 16 || e[a] < 0)
		{
			printf("Lubang tidak tersedia, coba lagi\n");
			getchar();
			getchar();
			system("clear");
			goto tebak_ranjau_1;
		}
	}
	for(a=0;a<4;a++)
	{
		for(c=0;c<4;c++)
		{
			if(a == c)
			{
				continue;
			}
			if(e[a] == e[c])
			{
				printf("Silahkan cari lubang lain, jangan lubang yang sama!");
				getchar();
				getchar();
				system("clear");
				goto tebak_ranjau_1;
			}
		}
	}
	for(a=0;a<4;a++)
	{
		if(ranjau2[e[a]] == 1)
		{
			nilai2 += 1;
		}
		else
		{
			nilai1 += 1;
		}
	}
	if(nilai1 >= 10)
	{
		status=1;
		break;
	}
	if(nilai2 >= 10)
	{
		status=2;
		break;
	}
	b = 1;
	giliran = 2;
	continue;
}
}
}
void* pemainkedua()
	{
		int a, b=0, c, d[4], e[4], f;
		for(a=0;a<16;a++){
		ranjau2[a] = 0;
	}
	while(1)
	{
		while(giliran!=2){}
		system("clear");
		if(b==0)
		{
			printf("Nama pemain kedua:\n");
			scanf("%s", nama_p_2);
			b=1;
			giliran = 1;
			continue;
		}
		else if(b==1)
		{
			printf("Hai %s, Silahkan pasang ranjau anda\n", nama_p_2);
			printf("Mau pasang ranjau berapa (maksimal 4 ranjau)?\n");
			scanf("%d", &c);
			if(c>4 || c<=0)
			{
				printf("Ranjau yang dipasang terlalu banyak, maksimal 4 ranjau\n");
				getchar();
				getchar();
				continue;
			}
psg_ranjau_2:
	system("clear");
	printf("Lubang yang sudah ada ranjaunya : ");
	for(a=0;a<16;a++)
	{
		if(ranjau2[a] == 1)
		{
			printf("%d ", a+1);
		}
	}
	printf("\nMau pasang ranjau di lubang ke berapa? (1-16)\n");
	for(a=0;a<c;a++)
	{
		scanf("%d", &d[a]);
		d[a] = d[a] - 1;
		if(d[a]>=16 || d[a]<0)
		{
			printf("Lubang yang akan dimasukkan tidak tersedia, silahkan coba lagi\n");
			getchar();
			getchar();
			goto psg_ranjau_2;
		}
	}
	for(a=0;a<c;a++)
	{
		for(f=0;f<c;f++)
		{
			if(a==f)
			{
				continue;
			}
			if(d[a] == d[f])
			{
				printf("Ranjau tidak bisa dipasang ke tempat yang sama, coba lagi\n");
				getchar();
				getchar();
				goto psg_ranjau_2;
			}
		}
	}
	for(a=0;a<c;a++)
	{
		if(ranjau2[d[a]] != 1)
		{
			ranjau2[d[a]] = 1;
		}
		else
		{
			printf("Ranjau tidak bisa dipasang ke tempat yang sama, coba lagi\n");
			getchar();
			getchar();
			goto psg_ranjau_2;
		}
	}
	b = 2;
	giliran = 1;
	continue;
}
else if(b==2)
	{
		tebak_ranjau_2:
		printf("Hai %s, Silahkan tebak ranjau yang disimpan di 4 lubang (1-16)\n", nama_p_2);
		for(a=0;a<4;a++)
		{
			scanf("%d", &e[a]);
			e[a] = e[a] - 1;
			if(e[a] >= 16 || e[a]<0)
			{
				printf("Lubang tidak tersedia, coba lagi\n");
				getchar();
				getchar();
				system("clear");
				goto tebak_ranjau_2;
			}
		}
		for(a=0;a<4;a++)
		{
			for(c=0;c<4;c++)
			{
				if(a==c)
				{
					continue;
				}
				if(e[a] == e[c]){
				printf("Silahkan cari lubang lain, jangan lubang yang sama!");
				getchar();
				getchar();
				system("clear");
				goto tebak_ranjau_2;
			}
		}
	}
for(a=0;a<4;a++)
	{
		if(ranjau1[e[a]] == 1)
		{
			nilai1 += 1;
		}
		else
		{
			nilai2 += 1;
		}
	}
	if(nilai1 >= 10)
	{
		status=1;
		break;
	}
	if(nilai >= 10)
	{
		status=2;
		break;
	}
	system("clear");
	printf("[SCORE]\n");
	printf("%s: %d\n", nama_p_1, nilai1);
	printf("%s: %d\n", nama_p_2, nilai2);
	printf("Klik tombol apapun untuk melanjutkan...\n");
	getchar();
	getchar();
	b = 1;
	giliran = 1;
	continue;
	}
}
}

