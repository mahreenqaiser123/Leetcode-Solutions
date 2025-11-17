/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    int left = 0;
    int right = numsSize - 1;
    int idx = numsSize - 1;
    
    // Use two pointers to fill result array from the back
    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];
        
        if (leftSq > rightSq) {
            result[idx--] = leftSq;
            left++;
        } else {
            result[idx--] = rightSq;
            right--;
        }
    }
    
    return result;
}
