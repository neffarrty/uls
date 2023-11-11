#include "../inc/uls.h"

void mx_print_in_cols(t_fileinfo arr[], int size, int cols) {
    int tab = mx_max_name_length(arr, size);
    
    if(size <= cols) {
        for(int i = 0; i < size; i++) {
            mx_printstr(arr[i].name);
            mx_printnchar(' ', tab + (tab - mx_strlen(arr[i].name)));
        }
        mx_printchar('\n');
    } 
    else {
        int n = size / cols;
        printf("n of rows = %d\n", n);
        if(size % cols != 0) {
            n += 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < cols; j++) {
                int index = i + j * cols;
                if(index < size) {
                    mx_printstr(arr[index].name);
                
                    mx_printnchar(' ', tab + (tab - mx_strlen(arr[index].name)));
                }
            }
            mx_printchar('\n');
        }
    }
}

