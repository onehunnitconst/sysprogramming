#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[BUFSIZ];

    realpath("linux_symlink.ln", buf); // 심볼릭 링크의 실제 경로 얻기
    printf("Real path: %s\n", buf);
}