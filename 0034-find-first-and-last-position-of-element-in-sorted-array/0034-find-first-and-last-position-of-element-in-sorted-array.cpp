class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    int left = findLeftBound(nums, target);
    int right = findRightBound(nums, target);
    result.push_back(left);
    result.push_back(right);

    return result;
    }

    int findLeftBound(vector<int>& nums, int target) {
    int index = -1, low = 0, high = nums.size() - 1;

    // Standard binary search
    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target) {
        index = mid;
        high = mid - 1; // Look in the left sub-array
      }
      else if (nums[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return index;
  }

  int findRightBound(vector<int>& nums, int target) {
    int index = -1, low = 0, high = nums.size() - 1;

    // Standard binary search
    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target) {
        index = mid;
        low = mid + 1; // Look in the right sub-array
      }
      else if (nums[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return index;
  }
};