#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    // Array to store the last seen index of each character (ASCII size 128)
    int charIndex[128];
    for (int i = 0; i < 128; i++) {
        charIndex[i] = -1;
    }
    
    int maxLength = 0;
    int left = 0;
    
    for (int right = 0; s[right] != '\0'; right++) {
        char currentChar = s[right];
        
        // If the character is already in the current window, move the left pointer
        if (charIndex[currentChar] >= left) {
            left = charIndex[currentChar] + 1;
        }
        
        // Update the last seen position of the current character
        charIndex[currentChar] = right;
        
        // Calculate the maximum length found so far
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}