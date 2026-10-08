int maxSubArray(int* nums, int numsSize) {
    int best = nums[0], cur = nums[0];
    for (int i = 1; i < numsSize; i++) {
        cur = (cur > 0 ? cur : 0) + nums[i];
        if (cur > best) best = cur;
    }
    return best;
}