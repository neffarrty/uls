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
            if(!(flags & FLAG_A) || !(flags & FLAG_A)) {
                continue;
            }
        }
        char *path = mx_concat_dirs(name, entry->d_name);
        files[i].name = mx_strdup(entry->d_name);
        stat(path, &files[i].st);
        i++;
        free(path);
    }
    mx_sort_files(files, size, flags);

    mx_printstr(name);
    mx_printstr(":\n");
    mx_print_in_cols(files, size);

    if(flags & FLAG_R) {
        for(int i = 0; i < size; i++) {
            if(mx_strcmp(files[i].name, ".") != 0 && mx_strcmp(files[i].name, "..") != 0) {
                char *new_name = mx_concat_dirs(name, files[i].name);
                struct stat st;
                stat(new_name, &st);
                if(S_ISDIR(st.st_mode) && mx_dir_size(new_name, flags) != 0) {
                    mx_printchar('\n');
                    mx_print_dir(new_name, flags);
                }

                free(new_name);
            }
        }
    }

    for(int i = 0; i < size; i++) {
        free(files[i].name);
    }
    free(files);

    closedir(dir);
}

