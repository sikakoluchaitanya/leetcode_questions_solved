/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth*/


class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int i = 0;
        
        while (i < words.size()) {
            int lineLength = words[i].length();
            int j = i + 1;
            
            // Calculate the number of words that can fit in the line
            while (j < words.size() && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            
            int spaces = maxWidth - lineLength;
            int evenlyDistributedSpaces = 1;
            int extraSpaces = 0;
            
            // If it's not the last line and there's more than one word in the line
            if (j != words.size() && j != i + 1) {
                evenlyDistributedSpaces = spaces / (j - i - 1);
                extraSpaces = spaces % (j - i - 1);
            }
            
            std::string line = words[i];
            
            for (int k = i + 1; k < j; k++) {
                int spaceCount = evenlyDistributedSpaces + (extraSpaces > 0 ? 1 : 0);
                extraSpaces--;
                
                line += std::string(spaceCount, ' ') + words[k];
            }
            
            // If it's the last line or only one word in the line
            line += std::string(maxWidth - line.length(), ' ');
            result.push_back(line);
            
            i = j;
        }
        
        return result;
    }
};
