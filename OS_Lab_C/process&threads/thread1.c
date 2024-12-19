#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void* printMessage(void *args){
    const char *message = (char *)args;
    printf("%s\n", message);
    pthread_exit(NULL);
}
void* returnval(){
    int *ptr = (int *)malloc(sizeof(int) * 1);
    *ptr = 142;
    pthread_exit((void *)ptr);
}
void *printFibonnacci(void *num){
    int *n = (int *)malloc(sizeof(int));
    n = (int *)num;
    int a = 0;
    int b = 1;
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", a);
        int res = a + b;
        a = b;
        b = res;
    }
    pthread_exit(NULL);
}
void *printFactorial(void *num){
    int *n = (int *)malloc(sizeof(int));
    n = (int *)num;
    int fact = 1;
    for (int i = 0; i < *n; i++)
    {
        fact = fact * (*n - i);
    }
    printf("fact = %d\n", fact);
    pthread_exit(NULL);
}
int main(){
    pthread_t th1,th2;

    // pthread_create(&th1, NULL, printMessage, (void *)"Hello there Iam pranjal");
    // pthread_create(&th2, NULL, returnval, NULL);
    // // to prevent from preemption;
    // pthread_join(th1, NULL);
    // int *val = NULL;
    // pthread_join(th2,(void *)&val);
    // printf("%d\n", *((int *)val));
    // returning value from function

    int n = 8, n2 = 5;

    pthread_create(&th1, NULL, printFibonnacci, (void *)(&n));
    pthread_create(&th2, NULL, printFactorial,(void *)(&n2));
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
}