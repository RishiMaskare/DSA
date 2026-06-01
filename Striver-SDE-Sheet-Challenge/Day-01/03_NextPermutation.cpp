/*
========================================================
Problem: Next Permutation
========================================================

Intuition:
To find the next lexicographically greater permutation,
we need to make the smallest possible increase in the
current arrangement.

Observations:
1. Starting from the right, the suffix is generally in
   decreasing order.
2. Find the first element that breaks this decreasing
   pattern. This is called the breakpoint.
3. To get the next greater permutation, swap the
   breakpoint with the smallest element greater than it
   on its right side.
4. The suffix is still in decreasing order, so reverse
   it to obtain the smallest possible arrangement.

Example:
1 2 3 -> 1 3 2

Breakpoint = 2
Swap with 3
Reverse suffix

--------------------------------------------------------
Approach:
1. Traverse from right to left and find the first index
   where nums[i-1] < nums[i].
   This index is the breakpoint.

2. If no breakpoint exists:
   - The array is in descending order.
   - Reverse the entire array and return.

3. Traverse from the end and find the first element
   greater than the breakpoint element.

4. Swap this element with the breakpoint element.

5. Reverse the portion after the breakpoint to obtain
   the next lexicographically smallest arrangement.

--------------------------------------------------------
Time Complexity:
O(N)

Reason:
- Finding breakpoint: O(N)
- Finding next greater element: O(N)
- Reversing suffix: O(N)

Overall: O(N)

--------------------------------------------------------
Space Complexity:
O(1)

Reason:
Only constant extra space is used.

--------------------------------------------------------
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), bptIdx = -1;

        // Find breakpoint
        for(int i = n - 1; i >= 1; i--) {
            if(nums[i - 1] < nums[i]) {
                bptIdx = i - 1;
                break;
            }
        }

        if(bptIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find rightmost element greater than breakpoint
        for(int i = n - 1; i > bptIdx; i--) {
            if(nums[i] > nums[bptIdx]) {
                swap(nums[i], nums[bptIdx]);
                break;
            }
        }

        reverse(nums.begin() + bptIdx + 1, nums.end());
    }
};
