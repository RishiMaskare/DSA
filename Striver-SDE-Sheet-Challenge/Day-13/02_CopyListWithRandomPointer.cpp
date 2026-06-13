/*
========================================================
Problem: Copy List With Random Pointer
========================================================

Intuition:
Create a mapping between original nodes
and copied nodes.

--------------------------------------------------------
Approach:
1. Create all copied nodes.
2. Store mapping in hash map.
3. Connect next pointers.
4. Assign random pointers using map.
5. Return copied list.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> m;
        Node* newHead = new Node(head->val);
        m[head] = newHead;
        Node* newTemp = newHead;
        Node* oldTemp = head->next;
        while(oldTemp) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        newTemp = newHead;
        oldTemp = head;
        while(newTemp) {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};
// Striver SDE Sheet Challenge - Day 13
