#include "apue.h"

int main(void ){
    int pfd[2];

    if(pipe(pfd) == -1){
        printf("failed to create a pipe!");
    }

    switch (fork()) {
        case -1:
            printf("failed to create a process");
        case 0: //child process
            if(close(pfd[1]) == -1){
                _exit(1);
            }
            char read_buf[MAXLINE];
            int readlen = read(pfd[0], read_buf, MAXLINE);
            printf("child process read: %s\n", read_buf);
            _exit(0);
        default: //parent process
            if(close(pfd[0]) == -1){
                exit(1);
            }
            char write_buf[] = "hello child!";
            int writen = write(pfd[1], write_buf, strlen(write_buf));
    }
}