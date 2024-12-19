#include<stdio.h>
#include<pthread.h>


struct Args {
    int *arr;
    int n;
    double avg;
    int min, max;
};

void *average(void *args){
    printf("Function called\n");
    struct Args *arguments = (struct Args *)args;
    int n = arguments->n;
    int s = 0;
    for (int i = 0; i < n;i++){
        s += arguments->arr[i];
    }
    arguments->avg = (double) s / n;
    printf("%f\n", arguments->avg);
    pthread_exit(arguments);
}
void *maximum(void *args){
    printf("maximum called\n");
    struct Args *casted = (struct Args *)args;
    int n = casted->n;
    int max = -10000000;
    for (int i = 0; i < n;i++){
        if(max < casted->arr[i]){
            max = casted->arr[i];
        }
    }
    casted->max = max;
    pthread_exit(casted);
}
void *minimum(void *args){
    printf("minimum called\n");
    struct Args *casted = (struct Args *)args;
    int n = casted->n;
    int min = 1000000;
    for (int i = 0; i < n; i++)
    {
        if (min > casted->arr[i])
        {
            min = casted->arr[i];
        }
    }
    casted->min = min;
    pthread_exit(casted);
}
int main(){
    int arr[] = {10, 3, 45, 10, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    pthread_t id1[3];
    struct Args arg;
    arg.arr = arr;
    arg.n = n;
    struct Args *res;
    pthread_create(&id1[0], NULL, average, (void *)&arg);
    pthread_join(id1[0], (void **)&res);
    printf("\n%f avg = ", res->avg);
    pthread_create(&id1[1], NULL, maximum, (void *)&(arg));
    pthread_join(id1[1], (void **)&res);
    pthread_create(&id1[2], NULL,minimum, (void *)&(arg));
    printf("max = %d\n", res->max);
    pthread_join(id1[2], (void **)&res);
    printf("min = %d\n", res->min);
}