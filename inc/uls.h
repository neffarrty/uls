#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include "flags.h"
#include <string.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

typedef struct s_fileinfo {
    char *name;
    struct stat stat;
}              t_fileinfo;

DIR* mx_opendir(const char* name);

int mx_count_dir_size(char* path);

int mx_max_name_length(t_fileinfo arr[], int size);

void mx_printnchar(char c, int n);

void mx_print_dir(char* name);

void mx_print_in_cols(t_fileinfo arr[], int size, int cols);

#endif

