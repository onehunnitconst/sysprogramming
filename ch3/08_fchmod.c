#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;
    struct stat statbuf;

    fd = open("linux.txt", O_RDONLY);

    if (fd == -1) {
        perror("open: linux.txt");
        exit(1);
    }

    fchmod(fd, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH);

    fstat(fd, &statbuf);
    printf("1. Mode = %o\n", (unsigned int)statbuf.st_mode);

    statbuf.st_mode |= S_IWGRP;
    statbuf.st_mode &= ~(S_IROTH);

    fchmod(fd, statbuf.st_mode);
    printf("2. Mode = %o\n", (unsigned int)statbuf.st_mode);
    close(fd);
}