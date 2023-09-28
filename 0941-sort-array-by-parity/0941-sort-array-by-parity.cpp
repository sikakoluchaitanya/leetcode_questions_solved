class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
       int n = nums.size();
        vector<int> n2;  // Create a new vector to store the sorted eleme
        
        for (int p1 = 0; p1 < n; p1++) {
            if (nums[p1] % 2 == 0) {
                n2.push_back(nums[p1]);  // Add even elements to n2
            }
        }

        for (int p1 = 0; p1 < n; p1++) {
            if (nums[p1] % 2 != 0) {
                n2.push_back(nums[p1]);  // Add odd elements to n2
            }
        }
        
        return n2;
    }
    
};