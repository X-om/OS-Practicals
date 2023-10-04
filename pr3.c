#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int main(){
    int filedes[2];
    int n;
    char string[MAX] = "Hello World";
    char line[MAX];
    
    printf("Enter the message to be given to the parent : ");
    scanf("%s",string);

    pid_t pid;
    if(pipe(filedes)<0){
        printf("Error , Pipe creation faild !\n");
        exit(0);
    }
    if((pid = fork())<0){
        printf("Fork , error !\n");
        exit(0);
    }

    if(pid > 0){
        printf("\n\n In parent ! \n\n");
        printf("parent id : %d",getppid());
        close(filedes[0]);
        write(filedes[1],string,strlen(string));
    }

    if(pid == 0){
        sleep(10);
        printf("\n\nIn child !\n\n");
        printf("child id : %d",getpid());
        close(filedes[1]);
        n = read(filedes[0],line,strlen(string));    
        line[n] = '\0';
        printf("\n\nbytes are : %d",n);
        printf("\n\nThe data read by child is : %s",line);
    }
    exit(0);
}
