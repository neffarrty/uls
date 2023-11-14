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
#include <limits.h>

typedef struct s_fileinfo {
    char *name;
    struct stat st;
}              t_fileinfo;

DIR* mx_opendir(const char* name);

int mx_dir_size(char* path, int flags);

int mx_max_name_length(t_fileinfo arr[], int size);

void mx_printnchar(char c, int n);

void mx_print_dir(char* name, int flags);

void mx_print_files(t_fileinfo arr[], int size, int flags);

void mx_sort_files(t_fileinfo arr[], int size, int flags);

bool mx_cmp_atime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_ctime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_mtime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_aname(t_fileinfo a, t_fileinfo b);

bool mx_cmp_rname(t_fileinfo a, t_fileinfo b);

void mx_long_output(t_fileinfo files[], int size);

char *mx_concat_dirs(char* fst, char* scd);

#endif

