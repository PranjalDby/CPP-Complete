#include<stdio.h>
#include<pthread.h>

int shared = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *upda()
{
    for (int i = 0; i < 100;i++){
        pthread_mutex_lock(&mutex);
        shared++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t th[100];
    for(int i = 0; i < 100;i++){
        pthread_create(&th[i], NULL, upda, NULL);
    }
    for (int i = 0; i < 100;i++){
        pthread_join(th[i], NULL);
    }
    printf("shared = %d\n", shared);
}