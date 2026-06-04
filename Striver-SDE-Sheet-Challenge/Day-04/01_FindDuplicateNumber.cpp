/*
========================================================
Problem: Find the Duplicate Number
========================================================

Intuition:
Treat the array as a linked list where:
index -> node
value -> next node

Since one number is duplicated, a cycle is formed.

Using Floyd's Cycle Detection Algorithm
(Tortoise and Hare), we can detect the cycle and find
its starting point, which corresponds to the duplicate
number.

--------------------------------------------------------
Approach:
1. Initialize slow and fast pointers.
2. Move:
   - slow by 1 step
   - fast by 2 steps
3. Find the meeting point.
4. Reset slow to the start.
5. Move both pointers one step at a time.
6. Their meeting point is the duplicate number.

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
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0], fast = arr[0];

        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while(slow != fast);

        slow = arr[0];

        while(slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};

// Striver SDE Sheet Challenge - Day 4
