void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[insertPos++] = nums[i];
        }
    }

    // Fill the remaining positions with zero
    while (insertPos < numsSize) {
        nums[insertPos++] = 0;
    }
}
