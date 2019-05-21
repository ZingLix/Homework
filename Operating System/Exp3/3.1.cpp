#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
        int pid, pipeId[2], buff;
        pipe(pipeId);
        if((pid=fork())!=0){
                write(pipeId[1], &pid, sizeof(int));
                exit(0);
        }
        read(pipeId[0], &buff, sizeof(int));
        printf("child pid: %d\n", buff);
        return 0;
}