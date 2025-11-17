int majorityElement(int* nums, int numsSize) {
    int candidate = 0, count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];  // Set current element as potential candidate
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }
    
    return candidate;
}
