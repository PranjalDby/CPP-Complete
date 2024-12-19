#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#define MAX 1024
int main()
{
    int fd = open("sample2.txt", O_CREAT | O_RDWR, 0777);
    char buffer[MAX];
    struct stat fst;
    buffer[MAX - 1] = '\0';
    char opt = '0';
    printf("Enter The Text: ");
    while (1)
    {
        scanf("%s", buffer);
        if (buffer[0] == '$')
        {
            break;
        }
        if (fstat(fd, &fst) == -1)
        {
            break;
        }
        off_t size = fst.st_size;
        // printf("%d\n", size);
        if (fd > 0)
        {
            write(fd, buffer, size);
        }
    }
    close(fd);
}