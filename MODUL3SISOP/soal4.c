#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t trd[101];
int status=0;

typedef struct arg_struct
{
    int angka;
    int stat;
    
}args;


void* faktorial(void *komentar)
{
    int a,b;
    struct arg_struct *args = (struct arg_struct *)komentar;
    while(args->stat != status)
    {}
    int input =args->angka;

    //hitung faktorial
    int hasil=1;
    for(b=input; b>1; b--)
        {
            hasil=hasil*b;
        }
        printf("%d! = %d \n", input, hasil);
        status++;
        free(komentar);
}

int main(int argc, char *argv[])
{
    int a, b, j,i;
    int input[101];

    //cek argv
    if (argc<2)
    {
        printf("Gagal!");
        exit(1);
    }

    //mengubah string ke int
    for(a=1; a<argc; a++)
        {
            input[a-1]=atoi(argv[a]);
        }

    printf(" Hasil faktorial : \n");

    //bubble sort
    argc--;
    int temp=0;
    for(i=1; i<argc; i++)
    {
        //flag = 1;
        for(j=1; j<argc; j++)
        {
            if(input[j-1] >= input[j])
            {
                temp =input[j-1];
                input[j-1]=input[j];
                input[j]=temp;
                //flag = 0;
            }
        }
        //if(flag==1) break;
    }

    for(a=0; a<argc; a++)
    {
        struct arg_struct *args = malloc(sizeof(struct arg_struct));
        args->angka = input[a];
        args->stat =a;

        pthread_create(&trd[a], NULL, faktorial, (void*)args);
    }

    for(a=0; a<argc;a++)
    {
        pthread_join(trd[a],NULL);
    }

    return 0;
}