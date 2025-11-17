#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));
    
    if (!row) return NULL; // Memory allocation check
    
    row[0] = 1; // First element is always 1
    
    // Build row iteratively
    for (int i = 1; i <= rowIndex; i++) {
        row[i] = 1; // Last element of current row is always 1
        
        // Update the inner elements from right to left
        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }
    
    return row;
}
