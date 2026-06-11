/*
========================================================
Problem: Intersection of Two Linked Lists
========================================================

Intuition:
Align both linked lists by length and move together.

--------------------------------------------------------
Approach:
1. Calculate lengths of both lists.
2. Move pointer of longer list ahead by diff.
3. Traverse both simultaneously.
4. Return intersection node if found.

--------------------------------------------------------
Time Complexity:
O(N + M)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int len1 = 0, len2 = 0;

        while(temp1 != NULL) {
            len1++;
            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            len2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        if(len1 > len2) {
            int diff = len1 - len2;
            while(diff--) temp1 = temp1->next;
        } else {
            int diff = len2 - len1;
            while(diff--) temp2 = temp2->next;
        }

        while(temp1 != NULL && temp2 != NULL) {
            if(temp1 == temp2) return temp1;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};

// Striver SDE Sheet Challenge - Day 11
