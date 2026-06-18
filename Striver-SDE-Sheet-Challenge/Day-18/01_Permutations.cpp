/*
========================================================
Problem: Permutations
========================================================

Intuition:
Fix one position at a time and generate
all possible arrangements.

--------------------------------------------------------
Approach:
1. Swap current element with every choice.
2. Recurse for remaining positions.
3. Backtrack by swapping back.

--------------------------------------------------------
Time Complexity:
O(N × N!)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back({nums});
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx], nums[i]);
            getPerms(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 18
