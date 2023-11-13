#include "../inc/uls.h"

void mx_long_output(t_fileinfo files[], int size) {
    blkcnt_t total = 0;

    for(int i = 0; i < size; i++) {
        blkcnt_t blocks = files[i].st.st_size / files[i].st.st_blksize;
        if(blocks == 0) blocks++;
        printf("%s: %ld - %ld\n", files[i].name, files[i].st.st_blocks, files[i].st.st_blksize);
        total += files[i].st.st_blocks;
    }

    printf("total: %ld\n", total);
}

