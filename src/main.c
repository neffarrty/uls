#include "../inc/uls.h"

int main(int argc, char *argv[]) {  
    unsigned short flags = 0;
    mx_check_flags(argc, argv, &flags);
    
    if(argc == 1) {
        DIR* dir = NULL;
        char **names = NULL;
        struct dirent *entry = NULL;
        int size = 0;
        
        size = mx_count_dir_size(".");
        dir = mx_opendir(".");

        struct winsize ws;
        ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);

        names = (char**)malloc(size * sizeof(char*));

        for(int i = 0; (entry = readdir(dir)) != NULL; i++) {
            names[i] = mx_strdup(entry->d_name);
        }
        mx_bubble_sort(names, size);
        
        // for(int i = 0; i < size; i++) {
        //     if(names[i][0] != '.') {
        //         sizeof_output += mx_strlen(names[i]);
        //         num_of_files++;
        //     }
        // }
        // int tab = sizeof_output / (num_of_files - 1);
        // printf("%d / %d = %d\n", sizeof_output, num_of_files - 1, tab);

        // int tab = mx_max_name_length(names, size);

        // for(int i = 0; i < size; i++) {
        //     if(names[i][0] != '.') {
        //         mx_printstr(names[i]);
        //         mx_printnchar(' ', tab + (tab - mx_strlen(names[i])));
        //     }
        // }
        mx_printstr("\n");

        closedir(dir);
    }
    else {
        if(flags & FLAG_R) {
            mx_print_dir(".");
        }
    }

    // char *arr[8] = {
    //     "A", "B", "C",
    //     "D", "E", "F",
    //     "G", "H"
    // };
    // mx_print_in_cols(arr, 8, 3);
    
    return EXIT_SUCCESS;
}


