#include "../inc/uls.h"

void mx_print_in_cols(t_fileinfo arr[], int size) {
    int max = mx_max_name_length(arr, size);
    struct winsize ws;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    int cols = ws.ws_col / (max + 2);
    // if(size <= cols) {
    //     for(int i = 0; i < size; i++) {
    //         mx_printstr(arr[i].name);
    //         mx_printnchar(' ', tab + (tab - mx_strlen(arr[i].name)));
    //     }
    //     mx_printchar('\n');
    // } 
    // else {
    int rows = size / cols;
    if(size % cols != 0) {
        rows += 1;
    }
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int index = i + j * rows;
            if(index < size) {
                mx_printstr(arr[index].name);
                mx_printnchar(' ', max - mx_strlen(arr[index].name));
            }
            if(j != cols - 1) {
                mx_printnchar(' ', 2);
            }
        }
        mx_printchar('\n');
    }
    // }
}

