/*Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to find the length of the linked list.
int findLength(struct ListNode* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to split the linked list into k parts.
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int length = findLength(head);
    int partSize = length / k;
    int extraNodes = length % k;
    
    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));

    for (int i = 0; i < k; i++) {
        result[i] = head;
        
        int currentPartSize = partSize + (i < extraNodes ? 1 : 0);

        for (int j = 1; j < currentPartSize; j++) {
            head = head->next;
        }

        if (head) {
            struct ListNode* next = head->next;
            head->next = NULL;
            head = next;
        }
    }

    *returnSize = k;
    return result;
}
