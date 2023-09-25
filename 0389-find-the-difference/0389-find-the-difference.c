char findTheDifference(char * s, char * t)
{
    int char_count[26] = {0}; // Assuming only lowercase letters

    // Count the occurrences of characters in string t
    for (int i = 0; t[i] != '\0'; i++) {
        char_count[t[i] - 'a']++;
    }

    // Subtract the counts of characters in string s
    for (int i = 0; s[i] != '\0'; i++) {
        char_count[s[i] - 'a']--;
    }

    // Find the character with a count of 1, as it was added to t
    for (int i = 0; i < 26; i++) {
        if (char_count[i] == 1) {
            return 'a' + i;
        }
    }

    return '\0'; 
}