#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
    char *file = "fifo";
    mkfifo(file, 0777);
    int fd;
    char data[100];
    fd = open(file, O_WRONLY);//writting to the file
    char buffer[] = "Hello there iam pranjal,";
    write(fd, buffer, sizeof(buffer));
    close(fd);
}