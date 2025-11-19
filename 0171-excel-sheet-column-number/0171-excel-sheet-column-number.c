int titleToNumber(char* columnTitle) {
    long result = 0;

    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int value = columnTitle[i] - 'A' + 1;  // Convert letter to number (A=1 ... Z=26)
        result = result * 26 + value;          // Base-26 accumulation
    }

    return result;
}
