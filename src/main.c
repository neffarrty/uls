#include "uls.h"
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/acl.h>

#include <sys/ioctl.h>

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

int mx_count_dir_size(char* path) {
    DIR* dir = NULL;
    struct dirent *entry = NULL;
    int size = 0;

    dir = mx_opendir(path);
    while((entry = readdir(dir)) != NULL) {
        size++;
    }
    closedir(dir);

    return size;
}

void mx_sort_entries(struct dirent **entries, int size) {
	int isSorted = 0;
	
	while(!isSorted) {
		isSorted = 1;
		for(int i = 0; i < size - 1; i++) {
			if(mx_strcmp(entries[i]->d_name, entries[i + 1]->d_name) > 0) {
				isSorted = 0;
				
				struct dirent* tmp = entries[i];
				entries[i] = entries[i + 1];
				entries[i + 1] = tmp;
			}
		}
	}
}

int main(int argc, char *argv[]) {  
    if(argc == 1) {
        DIR* dir = NULL;
        struct dirent **entries = NULL;
        int size = 0;

        size = mx_count_dir_size(".");
        dir = mx_opendir(".");

        entries = (struct dirent**)malloc(size * sizeof(struct dirent*));

        struct winsize ws;
        int io_res = ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
        printf("%dx%d\n", ws.ws_col, ws.ws_row);

        for(int i = 0; i < size; i++) {
            // acl_t acl = acl_get_file(drent->d_name, ACL_TYPE_ACCESS);
            // if(acl == NULL) {
            //     mx_printerr("uls: ");
            //     mx_printerr(drent->d_name);
            //     mx_printerr(": ");
            //     mx_printerr(strerror(errno));
            //     exit(EXIT_FAILURE);
            // }
            entries[i] = readdir(dir);

            // ssize_t size = 0;
            // char* acl_text = acl_to_text(acl, &size);
            // if(acl_text == NULL) {
            //     mx_printerr("uls: ");
            //     mx_printerr(drent->d_name);
            //     mx_printerr(": ");
            //     mx_printerr(strerror(errno));
            //     exit(EXIT_FAILURE);
            // }
            // printf(" %s\n", acl_text);
        }
        mx_sort_entries(entries, size);
        
        for(int i = 0; i < size; i++) {
            mx_printstr(entries[i]->d_name);
            mx_printstr(" ");
        }
        mx_printstr("\n");

        closedir(dir);
    }

    mx_check_flags(argc, argv, 0);
    
    return EXIT_SUCCESS;
}

