int firstUniqChar(char *s) {
    int freq[26] = {0};
    
    // Step 1: Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    
    // Step 2: Find the first character with frequency 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    // Step 3: If no unique character found
    return -1;
}
