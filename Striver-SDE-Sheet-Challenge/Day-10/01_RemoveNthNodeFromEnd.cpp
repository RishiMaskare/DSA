/*
========================================================
Problem: Remove Nth Node From End of Linked List
========================================================

Intuition:
Find length first, then locate (len - n + 1)th node.

--------------------------------------------------------
Approach:
1. Traverse list → find length.
2. Compute target node position.
3. If removing head → update head.
4. Else move to previous node and delete target.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next == NULL && n == 1) return NULL;

        ListNode* temp = head;
        int len = 0;

        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        int node = len - n + 1;

        if(node == 1) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        temp = head;
        ListNode* prev = NULL;

        for(int i = 1; i < node; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;

        return head;
    }
};

// Striver SDE Sheet Challenge - Day 10
