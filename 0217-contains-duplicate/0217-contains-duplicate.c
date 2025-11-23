int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x - y); 
}

bool containsDuplicate(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);

    // Check for duplicates
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}
