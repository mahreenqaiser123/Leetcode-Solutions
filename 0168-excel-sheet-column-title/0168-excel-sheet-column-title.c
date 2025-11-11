char* convertToTitle(int columnNumber) {
    char temp[10];  // temporary buffer (enough for 32-bit integer)
    int index = 0;

    // Build the title in reverse order
    while (columnNumber > 0) {
        columnNumber--;  // adjust for 1-based indexing
        temp[index++] = (columnNumber % 26) + 'A';
        columnNumber /= 26;
    }

    // Reverse the string to get correct order
    char* result = (char*)malloc(index + 1);
    for (int i = 0; i < index; i++) {
        result[i] = temp[index - i - 1];
    }
    result[index] = '\0';

    return result;
}
