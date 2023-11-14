#include "../inc/uls.h"

void mx_long_output(t_fileinfo files[], int size) {
    blkcnt_t total = 0;

    for(int i = 0; i < size; i++) {
        total += files[i].st.st_blocks;
    }

    printf("total %ld\n", total);

    for(int i = 0; i < size; i++) {
        mx_printstr(files[i].name);
        mx_printchar('\n');
    }
}

