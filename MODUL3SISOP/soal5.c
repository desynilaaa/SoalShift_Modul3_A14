#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t trd[101];

int main(int argc, char *argv[])
{
	int a=0;

	for(a=1; a<argc; a++)
		{
			pthread_create(&trd[a], NULL, CARI, (void*)argv[i]);
			printf("Coba : %s\n ", argv[a]);
		}

	for(a-0; a<argc; a++)
		{
			pthread_join(trd[a], NULL);
		}
	return 0;
}
