#include<stdio.h>
#include<err.h>
#include<string.h>
#include<stdlib.h>

/* opendir, readdir */
#include<sys/types.h>
#include<dirent.h>

/* stat */
#include<sys/stat.h>
#include<unistd.h>

/* colors */
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"
