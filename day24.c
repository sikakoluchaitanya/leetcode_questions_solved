/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.*/


// first approch 

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
     int totalSize = nums1Size + nums2Size;
    int* merged = (int*)malloc(sizeof(int) * totalSize);
    
    int ptr1 = 0, ptr2 = 0;
    int mergedPtr = 0;
    
    while (ptr1 < nums1Size && ptr2 < nums2Size) {
        if (nums1[ptr1] < nums2[ptr2]) {
            merged[mergedPtr++] = nums1[ptr1++];
        } else {
            merged[mergedPtr++] = nums2[ptr2++];
        }
    }
    
    while (ptr1 < nums1Size) {
        merged[mergedPtr++] = nums1[ptr1++];
    }
    
    while (ptr2 < nums2Size) {
        merged[mergedPtr++] = nums2[ptr2++];
    }
    
    double median;
    if (totalSize % 2 == 0) {
        // Even number of elements, take the average of the middle two.
        int mid1 = totalSize / 2 - 1;
        int mid2 = totalSize / 2;
        median = (merged[mid1] + merged[mid2]) / 2.0;
    } else {
        // Odd number of elements, the median is the middle element.
        int mid = totalSize / 2;
        median = merged[mid];
    }
    
    free(merged);
    return median;
}



// second approch 

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        // Swap the arrays to ensure nums1 is the smaller one.
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int left = 0, right = nums1Size, total = nums1Size + nums2Size;
    int partition1, partition2, maxLeft1, maxLeft2, minRight1, minRight2;

    while (left <= right) {
        partition1 = (left + right) / 2;
        partition2 = (total + 1) / 2 - partition1;

        maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        minRight1 = (partition1 == nums1Size) ? INT_MAX : nums1[partition1];

        maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        minRight2 = (partition2 == nums2Size) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // Found a valid partition.
            if (total % 2 == 0) {
                // If the total number is even, return the average of the maxLeft and minRight values.
                double leftMax = maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2;
                double rightMin = minRight1 < minRight2 ? minRight1 : minRight2;
                return (leftMax + rightMin) / 2;
            } else {
                // If the total number is odd, return the max of maxLeft1 and maxLeft2 (since both will have the median element).
                return maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2;
            }
        } else if (maxLeft1 > minRight2) {
            // Move the partition1 to the left.
            right = partition1 - 1;
        } else {
            // Move the partition1 to the right.
            left = partition1 + 1;
        }
    }

    // Return 0.0 if no solution is found.
    return 0.0;
}

