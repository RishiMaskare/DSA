/*
========================================================
Problem: Kth Largest Element
========================================================

Intuition:
A Max Heap always keeps the largest
element at the top.

--------------------------------------------------------
Approach:
1. Build max heap.
2. Remove largest element k-1 times.
3. Top element becomes kth largest.

--------------------------------------------------------
Time Complexity:
O(N + K log N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while(--k) {
            pq.pop();
        }
        return pq.top();
    }
};

// Striver SDE Sheet Challenge - Day 20
