#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<string.h>

#define SHM_SIZE 1024
int main()
{

    //creating shared memory

    int mid = shmget((key_t)123, SHM_SIZE, IPC_CREAT | 0666);

    if(mid < 0){
        perror("Memory creation Failed\n");
        exit(-1);
    }
    printf("Key value of shared memory = %d\n", mid);
    //attaching memory to the current process virtual memory
    void *shm_a = shmat(mid, NULL, 0);
    if(shm_a == (void *)-1){
        perror("attachment failed\n");
        exit(-1);
    }
    printf("attached loc = %p", shm_a);
    char buffer[SHM_SIZE];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy((char *)shm_a, buffer, SHM_SIZE);
    if (shmdt(shm_a) == -1)
    {
        printf("deattachment error\n");
    }
}