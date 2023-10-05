class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> result;
    
    if (nums.empty()) {
        return result;
    }
    
    int element1 = 0, element2 = 0;
    int count1 = 0, count2 = 0;
    
    // Find potential element
    for (int num : nums) {
        if (num == element1) {
            count1++;
        } else if (num == element2) {
            count2++;
        } else if (count1 == 0) {
            element1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            element2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    
    // Count occurrences of element in the second pass
    count1 = 0;
    count2 = 0;
    
    for (int num : nums) {
        if (num == element1) {
            count1++;
        } else if (num == element2) {
            count2++;
        }
    }
    
    int n = nums.size();
    
    if (count1 > n / 3) {
        result.push_back(element1);
    }
    if (count2 > n / 3) {
        result.push_back(element2);
    }
    
    return result;
    }
};
