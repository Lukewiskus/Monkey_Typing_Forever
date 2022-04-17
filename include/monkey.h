#ifndef MONKEY_H
#define MONKEY_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 


#define HASH_TABLE_SIZE 300000
#define MAXVALUESZ 70

struct node {
    char *value;           
    struct node *p_left;
    struct node *p_right;
};

typedef int (*Compare)(const char *, const char *);

struct node *p_root = NULL;

int numWordsMade = 0;
#endif