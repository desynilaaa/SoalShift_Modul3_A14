#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
int main(int argc, char*argv[])
{   
int num =0;
char word[2000];
char string[30];

char *path="/bin";
DIR* dir;

dir=opendir(path);
FILE *in_file = fopen("/home/desy/MODUL3SISOP/Novel.txt", "r");

if (in_file == NULL)
{
    printf("Error file missing\n");
    exit(-1);
}

scanf("%s",word);

printf("%s\n", word);

while(!feof(in_file))//this loop searches the for the current word
{
    fscanf(in_file,"%s",string);
    if(!strcmp(string,word))//if match found increment num
    num++;
}

printf("%s : %d \n",word,num );
return 0;
}