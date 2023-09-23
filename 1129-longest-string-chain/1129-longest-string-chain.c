// Function to compare two strings based on their lengths (used for sorting)
int compare(const void* a, const void* b) {
    return strlen(*(const char**)a) - strlen(*(const char**)b);
}

// Function to check if word2 can be obtained from word1 by removing one character
int isPredecessor(const char* word1, const char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    if (len1 + 1 != len2) {
        return 0;
    }
    
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (word1[i] == word2[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    
    return i == len1;
}

int longestStrChain(char** words, int wordsSize) {
    // Sort the words by their lengths
    qsort(words, wordsSize, sizeof(char*), compare);
    
    // Initialize an array to store the length of the longest chain ending at each word
    int* dp = (int*)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1; // Initialize each word as a chain of length 1
    }
    
    int maxLength = 1; // Initialize the maximum chain length
    
    for (int i = 1; i < wordsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (isPredecessor(words[j], words[i])) {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                maxLength = maxLength > dp[i] ? maxLength : dp[i];
            }
        }
    }
    
    free(dp);
    
    return maxLength;
}