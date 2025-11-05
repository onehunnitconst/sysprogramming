/*
    상수를 이용하여 파일 종류 검색
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat statbuf;
    int kind;

    stat("linux.txt", &statbuf);

    printf("Mode = %o\n", (unsigned int)statbuf.st_mode);

    kind = statbuf.st_mode & S_IFMT; // S_IFMT는 파일의 종류 비트를 가져오기 위한 비트마스크

    printf("Kind = %o\n", kind);

    switch (kind) {
        case S_IFLNK:
            printf("linux.txt is Symbolic Link\n");
            break;
        case S_IFDIR:
            printf("linux.txt is Directory\n");
            break;
        case S_IFREG:
            printf("linux.txt is Regular File\n");
            break;
    }
}