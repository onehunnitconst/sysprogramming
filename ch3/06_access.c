/*
    access: pathname에 지정된 파일이 mode로 지정한 권한을 지니고 있는지 확인 후 리턴
*/

#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

int main() {
    int permission;

    if (access("linux.txt", F_OK) == -1 && errno == ENOENT) {
        printf("linux.bak: File not exist.");
    }

    permission = access("linux.txt", R_OK);

    if (permission == 0)
        printf("linux.txt: Read permission OK\n");
    else if (permission == -1 && errno == EACCES) {
        printf("linux.txt: No Read Permission\n");
    }
}