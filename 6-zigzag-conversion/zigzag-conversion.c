#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            // Add character from the primary down/diagonal step
            result[index++] = s[j + i];
            
            // For rows other than the first and last, add the second character in the cycle
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                result[index++] = s[j + cycleLen - i];
            }
        }
    }
    result[index] = '\0';
    return result;
}