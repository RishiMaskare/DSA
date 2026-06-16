/*
========================================================
Problem: Subsets II
========================================================

Intuition:
Generate all subsets while avoiding duplicates.

--------------------------------------------------------
Approach:
1. Sort array.
2. Pick current element.
3. Skip duplicate elements when not picking.
4. Store unique subsets.

--------------------------------------------------------
Time Complexity:
O(2^N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& allSubsets, vector<int>& temp, int ind) {
        if(ind < 0) {
            allSubsets.push_back(temp);
            return;
        } 

        // pick
        temp.push_back(nums[ind]);
        f(nums, allSubsets, temp, ind-1);

        // not pick
        temp.pop_back();
        int idx = ind - 1;
        while(idx >= 0 && nums[idx] == nums[idx + 1]) idx--;
        f(nums, allSubsets, temp, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        f(nums, allSubsets, temp, nums.size() - 1);
        return allSubsets;
    }
};

// Striver SDE Sheet Challenge - Day 16
