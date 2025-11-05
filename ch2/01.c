#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    if (mkdir("sangsu", 0755) == -1) {
        perror("sangsu");
        exit(1);
    }
    return 0;
}