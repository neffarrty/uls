#include "uls.h"

char *mx_get_time_str(time_t time) {
    return mx_strndup(&ctime(&time)[4], 12);
}

int mx_max_length(char **arr, int size) {
    int max = mx_strlen(arr[0]);
    
    for(int i = 1; i < size; i++) {
        int length = mx_strlen(arr[i]);
        if(length > max) {
            max = length;
        }
    }

    return max;
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
    unsigned short flags = 0;
    int num_of_files = mx_check_flags(argc, argv, &flags);
    
    if(num_of_files == 0 && !(flags & 0xFFFF)) {
        DIR* dir = NULL;
        char **names = NULL;
        struct dirent *entry = NULL;
        int size = 0;
        
        size = mx_count_dir_size(".");
        dir = mx_opendir(".");

        struct winsize ws;
        int sizeof_output = 0;
        int num_of_files = 0;
        ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
        printf("window width: %d\n", ws.ws_col);

        names = (char**)malloc(size * sizeof(char*));

        for(int i = 0; (entry = readdir(dir)) != NULL; i++) {
            names[i] = mx_strdup(entry->d_name);
        }
        mx_bubble_sort(names, size);
        
        // for(int i = 0; i < size; i++) {
        //     if(names[i][0] != '.') {
        //         sizeof_output += mx_strlen(names[i]);
        //         num_of_files++;
        //     }
        // }
        // int tab = sizeof_output / (num_of_files - 1);
        // printf("%d / %d = %d\n", sizeof_output, num_of_files - 1, tab);

        int tab = mx_max_length(names, size);

        for(int i = 0; i < size; i++) {
            if(names[i][0] != '.') {
                mx_printstr(names[i]);
                if(mx_strlen(names[i]) < 8) {
                    for(int j = 0; j < tab - mx_strlen(names[i]); j++) {
                        mx_printstr(" ");
                    }
                }
                for(int j = 0; j < tab; j++) {
                        mx_printstr(" ");
                }
            }
        }
        mx_printstr("\n");

        closedir(dir);
    }
    
    return EXIT_SUCCESS;
}


