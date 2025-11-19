bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Move left pointer until alphanumeric
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Move right pointer until alphanumeric
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare lowercase characters
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
