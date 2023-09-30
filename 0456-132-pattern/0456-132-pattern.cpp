class Solution {
public:
    bool find132pattern(vector<int>& nums) 
{
    int n = nums.size();
    if (n < 3) {
        return false;
    }

    std::stack<int> candidate_k; 
    int nums_k = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        while (!candidate_k.empty() && nums[i] > candidate_k.top()) {
            nums_k = candidate_k.top(); 
            candidate_k.pop();
        }
        if (nums[i] > nums_k) {
            candidate_k.push(nums[i]);
        }
        else if (nums[i] < nums_k) {
            return true; 
        }
    }
    return false;
}
};