class Solution {
public:
    int numOfArrays(int n, int m, int k) {
       const int MOD = 1000000007;
        
        // Initialize two 2D arrays dp and prevDp
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prevDp(m + 1, vector<int>(k + 1, 0));
        
        // Set the base cases
        for (int maxSoFar = 1; maxSoFar <= m; maxSoFar++) {
            prevDp[maxSoFar][0] = 1;
        }
        
        // Iterate from n - 1 down to 0
        for (int i = n - 1; i >= 0; i--) {
            // Reset dp
            dp.assign(m + 1, vector<int>(k + 1, 0));
            
            for (int maxSoFar = m; maxSoFar >= 0; maxSoFar--) {
                for (int remain = 0; remain <= k; remain++) {
                    // Initialize ans
                    long long ans = (long long)maxSoFar * prevDp[maxSoFar][remain] % MOD;
                    
                    if (remain > 0) {
                        for (int num = maxSoFar + 1; num <= m; num++) {
                            ans = (ans + prevDp[num][remain - 1]) % MOD;
                        }
                    }
                    
                    dp[maxSoFar][remain] = ans;
                }
            }
            
            // Update prevDp with dp for the next iteration
            prevDp = dp;
        }
        
        return dp[0][k];
    }
};