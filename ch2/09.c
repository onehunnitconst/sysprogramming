/*
    telldir: 인자가 가리키는 디렉터리 스트림에서 현재 위치를 리턴한다.
    seekdir: 인자가 가리키는 디렉터리 스트림에서 readdir() 함수가 다음 항목을 읽을 수 있는 위치로 오프셋을 이동시킨다.
    rewinddir: 인자가 가리키는 디렉터리 스트림의 위치를 처음으로 되돌린다.
*/

#include <sys/syslimits.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dp;
    struct dirent *dent;
    long loc;

    dp = opendir("ch2");

    printf("Start Position: %ld \n", telldir(dp));

    while ((dent = readdir(dp))) {
        printf("Read: %s \t", dent->d_name);
        printf("Current Position: %ld \n", telldir(dp));
    }

    printf("** Directory Position Rewind ** \n");
    rewinddir(dp);
    printf("Current Position: %ld \n", telldir(dp));

    printf("** Move Directory Pointer ** \n");
    readdir(dp);
    loc = telldir(dp);
    seekdir(dp, loc);
    printf("Current Position: %ld \n", telldir(dp));

    dent = readdir(dp);
    printf("Read: %s \n", dent->d_name);
    
    closedir(dp);
}