// Alex Ryse - CS470 Lab4

#include "alex_libFS.h"
#include <ctype.h>  // For tolower()

// Function to display the menu
void displayMenu() {
    printf(
        "--- Menu ---\n"
        "1. Create a file\n"
        "2. Open a file\n"
        "3. Write to a file\n"
        "4. Read from a file\n"
        "5. Close a file\n"
        "6. Delete a file\n"
        "7. Exit\n"
        "Enter your choice: "
    );
}

// Function to wait for user input to continue
void waitForUser() {
    printf("\nPress Enter to continue...");
    getchar();  // Wait for Enter key
    getchar();  // Clear the newline character from the buffer
}

int main() {
    char filename[MAX_FILENAME];
    char introduction[] = "Hello, my name is Alex Ryse!\n\n"
                          "I am a fourth year computer science student at Central Washington University.\n"
                          "I am very passionate about full-stack development and generative AI.\n"
                          "This is a user-level file system library simulation that emaulates key functions of a file system.\n"
                          "I hope you enjoy using my project!";
    int file_index = -1;  // Track the currently open file
    int choice;
    // char buffer[MAX_FILE_SIZE];

    while (1) {
        displayMenu();
        scanf("%d", &choice);  // Get user choice
        getchar();  // Clear the newline character from the buffer

        switch (choice) {
            case 1:  // Create a file
                printf("Enter filename to create: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // remove newline character
                // attempt to create the file
                if (fileCreate(filename) != 0) {
                    printf("Error creating file.\n");
                }
                waitForUser();
                break;

            case 2:  // Open a file
                printf("Enter the filename to open: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // remove newline character
                // attempt to open the file
                file_index = fileOpen(filename);
                if (file_index == -1) {
                    printf("Error opening file.\n");
                }
                waitForUser();
                break;

            case 3:  // Write to a file
                // check if a file is open or not
                if (file_index == -1) {
                    printf("Error: No file is open. Please open a file to continue.\n");
                } else {
                    printf("Writing introduction to file '%s'...\n", filename);
                    // attempt to write to the file
                    if (fileWrite(file_index, introduction) != 0) {
                        printf("Error writing to file.\n");
                    }
                }
                waitForUser();
                break;

            case 4:  // Read from a file 
                printf("%d\n", choice);
                break;

            case 5:  // Close a file
                printf("%d\n", choice);
                break;

            case 6:  // Delete a file
                printf("%d\n", choice);
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