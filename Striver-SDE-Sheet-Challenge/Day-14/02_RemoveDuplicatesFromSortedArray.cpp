/*
========================================================
Problem: Remove Duplicates from Sorted Array
========================================================

Intuition:
Use two pointers to overwrite duplicates in-place.

--------------------------------------------------------
Approach:
1. Maintain slow pointer i.
2. Iterate with j.
3. If nums[j] != nums[i], move i and update value.
4. Return i+1 as new length.

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
    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

// Striver SDE Sheet Challenge - Day 14
