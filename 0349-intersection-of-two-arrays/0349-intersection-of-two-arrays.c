int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int *result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int idx = 0;

    int i = 0, j = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            // Add only unique values
            if (idx == 0 || result[idx - 1] != nums1[i]) {
                result[idx++] = nums1[i];
            }
            i++;
            j++;
        } 
        else if (nums1[i] < nums2[j]) {
            i++;
        } 
        else {
            j++;
        }
    }

    *returnSize = idx;
    return result;
}
