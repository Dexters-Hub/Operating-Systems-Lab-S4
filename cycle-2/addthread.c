#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[2];

void *add(void *arg)
{
    int *arr;
    arr = arg;

    int n1,n2,sum;
    n1=arr[0];
    n2=arr[1];
    sum = n1+n2;

    printf("%d + %d = %d\n",n1,n2,sum);

    return NULL;
}

int main() 
{
    printf("First number: ");
    scanf("%d",&global[0]);

    printf("Second number: ");
    scanf("%d",&global[1]);

    pthread_t sum;
    pthread_create(&sum,NULL,add,global);
    pthread_join(sum,NULL);

    return 0;
}
