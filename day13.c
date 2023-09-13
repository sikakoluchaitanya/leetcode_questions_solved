/*
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.*/


#define MAX_LEN 1001

// Function to check if a substring is in the dictionary
int isInDictionary(char* s, char** dictionary, int dictionarySize, int start, int end) {
    char substring[MAX_LEN];
    strncpy(substring, s + start, end - start + 1);
    substring[end - start + 1] = '\0';

    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(substring, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Recursive function with memoization
int dp(char* s, char** dictionary, int dictionarySize, int start, int* memo) {
    if (start == strlen(s)) {
        return 0;
    }

    if (memo[start] != -1) {
        return memo[start];
    }

    int ans = INT_MAX;

    for (int end = start; end < strlen(s); end++) {
        if (isInDictionary(s, dictionary, dictionarySize, start, end)) {
            int next = dp(s, dictionary, dictionarySize, end + 1, memo);
            ans = (ans < next) ? ans : next;
        }
    }

    ans = (ans < dp(s, dictionary, dictionarySize, start + 1, memo) + 1) ? ans : dp(s, dictionary, dictionarySize, start + 1, memo) + 1;
    memo[start] = ans;
    return ans;
}

int minExtraChar(char* s, char** dictionary, int dictionarySize) {
    int* memo = (int*)malloc((strlen(s) + 1) * sizeof(int));
    for (int i = 0; i <= strlen(s); i++) {
        memo[i] = -1;
    }

    int result = dp(s, dictionary, dictionarySize, 0, memo);
    free(memo);
    return result;
}
