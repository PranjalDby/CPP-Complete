#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
    // open Test2 dir;
    char *dirname = (char *)malloc(sizeof(char) * 50);
    printf("Enter the name of dir = ");
    fgets(dirname, 50, stdin);
    DIR *dir = opendir(dirname);
    if(dir == NULL){
        perror("Error opening a directory\n");
        return 1;
    }
    else{
        struct dirent *dir_struct;
        while((dir_struct = readdir(dir)) != NULL){
            printf("inode no = %d\n", (int)dir_struct->d_ino);
            printf("%s\n", dir_struct->d_name);
        }
    }
}