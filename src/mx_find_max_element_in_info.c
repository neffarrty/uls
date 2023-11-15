#include "../inc/uls.h"

int mx_find_max_element_in_info(char*** info, int iterator, int size){
        int max = mx_strlen(info[0][iterator]);
        for(int i = 0; i < size ; i++){
            if (mx_strlen(info[i][iterator]) > max ){
                max = mx_strlen(info[i][iterator]);
            }
        }
    return max;
}


