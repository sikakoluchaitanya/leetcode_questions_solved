bool isSubsequence(char * s, char * t)
{
    int i = 0;  // Pointer for string s
    int j = 0;  // Pointer for string t

    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return s[i] == '\0';
}