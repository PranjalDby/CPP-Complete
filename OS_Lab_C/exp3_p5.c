#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int p1 = fork();
    if (p1 < 0)
    {
        perror("fork");
        return 1;
    }
    if (p1 > 0)
    {
        //do Nothin
        wait(NULL);
    }
    else if (p1 == 0)
    {

        printf("P1->ppid = %d\n", getppid());
        printf("P1->pid = %d\n", getpid());
        int p2 = fork();
        if (p2 < 0)
        {
            perror("fork");
            return 1;
        }
        if (p2 > 0)
        {
            // P3-process starts
            int p3 = fork();
            if (p3 < 0)
            {
                perror("fork");
                return 1;
            }
            if (p3 > 0)
            {
                wait(NULL);
            }
            else if (p3 == 0)
            {
                printf("P3->ppid = %d\n", getppid());
                printf("P3->pid = %d\n", getpid());
                // printf("P3->ppid = %d\n", getppid());
                int p6 = fork();
                if (p6 < 0)
                {
                    perror("fork");
                    return 1;
                }
                if (p6 > 0)
                {
                    wait(NULL);
                }
                else if (p6 == 0)
                {
                    printf("P6->ppid = %d\n", getppid());
                    printf("P6->pid = %d\n", getpid());
                    printf("END:P6\n");
                }
            }
            wait(NULL);
        }
        else if (p2 == 0)
        {
            printf("P2->ppid = %d\n", getppid());
            printf("P2->pid = %d\n", getpid());
            int p4 = fork();
            if (p4 < 0)
            {
                perror("fork");
                return 1;
            }
            if (p4 > 0)
            {
                wait(NULL);
            }
            else if (p4 == 0)
            {
                printf("P4->ppid = %d\n", getppid());
                printf("P4->pid = %d\n", getpid());
                int p5 = fork();
                if (p5 < 0)
                {
                    perror("fork");
                    return 1;
                }
                if (p5 > 0)
                {
                    wait(NULL);
                }
                else if (p5 == 0)
                {
                    printf("P5->ppid = %d\n", getppid());
                    printf("P5->pid = %d\n", getpid());
                    printf("END:P5\n");
                }
            }
        }
    }
    return 0;
}
