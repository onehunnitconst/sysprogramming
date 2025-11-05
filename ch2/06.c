#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *cwd;

    cwd = getcwd(NULL, BUFSIZ);
    printf("1. Current Directory: %s \n", cwd);

    if (chdir("sangsu2") == -1) {
        perror("sangsu2");
        exit(1);
    }

    cwd = getcwd(NULL, BUFSIZ);

    printf("2. Current Directory: %s \n", cwd);

    free(cwd);

    return 0;
}