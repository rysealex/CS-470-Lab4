// Alex Ryse - CS470 Lab4

#include "alex_libFS.h"

// Global variables
FileEntry file_table[MAX_FILES];  // File table to track files
int file_count = 0;               // Number of files in the system

// Create a new file
int fileCreate(const char *filename) {

    // check if the file already exists
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].filename, filename) == 0) {
            printf("Error: File '%s' already exists.\n", filename);
            return -1;
        }
    }

    // create the file if not already exists
    FILE *fptr = fopen(filename, "w"); // open new file pointer in write mode
    // error checking if file pointer failed
    if (!fptr) {
        printf("Error: Failed to create file '%s'.\n", filename);
        return -1;
    }
    fclose(fptr); // close the file pointer after

    // add new file to the file table and set size and is open parameters
    strcpy(file_table[file_count].filename, filename);
    file_table[file_count].size = 0;
    file_table[file_count].is_open = 0; // 0 means file is closed, 1 means file is open
    file_count++;

    printf("File: '%s' created successfully.\n", filename);

    return 0;
}

// Open a file
int fileOpen(const char *filename) {

    // check if file exists and if is already open
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].filename, filename) == 0) {
            if (file_table[i].is_open == 1) {
                printf("Error: File '%s' is already open.\n", filename);
                return -1;
            }
            // if file not open, then set is open to open
            file_table[i].is_open = 1;
            printf("File: '%s' opened successfully.\n", filename);
            return i; // return the index of the open file
        }
    }

    // display error message if file is not found
    printf("Error: File '%s' not found.\n", filename);
    
    return -1;
}

// Write data to a file
int fileWrite(int file_index, const char *data) {

    // check if file is currently opened
    if (file_table[file_index].is_open == 0) {
        printf("Error: file '%s' is not open.\n", file_table[file_index].filename);
        return -1;
    }

    // get the size of the data to be written
    int data_size = strlen(data);

    // write the data to the file
    FILE *fptr = fopen(file_table[file_index].filename, "w"); // open new file pointer in write mode
    // error checking if file pointer failed
    if (!fptr) {
        printf("Error: Failed to open file '%s' for writing.\n", file_table[file_index].filename);
        return -1;
    }
    fwrite(data, 1, data_size, fptr); // write data to the file
    fclose(fptr); // close the file pointer after

    // set the size of the file
    file_table[file_index].size = data_size;

    printf("Data written to file '%s' successfully.\n", file_table[file_index].filename);

    return 0;
}

// Read data from a file
int fileRead(int file_index, char *buffer, int buffer_size) {

    // check if file is currently opened
    if (file_table[file_index].is_open == 0) {
        printf("Error: file '%s' is not open.\n", file_table[file_index].filename);
        return -1;
    }

    // read contents from the file
    FILE *fptr = fopen(file_table[file_index].filename, "r"); // open new file pointer in read mode
    // error checking if file pointer failed
    if (!fptr) {
        printf("Error: Failed to open file '%s' for reading.\n", file_table[file_index].filename);
        return -1;
    }
    // read and print each line of the file
    while (fgets(buffer, buffer_size, fptr) != NULL) {
        printf("%s", buffer);
    }
    fclose(fptr); // close the file pointer after

    printf("Data read from file '%s' successfully.\n", file_table[file_index].filename);

    return 0;
}

// Close a file
int fileClose(int file_index) {

    // check if file is not open
    if (file_table[file_index].is_open == 0) {
        printf("Error: file '%s' is not open.\n", file_table[file_index].filename);
        return -1;
    } else {
        // if file is open, then set is open to closed
        file_table[file_index].is_open = 0;
        printf("File: '%s' closed successfully.\n", file_table[file_index].filename);
    }

    return 0;
}

// Delete a file
int fileDelete(const char *filename) {

    int file_index = -1;

    // find the file index of the file from the file table
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].filename, filename) == 0) {
            file_index = i; // store the index of the file from the file table
            break;
        }
    }

    // check if the file was not found
    if (file_index == -1) {
        printf("Error: File '%s' not found.\n", filename);
        return -1;
    }

    // delete the file from the OS file system
    if (remove(filename) == 0) {
        printf("File: '%s' deleted successfully.\n", filename);
    } else {
        printf("Error: Failed to delete '%s' from the OS file system.\n", filename);
        return -1;
    }

    // remove the file from the file table
    for (int i = file_index; i < file_count - 1; i++) {
        // shift all subsequent file entries up one position in the file table
        file_table[i] = file_table[i+1];
    }
    file_count--;

    return 0;
}