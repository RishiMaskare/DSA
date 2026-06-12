/*
========================================================
Problem: Linked List Cycle II
========================================================

Intuition:
Use Floyd's Cycle Detection Algorithm.

After slow and fast meet:
- Move slow to head.
- Move both one step at a time.
- Their next meeting point is the start of cycle.

--------------------------------------------------------
Approach:
1. Detect cycle using slow & fast pointers.
2. If no cycle exists, return NULL.
3. Reset slow to head.
4. Move both pointers together.
5. Return meeting point.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------


*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool isCycle = false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                isCycle = true;
                break;
            }
        }
        if(!isCycle) {
            return NULL;
        }
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

// Striver SDE Sheet Challenge - Day 12
