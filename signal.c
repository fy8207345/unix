#include "apue.h"
#include "sys/wait.h"

static void sig_int(int); // our signal-catching function

int main(void ){
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR){
        err_sys("register signal handler error for SIGINT");
    }

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = 0;
        }
        pid = fork();
        if(pid < 0){
            err_sys("fork error");
        }else if(pid == 0){
            execlp(buf, buf, NULL);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }else{

        }

        if((pid = waitpid(pid, &status, 0)) < 0){
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}

void sig_int(int signo){
    printf("interrupt\n%% ");
}