char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0, k = 0;
    int maxLen = (i > j ? i : j) + 3; // +2 for carry + null terminator
    char* res = (char*)malloc(maxLen * sizeof(char));

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // Reverse the string since digits were added from end to start
    for (int l = 0; l < k / 2; l++) {
        char temp = res[l];
        res[l] = res[k - 1 - l];
        res[k - 1 - l] = temp;
    }

    res[k] = '\0';
    return res;
}
