/*
    opendir: 디렉토리 스트림을 열고 해당 디렉토리에 대한 포인터를 반환합니다.
    readdir: 디렉토리 스트림에서 다음 항목을 읽고 해당 항목에 대한 포인터를 반환합니다.
    closedir: 디렉토리 스트림을 닫습니다.
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dp;
    struct dirent *dent;

    dp = opendir("ch2");

    while((dent = readdir(dp))) {
        printf("File Name: %s \t", dent->d_name);
        printf("Inode Number: %ld \n", (long)dent->d_ino);
    }
    
    closedir(dp);
}