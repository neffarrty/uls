#include "../inc/uls.h"

int main(int argc, char *argv[]) {  
    unsigned short flags = 0;
    mx_check_flags(argc, argv, &flags);
    if(argc > 3) {
        int files_size = 0;
        int dirs_size = 0;

        for(int i = 1; i < argc; i++) {
            if(argv[i][0] != '-') {
                struct stat buf;
                int res = stat(argv[i], &buf);
                if(res == -1) {
                    mx_printerr("uls: ");
                    mx_printerr(argv[i]);
                    mx_printerr(": ");
                    mx_printerr(strerror(errno));
                    mx_printchar('\n');
                }
                else {
                    if(S_ISDIR(buf.st_mode)) {
                        dirs_size++;
                    }
                    else {
                        files_size++;
                    }
                }
            }
        }
        t_fileinfo *files = (t_fileinfo*)malloc(files_size * sizeof(t_fileinfo));
        t_fileinfo *dirs = (t_fileinfo*)malloc(dirs_size * sizeof(t_fileinfo));

        int i = 0;
        int j = 0;
        for(int k = 1; k < argc; k++) {
            if(argv[k][0] != '-') {
                struct stat buf;
                int res = stat(argv[k], &buf);
                if(res != -1) {
                    if(S_ISDIR(buf.st_mode)) {
                        dirs[i].name = mx_strdup(argv[k]);
                        stat(argv[k], &dirs[i].st);
                        i++;
                    }
                    else {
                        files[j].name = mx_strdup(argv[k]);
                        stat(argv[k], &files[j].st);
                        j++;
                    }
                }
            }
        }
        mx_sort_files(files, files_size, flags);
        mx_sort_files(dirs, dirs_size, flags);

        mx_print_files(files, files_size);

        for(int i = 0; i < dirs_size; i++) {
            mx_printchar('\n');
            mx_print_dir(dirs[i].name, flags);
        }
    }
    else {
        mx_print_dir(".", flags);
    }
    
    return EXIT_SUCCESS;
}


