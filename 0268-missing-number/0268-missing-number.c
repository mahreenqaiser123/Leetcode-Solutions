int missingNumber(int* nums, int numsSize) {
    int xorAll = 0;
    
    // XOR all numbers from 0 to numsSize
    for (int i = 0; i <= numsSize; i++) {
        xorAll ^= i;
    }
    
    // XOR with all elements in the array
    for (int i = 0; i < numsSize; i++) {
        xorAll ^= nums[i];
    }
    
    return xorAll;
}
