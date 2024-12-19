#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
    int pid1 = fork();//parent
    if(pid1 < 0){
        perror("fork");
        return 1;
    }
    if(pid1 > 0){
        // parent of pid1;
        printf("parent pid = %d\n", getpid());
        wait(NULL);
    }
    else if(pid1 == 0){
        int p2 = fork();
        if(p2 < 0){
            return 1;
        }
        if(p2 > 0){
            printf("Waiting for child to creates its child\n");
            printf("child pid = %d\n", getpid());
            wait(NULL);
        }
        else if (p2 == 0){
            sleep(5);
            int p3 = fork();
            if (p3 < 0)
            {
                return 1;
            }
            if (p3 > 0)
            {
                printf("Grand Child pid = %d\n", getpid());
                printf("Grand child parent = %d\n", getppid());
                wait(NULL);
            }
            else if (p3 == 0)
            {
                printf("Hey Iam a grandchild\n");
            }
        }
        
    }
    return 0;
}
