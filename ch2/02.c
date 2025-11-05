#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    if (rmdir("sangsu") == -1) {
        perror("sangsu");
        exit(1);
    }
    return 0;
}ch2/02.c