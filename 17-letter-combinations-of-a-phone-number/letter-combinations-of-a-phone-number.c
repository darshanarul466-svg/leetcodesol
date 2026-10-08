#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mapping from digits to corresponding letters
const char* phone[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void backtrack(char* digits, int index, char* current, int depth, char** result, int* returnSize) {
    if (digits[index] == '\0') {
        current[depth] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = phone[digit];
    
    for (int i = 0; letters[i] != '\0'; i++) {
        current[depth] = letters[i];
        backtrack(digits, index + 1, current, depth + 1, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) {
        return NULL;
    }

    // Maximum possible combinations is 4^4 = 256 for digits length up to 4
    char** result = (char**)malloc(256 * sizeof(char*));
    char current[5];

    backtrack(digits, 0, current, 0, result, returnSize);
    return result;
}
