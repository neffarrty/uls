#include "../inc/uls.h"

int mx_max_name_length(t_fileinfo arr[], int size) {
    int max = mx_strlen(arr[0].name);
    
    for(int i = 1; i < size; i++) {
        int length = mx_strlen(arr[i].name);
        if(length > max) {
            max = length;
        }
    }

    return max;
}

