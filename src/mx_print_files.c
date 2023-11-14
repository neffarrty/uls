#include "../inc/uls.h"

void mx_print_files(t_fileinfo arr[], int size) {
    int max = mx_max_name_length(arr, size);
    struct winsize ws;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    int cols = 0;
    if(ws.ws_col  % (max + 2) == 0){
        cols = ws.ws_col / (max + 8);
    }
    else {
        cols = ws.ws_col / (max + 2);
    }

    int rows = size / cols;
    if(size % cols != 0) {
        rows += 1;
    }
    if(!isatty(STDOUT_FILENO)){
       for(int i = 0; i < size; i++){
            mx_printstr(arr[i].name);
            mx_printchar('\n');
       }
    }
    else {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int index = i + j * rows;
                if(index < size ) {
                    mx_printstr(arr[index].name);
                    mx_printnchar(' ', max - mx_strlen(arr[index].name));
                }
                if(j != cols - 1) {
                    mx_printchar('\t');
                }
            }
            mx_printchar('\n');
        }
    }
}

