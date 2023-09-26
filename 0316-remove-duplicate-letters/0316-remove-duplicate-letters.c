char * removeDuplicateLetters(char * s)
{
    int len = strlen(s);
    int count[26] = {0}; // To store the count of each character
    int used[26] = {0};  // To keep track of whether a character is already in the result
    char stack[26];      // To store the result characters
    int top = -1;        // Stack pointer

    // Count the frequency of each character in the string
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        char currentChar = s[i];

        // Decrement the count of the current character
        count[currentChar - 'a']--;

        // If the current character is already in the result, skip it
        if (used[currentChar - 'a']) {
            continue;
        }

        // Remove characters from the result stack if they are greater than the current character
        while (top >= 0 && currentChar < stack[top] && count[stack[top] - 'a'] > 0) {
            used[stack[top] - 'a'] = 0;
            top--;
        }

        // Push the current character onto the stack
        stack[++top] = currentChar;
        used[currentChar - 'a'] = 1;
    }

    // Create the result string
    char* result = (char*)malloc(top + 2);
    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    result[top + 1] = '\0';

    return result;
}