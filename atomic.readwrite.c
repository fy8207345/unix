#include "apue.h"

int main(void ){
    char buf[MAXLINE];
    ssize_t n;
    while ( (n  = read(STDIN_FILENO, buf, MAXLINE)) > 0){
        if(pwrite(STDOUT_FILENO, buf, n, 0) < 0){
            err_sys("error write output");
        }
    }
    exit(0);
}