#include "../inc/uls.h"

void mx_print_dir(char* name, int flags) {
    DIR* dir = NULL;
    struct s_fileinfo *files = NULL;
    struct dirent *entry = NULL;
    int size = 0;

    size = mx_dir_size(name, flags);
    dir = mx_opendir(name);

    files = (t_fileinfo*)malloc(size * sizeof(t_fileinfo));

    int i = 0;
    while( (entry = readdir(dir)) != NULL ) {
        if(mx_strcmp(entry->d_name, ".") == 0 || mx_strcmp(entry->d_name, "..") == 0) {
            if(!(flags & FLAG_a)) {
                continue;
            }
        } 
        else if(entry->d_name[0] == '.') {
            if(!(flags & (FLAG_a | FLAG_A))) {
                continue;
            }
        }
        files[i].path = mx_concat_dirs(name, entry->d_name);

        files[i].name = mx_strdup(entry->d_name);
        lstat(files[i].path, &files[i].st);
        i++;
    }
    mx_sort_files(files, size, flags);
    
    if(mx_strcmp(name, ".") != 0){
        mx_printstr(name);
        mx_printstr(":\n");
    }
    mx_print_files(files, size, flags);

    if(flags & FLAG_R) {
        for(int i = 0; i < size; i++) {
            if(mx_strcmp(files[i].name, ".") != 0 && mx_strcmp(files[i].name, "..") != 0) {
                char *path = mx_concat_dirs(name, files[i].name);
                struct stat st;

                lstat(path, &st);
                if(S_ISDIR(st.st_mode) && mx_dir_size(path, flags) != 0) {
                    mx_printchar('\n');
                    mx_print_dir(path, flags);
                }

                free(path);
            }
        }
    }

    for(int i = 0; i < size; i++) {
        free(files[i].name);
        free(files[i].path);
    }
    free(files);

    closedir(dir);
}

