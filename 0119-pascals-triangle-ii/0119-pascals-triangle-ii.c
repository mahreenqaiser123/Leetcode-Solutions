
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));
    
    // Initialize the first element
    row[0] = 1;
    
    // Build the row iteratively
    for (int i = 1; i <= rowIndex; i++) {
        row[i] = 1; // Last element of each row is always 1
        
        // Update the inner elements from right to left
        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }
    
    return row;
}

int main() {
    int rowIndex = 3;
    int returnSize;
    int* row = getRow(rowIndex, &returnSize);
    
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", row[i]);
        if (i != returnSize - 1) printf(", ");
    }
    printf("]\n");
    
  
