/*
========================================================
Problem: Palindrome Linked List
========================================================

Intuition:
Find the middle of the list and reverse the second half.

Compare both halves node by node.

--------------------------------------------------------
Approach:
1. Find middle using slow & fast pointers.
2. Reverse second half.
3. Compare first and second halves.
4. If all values match, return true.

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
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* h2 = reverseLL(slow);
        ListNode* h1 = head;
        while(h1 && h2) {
            if(h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }

        return true;
    }
};

// Striver SDE Sheet Challenge - Day 12
