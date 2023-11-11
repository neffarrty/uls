#include "../inc/uls.h"

char *mx_concat_dirs(char* fst, char* scd) {
    char *res = mx_strnew(mx_strlen(fst) + mx_strlen(scd) + 1);
    mx_strncpy(res, fst, mx_strlen(fst));
    mx_strcat(res, "/");
    mx_strcat(res, scd);

    return res;
}

void mx_print_dir(char* name) {
    DIR* dir = NULL;
    struct s_fileinfo *files = NULL;
    struct dirent *entry = NULL;
    int size = 0;
        
    size = mx_count_dir_size(name);
    dir = mx_opendir(name);

    files = (t_fileinfo*)malloc(size * sizeof(t_fileinfo));

    for(int i = 0; (entry = readdir(dir)) != NULL; i++) {
        files[i].name = mx_strdup(entry->d_name);
        stat(entry->d_name, &files[i].stat);
    }

    mx_printstr(name);
    mx_printstr(":\n");
    for(int i = 0; i < size; i++) {
        mx_printstr(files[i].name);
        mx_printchar(' ');
    }
    // printf("size = %d\n", size);
    // mx_print_in_cols(files, size, 4);
    mx_printchar('\n');
    mx_printchar('\n');

    for(int i = 0; i < size; i++) {
        if(S_ISDIR(files[i].stat.st_mode) && mx_strcmp(files[i].name, "..") != 0 && mx_strcmp(files[i].name, ".") != 0) {
            char *new_name = mx_concat_dirs(name, files[i].name);
            mx_print_dir(new_name);
        }
    }

    // for(int i = 0; i < size; i++) {
    //     free(files[i].name);
    // }
    // free(files);

    closedir(dir);
}

