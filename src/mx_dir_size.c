#include "uls.h"

int mx_dir_size(char* path, unsigned short flags) {
    int size = 0;
    struct dirent *entry = NULL;
    DIR* dir = opendir(path);
    if(dir == NULL){
        return -1;
    }

    while((entry = readdir(dir)) != NULL) {
        if(mx_strcmp(entry->d_name, ".") == 0 || mx_strcmp(entry->d_name, "..") == 0) {
            if(!(flags & FLAG_a)) {
                continue;
            }
        } else if(entry->d_name[0] == '.') {
            if(!(flags & (FLAG_a | FLAG_A))) {
                continue;
            }
        }
        size++;
    }
    closedir(dir);

    return size;
}

