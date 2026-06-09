/*
========================================================
Problem: Middle of Linked List
========================================================

Intuition:
Use Slow & Fast pointers.

- Slow moves 1 step
- Fast moves 2 steps
When fast reaches end, slow is at middle.

--------------------------------------------------------
Approach:
1. Initialize slow and fast at head.
2. Move fast by 2 and slow by 1.
3. Stop when fast reaches NULL.
4. Return slow.

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
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Striver SDE Sheet Challenge - Day 9
