/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105*/

int* countBits(int n, int* returnSize) {
    // Initialize an array to store the count of 1's for each number from 0 to n
    int* ans = (int*)malloc(sizeof(int) * (n + 1));
    
    for (int i = 0; i <= n; i++) {
        int count = 0;
        int num = i;
        
        // Count the number of 1's in the binary representation of 'num'
        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }
        
        ans[i] = count;
    }
    
    // Set the returnSize to the size of the result array
    *returnSize = n + 1;
    
    return ans;
}
