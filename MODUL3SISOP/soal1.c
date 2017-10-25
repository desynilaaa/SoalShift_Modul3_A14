#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	key_t key = 2510;
	char senjata_tersedia[6][8] = {"MP4A1", "PM2-V1","SS2-V5","SPR-3","SPG1-V3","MINE"};
	int shmid = shmget(key, sizeof(int)*6, IPC_CREAT);
	int *stock;
	stock = shmat(shmid, NULL, 0);
	while(1)
	{
		int n, a, jml;
		char pil_senjata[8];
		system("clear");
		printf("1.Lihat ketersediaan senjata");
		printf("2. Beli senjata sekarang");
		printf("3. Keluar");
		scanf("%d", &n);
		if(n == 1)
	{
	system("clear");
	for(a=0;a<6;a++)
	{
		if(stock[a]>0)
		{
			printf("Jumlah %s di stock = %d barang\n", senjata_tersedia[a], stock[a]);
		}
	}
	printf("Press any key to continue...\n");
	getchar();
	getchar();
}
else if(n == 2)
{
	system("clear");
	printf("Format input [Nama barang] [Jumlah stok]\n");
	scanf("%s %d", pil_senjata, &jml);
	for(a=0;a<6;a++)
	{
		if(strcmp(pil_senjata, senjata_tersedia[a]) == 0)
		{
			if(stock[a] < jml)
			{
				printf("Barang di stok tidak cukup\n");
				printf("Press any key to continue...\n");
				getchar();
				getchar();
				break;
			}
			stock[a] -= jml;
			break;
		}
	}
}
else if(n == 3)
{
	system("clear");
	printf("EXIT\n");
	shmdt(stock);
	shmctl(shmid, IPC_RMID, NULL);
	break;
}
}
return 0;
}
