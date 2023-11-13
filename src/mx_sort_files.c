#include "../inc/uls.h"

void mx_sort_files(t_fileinfo arr[], int size, int flags) {
    bool (*cmp)(t_fileinfo, t_fileinfo) = NULL;

	if(flags & FLAG_r) {
		cmp = mx_cmp_rname;
	}
	else if(flags & FLAG_t) {
		cmp = mx_cmp_mtime;
	}
	else if(flags & FLAG_u) {
		cmp = mx_cmp_atime;
	}
	else if(flags & FLAG_c) {
		cmp = mx_cmp_ctime;
	}
	else {
		cmp = mx_cmp_aname;
	}

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

