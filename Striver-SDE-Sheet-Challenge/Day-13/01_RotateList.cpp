/*
========================================================
Problem: Rotate List
========================================================

Intuition:
The last k nodes become the new beginning
of the linked list.

--------------------------------------------------------
Approach:
1. Find length of linked list.
2. Reduce k using modulo.
3. Find new tail node.
4. Break the list.
5. Attach old tail to old head.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL) return head;
        ListNode* oldHead = head;
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        k = k % len;
        if(k == 0) return head;
        ListNode* curr = head;
        int cond = len-k-1;
        while(cond--) {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        ListNode* temp2 = head;
        while(temp2 != NULL && temp2->next != NULL) {
            temp2 = temp2->next;
        }
        if(temp2) temp2->next = oldHead;
        else head->next = oldHead;
        return head;
    }
};

// Striver SDE Sheet Challenge - Day 13
