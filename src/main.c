#include "../inc/uls.h"

int main(int argc, char *argv[]) {  
    unsigned short flags = 0;
    int count_files = mx_check_flags(argc, argv, &flags);
    
    if(count_files > 0) {
        int files_size = 0;
        int dirs_size = 0;

        for(int i = 1; i < argc; i++) {
            if(argv[i][0] != '-') {
                struct stat buf;
                int res = lstat(argv[i], &buf);
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
                mx_lstat(argv[k], &buf);
            
                if((buf.st_mode & S_IFMT) == S_IFDIR) {
                    dirs[i].name = mx_strdup(argv[k]);
                    dirs[i].path = mx_strdup(argv[k]);
                    lstat(argv[k], &dirs[i].st);
                    i++;
                }
                else {
                    files[j].name = mx_strdup(argv[k]);
                    files[j].path = mx_strdup(argv[k]);
                    lstat(argv[k], &files[j].st);
                    j++;
                }
            }
        }

        mx_sort_files(files, files_size, flags);
        mx_sort_files(dirs, dirs_size, flags);
        if(files_size > 0){
            mx_print_files(files, files_size, flags, false);
        }
        if(dirs_size == 1 && mx_dir_size(dirs[0].path,flags) == 0){
            return EXIT_SUCCESS;
        }
        for(int i = 0; i < dirs_size; i++) {
            if( i != 0 || files_size > 0){
                mx_printchar('\n');
            }
            mx_print_dir(dirs[i].name, flags);
        }
    }
    else {
        mx_print_dir(".", flags);
    }
    
    return EXIT_SUCCESS;
}


