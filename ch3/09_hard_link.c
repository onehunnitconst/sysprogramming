/*
    하드 링크
    #include <unistd.h>

    int link(const char *oldpath, const char *newpath);
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat statbuf;

    stat("linux.txt", &statbuf);
    printf("Before link: %lu\n", (unsigned long)statbuf.st_nlink);

    link("linux.txt", "linux_link.ln");

    stat("linux.txt", &statbuf);
    printf("After link: %lu\n", (unsigned long)statbuf.st_nlink);
}
