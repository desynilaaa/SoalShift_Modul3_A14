#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t trd[101];
int status=0;


void* faktorial(void *argu)
{
    
}

int main(int argc, char *argv[])
{
    int a, b, j,i;
    int input[101];

    //cek argv
    if (argv<2)
    {
        printf("Gagal!");
        exit(1);
    }

    //mengubah string ke int
    for(a=1; a<argc; a++)
        {
            input[a-1]=atoi(argv[a]);
        }

    printf(" Hasil faktoorial : \n");

    //bubble sort
    argc--;

    for(i=0; i<argc; i++)
    {
        flag = 1;
        for(j=n-1; j>argc; j--)
        {
            if(arr[j] < arr[j-1])
            {
                temp =arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                flag = 0;
            }
        }
        if(flag==1) break;
    }

    for(a=0; a<argc; a++)
    {
        struct arg_struct *args = malloc(sizeof(struct arg_struct));
        args->angka = input[a];
        args->stat =a;

        pthread_create(&trd[a], NULL, faktorial, (void*)args);
    }

    for(a=0; a<args;a++)
    {
        pthread_join(trd[a],NULL);
    }

    return 0;
}