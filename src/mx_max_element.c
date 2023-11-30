#include "uls.h"

int mx_max_element(char*** info, int size, int col) {
    int max = mx_strlen(info[0][col]);
    
    for(int i = 0; i < size ; i++){
        int current = mx_strlen(info[i][col]);
        if(current > max ){
            max = current;
        }
    }

    return max;
}


