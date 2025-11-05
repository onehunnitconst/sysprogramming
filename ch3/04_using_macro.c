/*
    상수 이외의 매크로를 사용하여 비트마스크와 알아서 연산
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat statbuf;

    stat("linux.txt", &statbuf);

    printf("Mode: %o\n", statbuf.st_mode);

    if(S_ISLNK(statbuf.st_mode))
        printf("linux.txt is Symbolic Link\n");
    if(S_ISREG(statbuf.st_mode))
        printf("linux.txt is Regular File\n");
    if(S_ISDIR(statbuf.st_mode))
        printf("linux.txt is Directory\n");

    return 0;
}