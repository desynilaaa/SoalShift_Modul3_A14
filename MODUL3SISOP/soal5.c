#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_t trd[101];

void *CARI(void *argv)
{
	int total=0;
	char temp[700];
	char baris[700];
	FILE *buka_file;
	buka_file = fopen ("Novel.txt","r");

	strcpy (temp,argv);

	while(1)
	{
		if (fscanf(buka_file, "%s", baris)==EOF) break;

		if(strstr(baris, argv)!=NULL) total++;
	}
		fclose(buka_file);
		printf("%s : %d\n", temp, total);
}

int main(int argc, char *argv[])
{
	int a=0;

	for(a=1; a<argc; a++)
		{
			pthread_create(&trd[a], NULL, CARI, (void*)argv[a]);
			//printf("Coba : %s\n ", argv[a]);
		}

	for(a=0; a<argc; a++)
		{
			pthread_join(trd[a], NULL);
		}
	return 0;
}
