//allowing race condition
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t s;
int shared = 0;

void *update(){
    // printf("Updating shared variable");
    for (int i = 0; i < 100;i++){
        sem_wait(&s);
        shared += 1;
        sem_post(&s); // unlock critical section
    }
    pthread_exit(NULL);
}
int main(){


    //synchronizing using semaphore
    pthread_t t[5];
    sem_init(&s, 0, 1);
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&t[i], NULL, update, NULL);
    }
    for (int i = 0; i < 5;i++){
        pthread_join(t[i],NULL);
    }
    sem_destroy(&s);
    printf("shared_variable= %d\n", shared);
}