#include "apue.h"

int main(void ){
    int fd = dup(STDIN_FILENO);
    printf("new fd: %d", fd);
    char buf[MAXLINE];
    int len;
    while ((len = read(fd, buf, MAXLINE)) > 0){
        printf("read data: %s", buf);
    }
    exit(0);
}