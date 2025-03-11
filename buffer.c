#include "buffer.h"
size_t loadBuffer(char *buffer) {
    return fread(buffer, 1, BUFFER_SIZE, file);
}
int getNextChar() {
    if (currentIndex >= bufferSize) {
        // Switch buffers
        char *temp = activeBuffer;
        activeBuffer = inactiveBuffer;
        inactiveBuffer = temp;

        // Refill the inactive buffer
        bufferSize = loadBuffer(inactiveBuffer);
        currentIndex = 0;

        if (bufferSize == 0) return EOF;  // End of file
    }
    return activeBuffer[currentIndex++];
}