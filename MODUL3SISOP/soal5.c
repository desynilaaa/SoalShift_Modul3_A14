#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <dirent.h>
#include <string.h>

void *print_message_function( void *ptr );
void *print_message_function2( void *ptr );

int num =0;
char word[20], word2[20];
char string[30];

int main(int argc, char*argv[])
{
	scanf("%s %s",word, word2);
    
     pthread_t thread1, thread2;//inisialisasi awal
     const char *message1 = "Thread 1";
     const char *message2 = "Thread 2";
     int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);//membuat thread pertama
     if(iret1)//jika eror
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, print_message_function2, (void*) message2);//membuat thread kedua
     if(iret2)//jika gagal
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }

     //printf("pthread_create() for thread 1 returns: %d\n",iret1);
     //printf("pthread_create() for thread 2 returns: %d\n",iret2);

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     exit(EXIT_SUCCESS);
}

void *print_message_function( void *ptr )
{

	char *path="/bin";
	DIR* dir;

	dir=opendir(path);
	FILE *in_file = fopen("/home/desy/MODUL3SISOP/Novel.txt", "r");

	if (in_file == NULL)
	{
    	printf("Error file missing\n");
    	exit(-1);
	}
	while(!feof(in_file))//this loop searches the for the current word
	{
	    fscanf(in_file,"%s",string);
	    if(!strcmp(string,word))//if match found increment num
	    num++;
	}

	printf("%s : %d \n",word,num );
	num=0;
}


void *print_message_function2( void *ptr )
{

	char *path="/bin";
	DIR* dir;

	dir=opendir(path);
	FILE *in_file = fopen("/home/desy/MODUL3SISOP/Novel.txt", "r");

	if (in_file == NULL)
	{
    	printf("Error file missing\n");
    	exit(-1);
	}
	while(!feof(in_file))//this loop searches the for the current word
	{
	    fscanf(in_file,"%s",string);
	    if(!strcmp(string,word2))//if match found increment num
	    num++;
	}

	printf("%s : %d \n",word2,num );
}