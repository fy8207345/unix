#include "apue.h"
#include "fcntl.h"

#define BUFSIZE 1024

int main(void ){
    int n;
    char buf[BUFSIZE];
    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0){
        if(write(STDOUT_FILENO, buf, n) != n){
            err_sys("write error");
        }
    }
    if(n < 0){
        err_sys("error read");
    }
    exit(0);
}