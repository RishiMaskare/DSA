/*
========================================================
Problem: Maximum Subarray
========================================================

Intuition:
A negative running sum can never help in forming a
larger subarray sum in the future.

For every element, we decide:
1. Start a new subarray from the current element.
2. Extend the existing subarray.

We choose whichever gives a larger sum.

This idea is known as Kadane's Algorithm.

--------------------------------------------------------
Approach:
1. Maintain a running sum (currSum).
2. For each element:
   - Add it to currSum.
   - If the current element itself is greater than
     currSum, start a new subarray from it.
3. Update the maximum sum seen so far.
4. Return the maximum sum.

--------------------------------------------------------
Time Complexity:
O(N)

Reason:
Single traversal of the array.

--------------------------------------------------------
Space Complexity:
O(1)

Reason:
Only constant extra space is used.

--------------------------------------------------------
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for(int val : nums) {
            currSum += val;

            if(val > currSum)
                currSum = val;

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

// Striver SDE Sheet Challenge - Day 2
