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

DIR* mx_opendir(const char* name);
int mx_count_dir_size(char* path);

#endif

