#include"remove_comments.h"
void removeComments(bool printOutput) {
    int ch;
    bool inComment = false;

    while ((ch = getNextChar()) != EOF) {
        if (inComment) {
            if (ch == '\n') {
                inComment = false; // End of comment line
                if (printOutput) putchar(ch);
            }
        } 
        else {
            if (ch == '%') {
                inComment = true; // Start of comment
            } 
            else {
                if (printOutput) putchar(ch);
            }
        }
    }
}
