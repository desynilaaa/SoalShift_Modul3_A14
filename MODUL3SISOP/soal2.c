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
