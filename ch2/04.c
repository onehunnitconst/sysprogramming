// 현재 작업 디렉토리 위치 검색: get_current_dir_name

#define _GNU_SOURCE
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
    char *cwd;

    // getcwd(NULL, 0)과 동일
    cwd = get_current_dir_name();
    printf("cwd = $s \n", cwd);
    free(cwd);
}