/*
========================================================
Problem: Combination Sum
========================================================

Intuition:
Each element can be taken multiple times.

Use Pick / Not Pick recursion
to generate valid combinations.

--------------------------------------------------------
Approach:
1. Pick current element.
2. Stay at same index since reuse is allowed.
3. Skip current element.
4. Store combination when target becomes 0.

--------------------------------------------------------
Time Complexity:
Exponential

--------------------------------------------------------
Space Complexity:
O(Target)

--------------------------------------------------------
*/

class Solution {
public:
    set<vector<int>> s;
    void f(vector<int>& candidates, int target, vector<int>& temp,
    vector<vector<int>>& ans, int ind) {
        if(target < 0 || ind == candidates.size()) {
            return;
        }
        if(target == 0) {
            if(s.find(temp) == s.end()) {
                ans.push_back(temp);
                s.insert(temp);
            }
        }

        // pick
        temp.push_back(candidates[ind]);
        f(candidates, target - candidates[ind], temp, ans, ind);
        f(candidates, target - candidates[ind], temp, ans, ind + 1);

        // not pick
        temp.pop_back();
        f(candidates, target, temp, ans, ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates, target, temp, ans, 0);
        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 17
