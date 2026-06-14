/*
========================================================
Problem: Trapping Rain Water
========================================================

Intuition:
Water trapped at index depends on:
min(left max, right max) - height[i]

--------------------------------------------------------
Approach:
1. Precompute leftMax array.
2. Precompute rightMax array.
3. For each index, calculate trapped water.
4. Sum all contributions.

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
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        int water = 0;

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};

// Striver SDE Sheet Challenge - Day 14
