#include "apue.h"
#include "fcntl.h"
#include "errno.h"

int main(void ){
    int fd;
    const char *path = "./createTest";
    if((fd = open(path, O_WRONLY)) < 0){
        if(errno == ENOENT){
            if((fd = creat(path, O_RDWR)) < 0){
                err_sys("create error");
            }
        }else{
            err_sys("open error");
        }
    }
    dup2(fd, 0);
    exit(0);
}