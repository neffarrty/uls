#include "../inc/uls.h"

void mx_long_output(t_fileinfo files[], int size) {
    blkcnt_t total = 0;

    char*** info = (char***)malloc(size * sizeof(char**));
    for(int i = 0 ; i < size; i++) {
        info[i] = (char**)malloc(7 * sizeof(char*));
    }

    for(int i = 0; i < size; i++) {
        total += files[i].st.st_blocks;
    }

    for(int i = 0 ; i < size; i++) {
       //info[i][0] = "-rwxrwxrwx";
        info[i][0] = mx_get_permissions(files[i]);
        //info[i][0] = get_acl(files[i].name);
        info[i][1] = mx_itoa(files[i].st.st_nlink);
        struct passwd* pwd = getpwuid(files[i].st.st_uid);
        struct group*  grp = getgrgid(files[i].st.st_gid);
        info[i][2] = mx_strdup(pwd->pw_name);
        info[i][3] = mx_strdup(grp->gr_name);
        info[i][4] = mx_itoa(files[i].st.st_size);
        info[i][5] = mx_strndup(&ctime(&files[i].st.st_mtime)[4], 12);
        info[i][6] = mx_strdup(files[i].name);
    }

    printf("total %lld\n", total);

    for(int i = 0; i < size; i++) {
        mx_printstr(info[i][0]);
        mx_printchar(' ');
        mx_printstr(info[i][1]);
        mx_printchar(' ');
        mx_printstr(info[i][2]);
        mx_printchar(' ');
        mx_printstr(info[i][3]);
        mx_printchar(' ');
        mx_printstr(info[i][4]);
        mx_printchar(' ');
        mx_printstr(info[i][5]);
        mx_printchar(' ');
        mx_printstr(info[i][6]);
        if((files[i].st.st_mode & S_IFMT) == S_IFLNK){
            mx_print_link(files[i].name);
        }
        mx_printchar('\n');
    }

    // for(int i = 0 ; i < size; i++) {
    //     for(int j = 0 ; j < 7; j++) {
    //         free(info[i][j]);
    //     }
    //     free(info[i]);
    // }
    // free(info);
}

