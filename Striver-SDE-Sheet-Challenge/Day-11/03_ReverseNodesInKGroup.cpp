/*
========================================================
Problem: Reverse Nodes in K Group
========================================================

Intuition:
Reverse linked list in chunks of size k using recursion.

--------------------------------------------------------
Approach:
1. Check if k nodes exist.
2. Reverse first k nodes.
3. Recursively solve remaining list.
4. Connect reversed part with recursion result.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N / K) recursion stack

--------------------------------------------------------
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int cnt = 0;

        while(cnt < k) {
            if(temp == NULL) return head;
            temp = temp->next;
            cnt++;
        }

        ListNode* prevNode = reverseKGroup(temp, k);
        cnt = 0;
        temp = head;

        while(cnt < k) {

            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};

// Striver SDE Sheet Challenge - Day 11
