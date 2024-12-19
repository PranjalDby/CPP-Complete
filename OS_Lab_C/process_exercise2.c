#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
    int p1 = fork();
    if(p1 < 0){
        perror("fork");
        return 1;
    }
    if(p1 > 0){
        //parent-process
        int p2 = fork();
        if(p2 < 0){
            perror("fork");
            return 1;
        }
        if(p2 > 0){
            // parent of p2;
            wait(NULL);
        }
        else if(p2 == 0){
            printf("P2 finished\n");
        }
        int p3 = fork();
        if(p3 < 0){
            return 1;
        }
        if(p3 > 0){
            wait(NULL);
        }
        else if(p3 == 0){
            printf("P3 finished\n");
        }
        wait(NULL);
    }
    else if (p1 == 0){
        sleep(2);
        printf("P1 finished\n");
    }
}