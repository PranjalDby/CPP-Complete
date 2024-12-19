#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>

int main()
{
    // creating new file
    int fd = open("Sample.txt", O_CREAT | O_WRONLY);
    if (fd > -1)
    {
        printf("File created successfully.\n");
        int mode = 0700;
        if (chmod("Sample.txt", mode) == -1)
        {
            perror("chmod failed");
            return -1;
        }

        // changing ownership
        struct group *grp;
        struct passwd *pass;
        grp = getgrnam("temp");
        pass = getpwnam("root");
        if (grp == NULL)
        {
            perror("getgrnam failed");
            return -1;
        }
        if (pass == NULL)
        {
            perror("getpwnam failed");
            return -1;
        }
        if (chown("Sample.txt", pass->pw_uid, grp->gr_gid) == -1)
        {
            perror("chown failed");
            return -1;
        }
    }
    else
    {
        perror("open failed");
        return -1;
    }
    close(fd);
    // creating hardlink
    if (link("Sample.txt", "sample_link.txt") == -1)
    {
        perror("link failed");
        return -1;
    }
    return 0;
}