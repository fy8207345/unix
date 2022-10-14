#include "fcntl.h"

int main(void ){
//    int fd = open("newFileTest", O_DIRECTORY | O_CREAT | O_RDWR);
    int fd2 = creat("newDirectory", O_DIRECTORY);
}