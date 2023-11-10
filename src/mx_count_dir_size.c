#include "../inc/uls.h"

int mx_count_dir_size(char* path) {
    DIR* dir = NULL;
    struct dirent *entry = NULL;
    int size = 0;

    dir = mx_opendir(path);
    while((entry = readdir(dir)) != NULL) {
        size++;
    }
    closedir(dir);

    return size;
}

