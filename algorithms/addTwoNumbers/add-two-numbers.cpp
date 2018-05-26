/*URL: https://leetcode.com/problems/add-two-numbers/description/
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 **/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        auto curr = &dummy;

        auto carry = 0;
        while (l1 || l2|| carry) {
            auto a = l1? l1->val:0, b=l2?l2->val:0;
            auto val = carry + a + b;
            curr->next = new ListNode(val%10);
            carry = val/10;
            l1 = l1? l1->next:nullptr;
            l2 = l2? l2->next:nullptr;
            curr = curr->next;
        }
        return dummy.next;
    }
};

