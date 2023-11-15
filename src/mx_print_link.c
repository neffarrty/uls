#include "../inc/uls.h"

void mx_print_link(const char *name){
    char buff[PATH_MAX];
    ssize_t len = readlink(name,buff,sizeof(buff)-1);
    if(len != -1){
        mx_printstr(" -> ");
        mx_printstr(buff);
    }
}


