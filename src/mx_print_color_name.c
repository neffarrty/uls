#include "../inc/uls.h"

void mx_print_color_name(t_fileinfo file) {
    switch(file.st.st_mode & S_IFMT) {
        case S_IFSOCK:
            mx_printstr(GRN);
            break;
        case S_IFLNK:
            mx_printstr(MAG);
            break;
        case S_IFBLK:
            mx_printstr(BLU);
            break;
        case S_IFDIR:
            mx_printstr(BLU);
            break;
        case S_IFCHR:
            mx_printstr(GRN);
            break;
        case S_IFIFO:
            mx_printstr(GRN); //brown
            break;
        default:
            if(file.st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {       
                mx_printstr(RED);
            }
            break;
    }
    mx_printstr(file.name);
    mx_printstr(RESET);
}

