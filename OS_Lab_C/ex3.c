#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#define MAX 1024

void encryptor(char *buffer,int n){
    for (int i = 0; i < n;i++){
        buffer[i] = ((buffer[i]+3)+'A') % 26 + 'a';
    }
    // printf(" at func = %s\n", buffer);
}
int main()
{
    int fd = open("input1.txt", O_CREAT | O_RDWR, 0777);
    printf("Enter the content: \n");
    char buffer[MAX];
    buffer[MAX-1] = '\0';
    fgets(buffer, MAX, stdin);
    printf("Before Encryption = %s\n", buffer);

    int n= 0;
    for (int i = 0; buffer[i]!='\0';i++){
        n++;
    }

    encryptor(buffer,n);
    printf("after encryption:%s\n",buffer);
    // struct stat fst;
    // off_t size;
    // if (fstat(fd, &fst) != -1)
    // {
    //     size = fst.st_size;
    //     printf("Not Error.");
    // }
    write(fd, buffer, n);
    close(fd);
}