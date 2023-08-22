/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
*/

char * convertToTitle(int columnNumber)
{
   int numDigits = 0;
    int temp = columnNumber;
    
    while (temp > 0) {
        temp = (temp - 1) / 26;
        numDigits++;
    }
    
    char *title = (char *)malloc((numDigits + 1) * sizeof(char));
    title[numDigits] = '\0';

    while (columnNumber > 0) {
        columnNumber--;
        title[--numDigits] = 'A' + (columnNumber % 26);
        columnNumber /= 26;
    }

    return title;
  
}
