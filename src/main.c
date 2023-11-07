#include "uls.h"
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/acl.h>

DIR* mx_opendir(const char* name) {
    DIR* dir = opendir(name);

    if(dir == NULL) {
        mx_printerr("uls: ");
        mx_printerr(name);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return dir;
}

int mx_count_dir_size(DIR* dir) {
    DIR* tmp = dir;
    struct dirent *entry = NULL;
    int size = 0;

    while((entry = readdir(tmp)) != NULL) {
        size++;
    }

    return size;
}

int main(int argc, char *argv[]) {  
    if(argc == 1) {
        DIR* current_dir = NULL;
        struct dirent *drent = NULL;
        current_dir = opendir(".");
        // int size = mx_count_dir_size(current_dir);
        // printf("%d\n", size);

        if(current_dir == NULL) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }

        while((drent = readdir(current_dir)) != NULL) {
            mx_printstr(drent->d_name);
            acl_t acl = acl_get_file(drent->d_name, ACL_TYPE_ACCESS);
            ssize_t size = 0;
            char* acl_text = acl_to_text(acl, &size);
            printf("%s\n", acl_text);
            mx_printchar(' ');
        }
        mx_printchar('\n');
        closedir(current_dir);
    }
    else if(argc == 2) {
        DIR* current_dir = NULL;
        struct dirent *drent = NULL;
        current_dir = opendir(argv[1]);
        // int size = mx_count_dir_size(current_dir);
        // printf("%d\n", size);

        if(current_dir == NULL) {
            mx_printerr("uls: ");
            mx_printerr(argv[1]);
            mx_printerr(": ");
            mx_printerr(strerror(errno));
            exit(EXIT_FAILURE);
        }


        while((drent = readdir(current_dir)) != NULL) {
            mx_printstr(drent->d_name);
            acl_t acl = acl_get_file(drent->d_name, ACL_TYPE_ACCESS);
            ssize_t size = 0;
            char* acl_text = acl_to_text(acl, &size);
            printf("%s\n", acl_text);
            mx_printchar(' ');
        }
        mx_printchar('\n');
        closedir(current_dir);
    }

    return EXIT_SUCCESS;
}

