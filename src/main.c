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
        DIR* dir = NULL;
        struct dirent *drent = NULL;
        dir = mx_opendir(".");

        while((drent = readdir(dir)) != NULL) {
            mx_printstr(drent->d_name);
            acl_t acl = acl_get_file(drent->d_name, ACL_TYPE_ACCESS);
            if(acl == NULL) {
                mx_printerr("uls: ");
                mx_printerr(drent->d_name);
                mx_printerr(": ");
                mx_printerr(strerror(errno));
                exit(EXIT_FAILURE);
            }

            ssize_t size = 0;
            char* acl_text = acl_to_text(acl, &size);
            if(acl_text == NULL) {
                mx_printerr("uls: ");
                mx_printerr(drent->d_name);
                mx_printerr(": ");
                mx_printerr(strerror(errno));
                exit(EXIT_FAILURE);
            }
            printf(" %s\n", acl_text);
            mx_printchar(' ');
        }
        mx_printchar('\n');
        closedir(dir);
    }
    
    return EXIT_SUCCESS;
}

