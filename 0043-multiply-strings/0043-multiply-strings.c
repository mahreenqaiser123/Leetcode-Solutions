/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    
    // If either number is "0", return "0"
    if (num1[0] == '0' || num2[0] == '0') {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }

    int* resultArr = (int*)calloc(len1 + len2, sizeof(int)); // result array to store intermediate results

    // Perform multiplication digit by digit (from right to left)
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + resultArr[i + j + 1];
            resultArr[i + j + 1] = sum % 10;
            resultArr[i + j] += sum / 10;
        }
    }
    
    // Convert result array to string
    char* resultStr = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int idx = 0;
    
    // Skip leading zeros
    int i = 0;
    while (i < len1 + len2 && resultArr[i] == 0) i++;
    
    // Copy remaining digits
    while (i < len1 + len2) {
        resultStr[idx++] = resultArr[i++] + '0';
    }
    
    resultStr[idx] = '\0';
    free(resultArr);
    
    return resultStr;
}
