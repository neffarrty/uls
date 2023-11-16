#include "../inc/uls.h"

void mx_print_color_name(t_fileinfo file) {
    switch(file.st.st_mode & S_IFMT) {
        case S_IFSOCK:
            mx_printstr(SOC_COLOR);
            break;
        case S_IFLNK:
            mx_printstr(LNK_COLOR);
            break;
        case S_IFBLK:
            mx_printstr(BLK_COLOR);
            break;
        case S_IFDIR:
            mx_printstr(DIR_COLOR);
            break;
        case S_IFCHR:
            mx_printstr(CHR_COLOR);
            break;
        case S_IFIFO:
            mx_printstr(PIP_COLOR);
            break;
        default:
            if(file.st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {       
                mx_printstr(EXE_COLOR);
            }
            break;
    }
    mx_printstr(file.name);
    mx_printstr(NON_COLOR);
}

