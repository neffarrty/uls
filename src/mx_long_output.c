#include "../inc/uls.h"

void mx_long_output(t_fileinfo files[], int size) {
    blkcnt_t total = 0;

    for(int i = 0; i < size; i++) {
       //printf("%s: %lld - %d\n", files[i].name, files[i].st.st_blocks, files[i].st.st_blksize);
        total += files[i].st.st_blocks;
    }

    printf("total: %lld\n", total);
}

