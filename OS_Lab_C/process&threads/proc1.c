#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    // creating the child process;
    pid_t pid = fork();
    char *args[] = {"ls", "-l", NULL};
    // if(pid == 0){
    //     printf("Child process\n");
    //     for (int i = 0; i < 5;i++){
    //         printf("Mayday !");
    //         if(i == 3){
    //             sleep(2);
    //         }
    //     }
    // }
    // else if(pid > 0){
    //     printf("Parent process\n");
    //     printf("parent process terminates\n");
    // }

    //to make zombies process
    // if(pid > 0){
    //     printf("parent process pid = %d", getpid());
    //     printf("child process pid = %d", pid);
    //     sleep(10);
    //     printf("terminating...\nn");
    // }
    // else if(pid == 0){
    //     printf("Hi. iam a child\n");
    //     exit(0);
    // }

    // execv() replacing current process some other process
     if(pid > 0){
         printf("parent process pid = %d\n", getpid());
         printf("child process pid = %d\n", pid);
         wait(NULL);
         printf("terminating...\n");
     }
     else if(pid == 0){
         printf("Hi. iam a child\n");
         execv("/bin/ls", args);
         printf("execv failed\n");
         exit(-1);
     }
}