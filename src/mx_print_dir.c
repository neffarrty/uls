#include "../inc/uls.h"

bool  mx_cmp_atime(t_fileinfo a, t_fileinfo b) {
    return a.stat.st_atime > b.stat.st_atime;
}

bool mx_cmp_ctime(t_fileinfo a, t_fileinfo b) {
    return a.stat.st_ctime > b.stat.st_ctime;
}

bool mx_cmp_mtime(t_fileinfo a, t_fileinfo b) {
    return a.stat.st_mtime > b.stat.st_mtime;
}

bool mx_cmp_name(t_fileinfo a, t_fileinfo b) {
    return mx_strcmp(a.name, b.name) > 0;
}

void mx_sort(t_fileinfo arr[], int size) {
    bool (*cmp)(t_fileinfo, t_fileinfo) = mx_cmp_name;

    int isSorted = 0;
	while(!isSorted) {
		isSorted = 1;

		for(int i = 0; i < size - 1; i++) {
			if(cmp(arr[i], arr[i + 1])) {
				isSorted = 0;
				
				t_fileinfo buff = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buff;
			}
		}
	}
}

char *mx_concat_dirs(char* fst, char* scd) {
    char *res = mx_strnew(mx_strlen(fst) + mx_strlen(scd) + 1);
    mx_strncpy(res, fst, mx_strlen(fst));
    mx_strcat(res, "/");
    mx_strcat(res, scd);

    return res;
}

void mx_print_dir(char* name) {
    DIR* dir = NULL;
    struct s_fileinfo *files = NULL;
    struct dirent *entry = NULL;
    int size = 0;
        
    size = mx_count_dir_size(name);
    dir = mx_opendir(name);

    files = (t_fileinfo*)malloc(size * sizeof(t_fileinfo));

    for(int i = 0; (entry = readdir(dir)) != NULL; i++) {
        files[i].name = mx_strdup(entry->d_name);
        stat(entry->d_name, &files[i].stat);
    }
    mx_sort(files, size);

    mx_printstr(name);
    mx_printstr(":\n");
    for(int i = 0; i < size; i++) {
        mx_printstr(files[i].name);
        mx_printchar(' ');
    }
    mx_printchar('\n');
    mx_printchar('\n');

    for(int i = 0; i < size; i++) {
        if(mx_strcmp(files[i].name, "..") != 0 && mx_strcmp(files[i].name, ".") != 0) {
            char *new_name = mx_concat_dirs(name, files[i].name);
            struct stat st;
            stat(new_name, &st);
            if(S_ISDIR(st.st_mode)) {
                mx_print_dir(new_name);
            }
        }
    }

    // for(int i = 0; i < size; i++) {
    //     free(files[i].name);
    // }
    // free(files);

    closedir(dir);
}

