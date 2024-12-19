#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct structure{
    int id;
    int iterations;
} ;
void *display(void *a){
    struct structure *st = (struct structure *)a;
    printf("Unique id = %d\n", st->id);
    for (int i = 0; i < st->iterations;i++){
        printf("*\n");
    }
    pthread_exit(NULL);
};
int main(int argc, char const *argv[])
{
    /* code */
    pthread_t t[10];
    struct structure st;
    for (int i = 0; i < 10; i++)
    {
        st.id = i * 10;
        st.iterations = i;
        pthread_create(&t[i], NULL, display, (void *)&st);
        pthread_join(t[i],NULL);
    }

    return 0;
}
