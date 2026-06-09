/*
========================================================
Problem: Delete Node in a Linked List (No Head Given)
========================================================

Intuition:
We cannot access previous node, so we overwrite current node.

--------------------------------------------------------
Approach:
1. Copy value from next node.
2. Skip next node.
3. Effectively delete current node.

--------------------------------------------------------
Time Complexity:
O(1)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------
*/

class Solution {
public:
    void deleteNode(ListNode* node) {

        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Striver SDE Sheet Challenge - Day 10
