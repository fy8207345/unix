#include "apue.h"
#include "sys/wait.h"

int main(void ){
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% : %ld", (long )getpid());
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if(strlen(buf) == 1){
            continue;
        }
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = 0;
        }
        pid = fork(); //fork完会产生一个子进程，从下一条指令开始执行
        if(pid < 0){
            err_sys("fork error");
        }else if(pid == 0) { //子进程会进入这个分支
            printf("child process get executed : %d\n", pid);
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute : %s", buf);
            exit(127);
        }else{
            printf("parent process get executed : %d\n", pid);
        }

        printf("wait child process: %d", pid);
        if((pid = waitpid(pid, &status, 0)) < 0){
            err_ret("waitpid error");
        }
        printf("%% : %ld", (long )getpid());
    }
    exit(0);
}