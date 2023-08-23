/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.*/

char* reorganizeString(char* s) {
    int length = strlen(s);
    int charCount[26] = {0};

    // Count the frequency of each character.
    for (int i = 0; i < length; i++) {
        charCount[s[i] - 'a']++;
    }

    // Find the most frequent character and its frequency.
    int maxFreq = 0;
    char maxFreqChar = 'a';
    for (int i = 0; i < 26; i++) {
        if (charCount[i] > maxFreq) {
            maxFreq = charCount[i];
            maxFreqChar = i + 'a';
        }
    }

    // Check if reorganization is possible.
    if (maxFreq > (length + 1) / 2) {
        return "";  // Not possible.
    }

    // Create the result array.
    char* result = (char*)malloc((length + 1) * sizeof(char));
    result[length] = '\0';

    // Fill the result array with alternating characters.
    int index = 0;
    while (charCount[maxFreqChar - 'a'] > 0) {
        result[index] = maxFreqChar;
        index += 2;
        charCount[maxFreqChar - 'a']--;
    }

    // Fill other characters.
    for (int i = 0; i < 26; i++) {
        while (charCount[i] > 0) {
            if (index >= length) {
                index = 1;
            }
            result[index] = i + 'a';
            index += 2;
            charCount[i]--;
        }
    }

    return result;
}
