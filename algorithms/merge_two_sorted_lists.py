"""
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, self.next)
"""
class ListNode (object):
    def __init__(self,x):
        self.val = x
        self.next = None
"""
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        dummy = ListNode(0)
        dummy_end = dummy

        while l1 is not None and l2 is not None:
            if l1.val < l2.val:
                dummy_end.next = l1
                l1 = l1.next

            else:
                dummy_end.next = l2;
                l2 = l2.next

            dummy_end = dummy_end.next

        if l1 is not None:
            dummy_end = l1
        else:
            dummy_end = l2

        return dummy.next

if __name__ == "__main__":
    l1 = ListNode(0)
    l1.next = ListNode(1)
    l2 = ListNode (2)
    l2.next = ListNode(3)
    print Solution().mergeTwoLists(l1, l2)

