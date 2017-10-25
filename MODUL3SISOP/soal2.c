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
