#ifndef LIBFS_H
#define LIBFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILES 100
#define MAX_FILENAME 50
#define MAX_FILE_SIZE 1024

// File system structures
typedef struct {
    char filename[MAX_FILENAME];
    int size;
    int is_open;
} FileEntry;

// Function prototypes
// Build your code

#endif // LIBFS_H