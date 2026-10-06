#include <stdio.h>
#include <stdbool.h>

bool isSorted(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int operations = 0;
    int currentSize = numsSize;


    while (!isSorted(nums, currentSize)) {
        int minSum = nums[0] + nums[1];
        int minIdx = 0;

        for (int i = 1; i < currentSize - 1; i++) {
            int currentSum = nums[i] + nums[i + 1];
            if (currentSum < minSum) {
                minSum = currentSum;
                minIdx = i;
            }
        }

        // Replace the pair at minIdx and minIdx + 1 with their sum
        nums[minIdx] = minSum;

        // Shift the remaining elements to the left
        for (int i = minIdx + 1; i < currentSize - 1; i++) {
            nums[i] = nums[i + 1];
        }

        currentSize--;
        operations++;
    }

    return operations;
}