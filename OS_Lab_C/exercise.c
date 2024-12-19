#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
    char *dirname;
    dirname = (char *)malloc(sizeof(char) * 50);
    printf("Enter the directory name = ");
    fgets(dirname, 50, stdin);
    char *mode_input = (char *)malloc(sizeof(char) * 4);
    printf("Enter the mode for user:group:other: ");
    scanf("%s", mode_input);
    mode_t mode = (mode_t)strtol(mode_input, NULL, 8);
    int status = mkdir(dirname, mode);
    if(status < 0){
        perror("file not created\n");
    }
    else{
        printf("File created successfully\n");
    }
}