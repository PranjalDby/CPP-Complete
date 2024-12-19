#include<stdio.h>
#include<dirent.h>


int main(){
    //opendir

    DIR *dir;
    dir = opendir(".");//opening current directory for reading and it returns structure pointer
    struct dirent *entry;
    if (dir)
    {
        printf("Contents of dir\n");
        while((entry = readdir(dir)) != NULL){
            printf("Filename = %s\n", entry->d_name);
        }
    }
}