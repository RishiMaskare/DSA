/*
========================================================
Problem: Flattening a Linked List
========================================================

Intuition:
Flatten the list from right to left.

Merge current list with already flattened remainder.

--------------------------------------------------------
Approach:
1. Recursively flatten next list.
2. Merge two sorted bottom-linked lists.
3. Return merged result.

--------------------------------------------------------
Time Complexity:
O(N * M) (depends on merge operations)

--------------------------------------------------------
Space Complexity:
O(N) recursion stack

--------------------------------------------------------
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge2list(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(list1 && list2) {
            if(list1->data < list2->data) {
                Node* newNode = new Node(list1->data);
                res->bottom = newNode;
                res = newNode;
                list1 = list1->bottom;
            } else {
                Node* newNode = new Node(list2->data);
                res->bottom = newNode;
                res = newNode;
                list2 = list2->bottom;
            }
        }
        if(list1) res->bottom = list1;
        else res->bottom = list2;
        return dummyNode->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
        if(root == NULL || root->next == NULL) return root;
        Node* mergedHead = flatten(root->next);
        return merge2list(root, mergedHead);
    }
};


// Striver SDE Sheet Challenge - Day 12
