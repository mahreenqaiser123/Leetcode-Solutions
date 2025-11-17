/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes array.
 * Note: Both returned array and *returnColumnSizes array must be malloced,
 * assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    
    // Allocate memory for the result and column sizes
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    // Generate each row of Pascal's Triangle
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1; // Row i has i+1 elements
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        triangle[i][0] = triangle[i][i] = 1; // First and last elements are 1
        
        // Fill in the rest using the formula:
        // triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    return triangle;
}
