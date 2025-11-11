int dominantIndex(int* nums, int numsSize) {
    int maxIndex = 0;
    
    // Step 1: Find index of largest element
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }
    
    // Step 2: Check if the largest element is at least twice all others
    for (int i = 0; i < numsSize; i++) {
        if (i != maxIndex && nums[maxIndex] < 2 * nums[i]) {
            return -1;
        }
    }
    
    // Step 3: If condition holds, return index of largest element
    return maxIndex;
}
