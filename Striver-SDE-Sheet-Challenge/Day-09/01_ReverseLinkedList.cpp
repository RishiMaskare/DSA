/*
========================================================
Problem: Reverse Linked List
========================================================

Intuition:
We reverse links between nodes instead of values.

We keep track of:
- prev (previous node)
- curr (current node)
- next (temporary pointer)

--------------------------------------------------------
Approach:
1. Traverse the list.
2. Store next node.
3. Reverse current pointer.
4. Move prev and curr forward.
5. Return prev as new head.

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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Striver SDE Sheet Challenge - Day 9
