#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define Max 1024
int main()
{
    char buffer[Max];
    int fd = open("sample.txt", O_RDONLY, 0777);
    if (fd < 1)
    {
        printf("file not found.");
    }
    else
    {
        int flag = 0;
        struct stat filestate;
        if (fstat(fd, &filestate) == -1)
        {
            printf("Some error\n");
            close(fd);
        }
        off_t size = filestate.st_size;
        ssize_t bytesRead;
        printf("Which part do you want to read: 1. for first Half 2. for second half \n");
        scanf("%d", &flag);
        printf("Total File Size:%d\n", (int)size);
        switch (flag)
        {
        case 1:
            lseek(fd, 0, SEEK_SET);
            bytesRead = read(fd, buffer, size / 2);
            break;
        case 2:
            lseek(fd, size - size / 2, SEEK_SET);
            off_t next_half = size - (size / 2);

            bytesRead = read(fd, buffer, next_half);
            break;
        default:
            printf("Invalid option.\n");
            close(fd);
            return 1;
        }
        if (bytesRead < 0)
        {
            perror("Read error");
            close(fd);
            return 1;
        }
        buffer[bytesRead] = '\0';
        printf("%s\n", buffer);
        close(fd);
    }
}