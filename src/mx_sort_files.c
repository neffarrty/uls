#include "../inc/uls.h"

void mx_sort_files(t_fileinfo files[], int size, int flags) {
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
	else if(flags & FLAG_S) {
		cmp = mx_cmp_size;
	}
	else {
		cmp = mx_cmp_name;
	}

    int isSorted = 0;
	while(!isSorted) {
		isSorted = 1;

		for(int i = 0; i < size - 1; i++) {
			if(cmp(files[i], files[i + 1])) {
				isSorted = 0;
				
				t_fileinfo buff = files[i];
				files[i] = files[i + 1];
				files[i + 1] = buff;
			}
		}
	}
	// isSorted = 0;
	// while(!isSorted) {
	// 	isSorted = 1;

	// 	for(int i = 0; i < size - 1; i++) {
	// 		if(mx_cmp_name(files[i], files[i + 1])) {
	// 			isSorted = 0;
				
	// 			t_fileinfo buff = files[i];
	// 			files[i] = files[i + 1];
	// 			files[i + 1] = buff;
	// 		}
	// 	}
	// }
}

