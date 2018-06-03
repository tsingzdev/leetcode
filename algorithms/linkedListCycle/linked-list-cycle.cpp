// https://leetcode.com/problems/linked-list-cycle/description/
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if(slow == fast) {
                return true; // there is a cycle;
            }
        }
        return false; // No cycle;

    }
};
