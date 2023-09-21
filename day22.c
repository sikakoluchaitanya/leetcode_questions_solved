/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
*/

int findDuplicate(int* nums, int numsSize)
{
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect whether a cycle exists.
    do {
        slow = nums[slow];          // Move one step.
        fast = nums[nums[fast]];    // Move two steps.
    } while (slow != fast);

    // Phase 2: Find the entrance to the cycle.
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    // Return the duplicate number.
    return slow;
}

// this is more correct to solve this problem because we are not using any thing to increment the value of the pointer instead the movement is based on the values stored at the particular location of the array which is very random but if there are same values in the array then the slow and fast will meet at some point  
