#include "apue.h"
#include "fcntl.h"
#include "errno.h"

int main(void ){
    int oldfd = STDIN_FILENO, newfd = 100, newfd2 = 1000;
    int value = dup2(oldfd, newfd);

    if(value == -1){
        err_quit("dup2 error: %s", strerror(errno));
    }

    printf("old: %d, new: %d, value: %d\n", oldfd, newfd, value);
    char buf[MAXLINE];
    int len;

    while ((len = read(newfd, buf, MAXLINE)) > 0){
        printf("%s", buf);
    }

    value = dup2(newfd, newfd2);
    if(value == -1){
        err_quit("dup2 error: %s", strerror(errno));
    }
    printf("old: %d, new: %d, value: %d\n", newfd, newfd2, value);
    while ((len = read(newfd, buf, MAXLINE)) > 0){
        printf("%s", buf);
    }

    exit(0);
}