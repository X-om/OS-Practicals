#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    system("clear");
    int n;
    printf("Enter the number till you want to print the even and odd : ");
    scanf("%d",&n);
    
    pid_t pid;

    if((pid=fork())<0){
        printf("\nFork error !\n");
        exit(0);
    }
    if(pid == 0)
    {
        sleep(5);
        printf("\nchild Proccess\nID : %d \n\n",getpid());
        printf("Odd Numbers !\n");
        for(int i = 1; i<=n; i++)
        {
            if(i%2!=0)
                printf("%d\n",i);
        }
        exit(0);
    }
     if(pid > 0)
    {
        printf("\nFork successfull\n");
        printf("\nParent Proccess\nID : %d \n\n",getppid());
        printf("Even Numbers !\n");
        for(int i = 1; i<=n; i++)
        {
            if(i%2==0)
                printf("%d\n",i);
        }
        wait(5);
        exit(0);
    }
    exit(0);
}