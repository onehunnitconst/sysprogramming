// 현재 작업 디렉토리 위치 검색: getcwd

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *cwd;
    char wd1[BUFSIZ];
    char wd2[10];

    // 사용자가 지정한 버퍼에 경로 저장
    getcwd(wd1, BUFSIZ);
    printf("wd1 = %s \n", wd1);

    // size에 지정한 크기로 버퍼 할당하고 경 저장
    cwd = getcwd(NULL, BUFSIZ);
    printf("cwd1 = %s \n", cwd);
    free(cwd);

    // 시스템이 알아서 버퍼를 할당하고 경로 저장
    cwd = getcwd(NULL, 0);
    printf("cwd2 = %s \n", cwd);
    free(cwd);

    if (getcwd(wd2, 10) == NULL) {
        perror("getcwd");
        exit(1);
    }
}