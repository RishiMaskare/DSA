/*
========================================================
Problem: Detect Cycle in Linked List
========================================================

Intuition:
Use Floyd’s Cycle Detection Algorithm.

Fast pointer will eventually meet slow pointer if cycle exists.

--------------------------------------------------------
Approach:
1. Initialize slow and fast pointers.
2. Move slow by 1 and fast by 2.
3. If they meet → cycle exists.
4. If fast reaches NULL → no cycle.

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
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }
};

// Striver SDE Sheet Challenge - Day 11
