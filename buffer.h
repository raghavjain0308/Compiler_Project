#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 4096  // Define buffer size
char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];  // Twin buffers
char *activeBuffer, *inactiveBuffer;             // Active & inactive pointers
size_t bufferSize;                               // Bytes read in active buffer
FILE *file;
int currentIndex;   
FILE *getStream(FILE *fp);
size_t loadBuffer(char *buffer);
int getNextChar();