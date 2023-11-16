#include "../inc/uls.h"

void mx_print_xattr(const char *path) {
    int len_of_atribute = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    char* xattr_list = malloc(len_of_atribute);
    ssize_t xattr = listxattr(path, xattr_list, XATTR_MAXNAMELEN, XATTR_NOFOLLOW);
    
    if(xattr > 0) {
        for(char *list = xattr_list; list < xattr_list + xattr; list += strlen(list) + 1){
            int len = getxattr(path, list, NULL, 0, 0, XATTR_NOFOLLOW);
            mx_printchar('\t'); 
            mx_printstr(list);
            mx_printchar('\t'); 
            mx_printint(len);
            mx_printchar('\n');
        }
    }
}


