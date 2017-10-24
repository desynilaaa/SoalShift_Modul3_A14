#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, temp, flag, j, ts;
    int arr[100];
    scanf("%d", &ts);
    for(i=0; i<ts; i++)
    {
        scanf("%d", &arr[i]);
    }
    n=ts;
    for(i=0; i<n; i++)
    {
        flag = 1;
        for(j=n-1; j>i; j--)
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
    for(i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}
