#include "apue.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("usage: ./a.out filename\n");
        exit(1);
    }
    int p[2];
    pipe(p);
    if(fork() == 0){
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        int readfd = dup(p[0]);
        close(p[0]);
        close(p[1]);
        char read_buf[MAXLINE];
        size_t readn = read(readfd, read_buf, MAXLINE);
        printf("child read: %s", read_buf);
        execlp("wc", "wc", read_buf, NULL);
    }else{
        write(p[1], argv[1], strlen(argv[1]));
        close(p[0]);
        close(p[1]);
    }
}