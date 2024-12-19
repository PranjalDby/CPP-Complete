#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int fd = open("fifo", O_RDONLY);
    mkfifo("fifo", 0777);
    char buffer[1000];
    if (fd > 0)
    {
        read(fd, buffer, sizeof(buffer));
        printf("Readed = %s\n", buffer);
    }
    close(fd);
}