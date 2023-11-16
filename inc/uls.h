#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include "flags.h"
#include "color.h"

#include <string.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <limits.h>
#include <grp.h>
#include <pwd.h>
#include <sys/xattr.h>

typedef struct s_fileinfo {
    char *name;
    struct stat st;
    char *path;
}              t_fileinfo;

DIR* mx_opendir(const char* name);

int mx_dir_size(char* path, unsigned short flags);

int mx_max_name_length(t_fileinfo arr[], int size);

void mx_printnchar(char c, int n);

void mx_print_dir(char* name, unsigned short flags);

void mx_print_files(t_fileinfo files[], int size, unsigned short flags);

void mx_sort_files(t_fileinfo files[], int size, unsigned short flags);

bool mx_cmp_atime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_ctime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_mtime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_rname(t_fileinfo a, t_fileinfo b);

bool mx_cmp_name(t_fileinfo a, t_fileinfo b);

bool mx_cmp_size(t_fileinfo a, t_fileinfo b);

void mx_long_output(t_fileinfo files[], int size, unsigned short flags);

char *mx_concat_dirs(char* fst, char* scd);

int mx_count_cols(int max);

void mx_print_link(const char *path);

char mx_get_file_type(mode_t mode);

char* mx_get_permissions(t_fileinfo file);

int mx_max_element(char*** info, int size, int col);

void mx_print_xattr(const char *path);

#endif

