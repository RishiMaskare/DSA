/*
========================================================
Problem: Combination Sum II
========================================================

Intuition:
Generate unique combinations.

Sorting helps skip duplicates efficiently.

--------------------------------------------------------
Approach:
1. Sort the array.
2. Iterate from current index.
3. Skip duplicate values.
4. Pick current element once.
5. Continue recursion.

--------------------------------------------------------
Time Complexity:
Exponential

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    void f(int ind, int target, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates) {
    if(target == 0) {
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<candidates.size();i++) {
        if(i > ind && candidates[i] == candidates[i-1]) continue;

        if(candidates[i] > target) break;

        temp.push_back(candidates[i]);
        f(i + 1, target - candidates[i], temp, ans, candidates);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, target, temp, ans, candidates);
        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 17
