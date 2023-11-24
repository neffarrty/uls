#include "../inc/uls.h"

void mx_lstat(const char* pathname,struct stat* buf){
    int res = lstat(pathname,buf);
    
    if (res == -1){
        mx_printerr("uls: ");
        mx_printerr(pathname);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        exit(EXIT_FAILURE);
    }
}


