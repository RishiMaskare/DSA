/*
========================================================
Problem: Merge Two Sorted Linked Lists
========================================================

Intuition:
Use a dummy node to simplify merging.

Compare nodes one by one and build result list.

--------------------------------------------------------
Approach:
1. Create dummy node.
2. Use temp pointer.
3. Compare list1 and list2 nodes.
4. Attach smaller node to result.
5. Attach remaining list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL) {

            if(list1->val < list2->val) {

                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if(list1) temp->next = list1;
        else temp->next = list2;

        return dummyNode->next;
    }
};

// Striver SDE Sheet Challenge - Day 9
