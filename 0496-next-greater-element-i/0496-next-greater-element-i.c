/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* result = (int*)malloc(nums1Size * sizeof(int)); // to store results
    int* next = (int*)malloc(nums2Size * sizeof(int));   // to store next greater for nums2
    int* stack = (int*)malloc(nums2Size * sizeof(int));  // monotonic stack
    int top = -1; // stack pointer
    
    // Map each element in nums2 to its next greater element
    for (int i = nums2Size - 1; i >= 0; i--) {
        while (top != -1 && nums2[stack[top]] <= nums2[i]) {
            top--; // pop smaller values
        }
        next[i] = (top == -1 ? -1 : nums2[stack[top]]);
        stack[++top] = i; // push current index
    }
    
    // For each element in nums1, find its position in nums2 and lookup result
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[i] = next[j];
                break;
            }
        }
    }
    
    free(next);
    free(stack);
    return result;
}
