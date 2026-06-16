/*
========================================================
Problem: Subset Sums
========================================================

Intuition:
Every element has two choices:
- Include
- Exclude

Generate all possible subset sums.

--------------------------------------------------------
Approach:
1. Recursively pick element.
2. Recursively skip element.
3. Store sum when subset ends.

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
    void f(vector<int>& temp, vector<int>& ans, vector<int>& arr, int ind) {
        if(ind < 0) {
            int sum = accumulate(temp.begin(), temp.end(), 0);
            ans.push_back(sum);
            return;
        }
        
        // pick
        temp.push_back(arr[ind]);
        f(temp, ans, arr, ind - 1);

        // not pick
        temp.pop_back();
        f(temp, ans, arr, ind - 1);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> temp, ans;
        f(temp, ans, arr, arr.size() - 1);
        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 16
