#ifndef ULS_H
#define ULS_H

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

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
#include <grp.h>
#include <pwd.h>
#include <sys/xattr.h>

typedef struct s_fileinfo {
    char *name;
    struct stat st;
    char *path;
}              t_fileinfo;

DIR* mx_opendir(const char* name);

int mx_dir_size(char* path, int flags);

int mx_max_name_length(t_fileinfo arr[], int size);

void mx_printnchar(char c, int n);

void mx_print_dir(char* name, int flags);

void mx_print_files(t_fileinfo files[], int size, int flags);

void mx_sort_files(t_fileinfo files[], int size, int flags);

bool mx_cmp_atime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_ctime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_mtime(t_fileinfo a, t_fileinfo b);

bool mx_cmp_rname(t_fileinfo a, t_fileinfo b);

bool mx_cmp_name(t_fileinfo a, t_fileinfo b);

bool mx_cmp_size(t_fileinfo a, t_fileinfo b);

void mx_long_output(t_fileinfo files[], int size);

char *mx_concat_dirs(char* fst, char* scd);

int mx_count_cols(int max);

void mx_print_link(const char *path);

char mx_get_file_type(mode_t mode);

char* mx_get_permissions(t_fileinfo file);

int mx_max_element(char*** info, int size, int col);

void mx_print_color_name(t_fileinfo file);

#endif

