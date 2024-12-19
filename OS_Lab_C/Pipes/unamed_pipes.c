#include<stdio.h>
#include<unistd.h>


int main(){
    //unamed pipe faccilates communication b/w parent process and child process
    int fd[2];
    /**
     * 0 means read
     * 1 means write
     */
    char data[1000];
    pid_t pid = fork();
    if(pid > 0){
        printf("Iam a parent\n");
        printf("writting to a pipe\n");
        close(fd[0]);
        char message[] = "Hello there, you child";
        write(fd[1], message, sizeof(message) );
        close(fd[1]);
    }
    else{
        close(fd[1]);
        printf("Iam a child");
        read(fd[0], data, sizeof(data));
        printf("Receive mesage  = %s\n", data);
        close(fd[0]);
    }
}