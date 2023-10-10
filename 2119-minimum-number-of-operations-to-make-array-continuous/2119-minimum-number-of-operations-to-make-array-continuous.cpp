class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> sort_nums(begin(nums), end(nums)); // sorted the array to reduce the time complexity 
        vector<int> sorted_nums(begin(sort_nums), end(sort_nums));

        int result = INT_MAX;

        for(int i = 0; i<sorted_nums.size(); i++)
        {
            int L = sorted_nums[i];
            int R = L + n-1;

            int j = upper_bound(begin(sorted_nums), end(sorted_nums),R ) - begin(sorted_nums);

            int within_range = j-i;
            int out_of_range = n-within_range;

            result = min(result, out_of_range);       
        }
        return result;
    }

};