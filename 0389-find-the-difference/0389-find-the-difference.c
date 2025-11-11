char findTheDifference(char *s, char *t) {
    int sumS = 0, sumT = 0;
    
    // Sum ASCII values of string s
    for (int i = 0; s[i] != '\0'; i++) {
        sumS += s[i];
    }
    
    // Sum ASCII values of string t
    for (int i = 0; t[i] != '\0'; i++) {
        sumT += t[i];
    }
    
    // The difference corresponds to the added character
    return (char)(sumT - sumS);
}
