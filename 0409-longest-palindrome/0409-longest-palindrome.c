#include <stdio.h>
#include <string.h>

int longestPalindrome(char *s) {
    int freq[128] = {0};  // ASCII letters (upper + lower)
    int length = 0;
    int odd_found = 0;

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;
    }

    // Calculate the palindrome length
    for (int i = 0; i < 128; i++) {
        length += (freq[i] / 2) * 2; // use all even parts
        if (freq[i] % 2 == 1)
            odd_found = 1;
    }

    // Add 1 if there’s any odd count (for the center)
    if (odd_found)
        length++;

    return length;
}
