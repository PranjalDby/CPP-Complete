#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    // creating the child process;
    pid_t pid = fork();
    if(pid > 0){
        printf("P1\n");
        wait(NULL);
    }
    else if(pid == 0){
        pid_t pid2 = fork();
        if (pid2 > 0)
        {
            printf("P2\n");
            wait(NULL);
            pid_t pid3 = fork();
            if (pid3 > 0)
            {
                
                printf("P3\n");
                wait(NULL);
            }
            else if (pid3 == 0)
            {
                sleep(1);
                pid_t pid6 = fork();
                if (pid6 > 0)
                {
                    wait(NULL);
                    printf("P6\n");
                }
                else if (pid6 == 0)
                {
                    sleep(1);
                }
            }
        }
        else if(pid2 == 0){
            pid_t pid4 = fork();
            if (pid4 > 0)
            {
                wait(NULL);
                sleep(1);
            }
            else if(pid4 == 0){
                printf("P4\n");
                sleep(1);
                pid_t p5 = fork();
                if(p5 > 0){
                    wait(NULL);
                    printf("P5\n");
                }
                else if(p5 == 0){
                    sleep(1);
                }
            }
        }
    }
}