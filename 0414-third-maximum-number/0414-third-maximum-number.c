int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        long n = nums[i];

        // Skip duplicates
        if (n == first || n == second || n == third) continue;

        if (n > first) {
            third = second;
            second = first;
            first = n;
        }
        else if (n > second) {
            third = second;
            second = n;
        }
        else if (n > third) {
            third = n;
        }
    }

    // If third max doesn't exist, return the maximum (first)
    return (third == LONG_MIN ? first : third);
}
