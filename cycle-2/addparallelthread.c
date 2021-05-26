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
    sleep(3);
    printf("End of thread\n");

    return NULL;
}

int main() 
{
    printf("First number: ");
    scanf("%d",&global[0]);

    printf("Second number: ");
    scanf("%d",&global[1]);

    pthread_t sum1, sum2;
    pthread_create(&sum1,NULL,add,global);
    pthread_create(&sum2,NULL,add,global);
    pthread_join(sum1,NULL);
    pthread_join(sum2,NULL);

    return 0;
}
