#include <stdlib.h>
#include <stdio.h>

int main() {
    if (rename("sangsu", "sangsu2") == -1) {
        perror("sangsu");
        exit(1);
    }
    return 0;
}