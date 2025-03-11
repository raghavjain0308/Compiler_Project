#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "remove_comments.h"
#include "buffer.h"
#include "lexer.h"

// Placeholder function for lexer and parser invocation
void runLexerAndParser() {
    // Here you would invoke your actual lexer and parser functions.
    // For demonstration, we'll just simulate a delay.
    
    printf("Running lexer and parser...\n");
    
    // Simulate processing delay (you can remove this once actual lexer/parser is implemented)
    for (volatile long i = 0; i < 100000000; ++i);
    
    printf("Lexer and parser completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Initialize buffers
    activeBuffer = buffer1;
    inactiveBuffer = buffer2;
    bufferSize = loadBuffer(activeBuffer);
    currentIndex = 0;

    char choice;
    while (1) {
        printf("--------------------Compiler_Project-----------------------\n");
        printf("--------------------Group No. -----------------------------\n");
        printf("\nMenu:\n");
        printf("Choose from the options below: \n");
        printf("0. Exit\n");
        printf("1. Remove Comments\n");
        printf("2. Print Token List\n");
        printf("3. Generate Parse Tree\n");
        printf("4. Calculate total time taken\n");
        
        scanf(" %c", &choice);

        switch (choice) {
            case '0':
                printf("Exiting program...\n");
                fclose(file);
                return 0;

            case '1':
                printf("\nComment-free Code......\n");
                removeComments(true);
                break;
            case '2':
                initialize_Lexer(file);
                break;
            case '4': {   // Timing functionality added here
                clock_t start_time, end_time;
                double total_CPU_time, total_CPU_time_in_seconds;

                start_time = clock();

                // Invoke your lexer and parser here
                runLexerAndParser();

                end_time = clock();

                total_CPU_time = (double)(end_time - start_time);
                total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;

                printf("\nTotal CPU time taken: %.2lf clock ticks\n", total_CPU_time);
                printf("Total CPU time in seconds: %.4lf seconds\n", total_CPU_time_in_seconds);

                break;
            }

            default:
                printf("Invalid option. Try again.\n");
        }

        // Reset file for reprocessing after each operation
        fseek(file, 0, SEEK_SET);
        activeBuffer = buffer1;
        inactiveBuffer = buffer2;
        bufferSize = loadBuffer(activeBuffer);
        currentIndex = 0;
    }

    fclose(file);
    return 0;
}