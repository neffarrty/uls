#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <time.h>
#include "uls.h"

char *mx_get_time(time_t time) {
    return mx_strndup(&ctime(&time)[4], 12);
}

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
            entries[i] = readdir(dir);
        }
        mx_sort_entries(entries, size);
        
        for(int i = 0; i < size; i++) {
            mx_printstr(entries[i]->d_name);
            mx_printstr(" ");
        }
        mx_printstr("\n");

        closedir(dir);
    }
    else {
        unsigned short flags = 0;
        mx_check_flags(argc, argv, &flags);
        mx_printstr("options defined: ");
        (flags & 0xFFFF) ? mx_printstr("true\n") : mx_printstr("false\n");
    }
    
    return EXIT_SUCCESS;
}

