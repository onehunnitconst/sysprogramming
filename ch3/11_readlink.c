#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buf[BUFSIZ];
    int n;

    n = readlink("linux_symlink.ln", buf, BUFSIZ); // 심볼릭 링크의 원본 경로 읽기

    if (n == -1) {
        perror("readlink");
        exit(1);
    }

    buf[n] = '\0';
    printf("linux_symlink.ln points to %s\n", buf);
}