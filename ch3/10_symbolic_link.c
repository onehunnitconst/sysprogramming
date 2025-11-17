/*
    심볼릭 링크
    #include <unistd.h>

    int symlink(const char *target, const char *linkpath);

    성공시 0, 실패시 -1 반환
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat statbuf;

    printf("stat: linux.txt\n");
    stat("linux.txt", &statbuf);
    printf("Link Count: %lu\n", (unsigned long)statbuf.st_nlink);
    printf("Inode: %lu\n", (unsigned long)statbuf.st_ino);

    if (symlink("linux.txt", "linux_symlink.ln") == -1) {
        perror("symlink error");
    }

    printf("stat: linux_symlink.ln\n");
    stat("linux_symlink.ln", &statbuf);
    printf("Link Count: %lu\n", (unsigned long)statbuf.st_nlink);
    printf("Inode: %lu\n", (unsigned long)statbuf.st_ino);

    printf("lstat: linux_symlink.ln\n");
    lstat("linux_symlink.ln", &statbuf);
    printf("Link Count: %lu\n", (unsigned long)statbuf.st_nlink);
    printf("Inode: %lu\n", (unsigned long)statbuf.st_ino);
}
