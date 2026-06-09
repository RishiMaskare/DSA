/*
========================================================
Problem: Add Two Numbers (Linked List)
========================================================

Intuition:
Simulate digit-by-digit addition like manual math.

--------------------------------------------------------
Approach:
1. Traverse both lists.
2. Add values + carry.
3. Store last digit in node.
4. Update carry.
5. Handle leftover carry.

--------------------------------------------------------
Time Complexity:
O(max(N, M))

--------------------------------------------------------
Space Complexity:
O(max(N, M))

--------------------------------------------------------
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        int carry = 0;

        while(head1 || head2) {

            int sum = carry;

            if(head1) {
                sum += head1->val;
                head1 = head1->next;
            }

            if(head2) {
                sum += head2->val;
                head2 = head2->next;
            }

            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            carry = sum / 10;
        }

        if(carry) {
            temp->next = new ListNode(carry);
        }

        return dummyNode->next;
    }
};

// Striver SDE Sheet Challenge - Day 10
