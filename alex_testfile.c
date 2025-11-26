#include "alex_libFS.h"
#include <ctype.h>  // For tolower()

// Function to display the menu
void displayMenu() {
    // Build your code
}

// Function to wait for user input to continue
void waitForUser() {
    printf("\nPress Enter to continue...");
    getchar();  // Wait for Enter key
    getchar();  // Clear the newline character from the buffer
}

int main() {
    char filename[MAX_FILENAME];
    char introduction[] = "Hello, my name is John Doe.\n\n"
                          "I am a computer science student passionate about systems programming.\n"
                          "This project involves creating a file system library in C.\n"
                          "I hope you find my implementation useful!";
    int file_index = -1;  // Track the currently open file
    int choice;
    // char buffer[MAX_FILE_SIZE];

    while (1) {
        displayMenu();
        scanf("%d", &choice);  // Get user choice
        getchar();  // Clear the newline character from the buffer

        switch (choice) {
            case 1:  // Create a file
                // Build your code

            case 2:  // Open a file
               // Build your code

            case 3:  // Write to a file
                // Build your code

            case 4:  // Read from a file 
                printf("To be finished.\n");
                break;


            case 7:  // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                waitForUser();
                break;
        }
    }

    return 0;
}