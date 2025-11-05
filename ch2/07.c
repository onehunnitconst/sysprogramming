/*
fchdir: 파일 디스크립터를 인자로 받는 함수로, 해당 파일 디스크립터가 가리키는 디렉토리로 현재 작업 디렉토리를 변경한다.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *cwd;
    int fd;

    cwd = getcwd(NULL, BUFSIZ);
    printf("1. Current Directory: %s \n", cwd);

    fd = open("sangsu2", O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (fchdir(fd) == -1) {
        perror("fchdir");
        exit(1);
    }

    cwd = getcwd(NULL, BUFSIZ);
    printf("2. Current Directory: %s \n", cwd);

    close(fd);
    free(cwd);

    return 0;
}