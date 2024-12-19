#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct args{
    char *name;
};
void *findl(void *str)
{
    struct args* a = (struct args *) str;
    int *l = (int *)malloc(sizeof(int));
    *l = 0;
    for (int i = 0;a->name[i] != '\0';i++){
        printf("%s\n", a->name);
        (*l)++;
    }
    printf("%d\n", *l);
    pthread_exit(l);
}
int main(){

    //program to find the length of the string passed.
    pthread_t pid;
    char *maxChars = (char *)malloc(sizeof(char) * 1000);
    printf("Enter the String:\n");
    scanf("%s", maxChars);
    struct args ag;
    ag.name = &maxChars[0];
    // printf("%s\n", maxChars);
    pthread_create(&pid, NULL, findl, (void *)&ag);
    int *l = (int *)malloc(sizeof(int) * 1);
    pthread_join(pid,(void **)&l);
    printf("lenght = %d\n",*l);
}