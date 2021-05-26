#include <stdio.h>

int main()
{
    int limit, i, id;
    printf("Enter a limit:\n");
    scanf("%d",&limit);
    id = fork();
    if(id!=0)
    {   
        
        for(i=1;i<=limit;i++)
        {
            if(i%2 !=0)
            printf("%d is odd and the parent process id is %d\n",i,id);
        }
        printf("\n");
    }
    if(id==0)
    {
        wait();
        for(i=1;i<=limit;i++)
        {
            if(i%2 == 0)
            {
                printf("%d is even and the child process id is %d\n",i,id);
            }
        }
    }
    
    return 0;
}
