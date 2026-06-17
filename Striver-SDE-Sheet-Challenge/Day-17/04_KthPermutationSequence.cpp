/*
========================================================
Problem: K-th Permutation Sequence
========================================================

Intuition:
Instead of generating all permutations,
directly determine each digit using factorials.

--------------------------------------------------------
Approach:
1. Compute factorial blocks.
2. Determine index of next digit.
3. Remove chosen digit.
4. Update k and repeat.

--------------------------------------------------------
Time Complexity:
O(N^2)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        for(int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }

        nums.push_back(n);
        k--; 
        string ans = "";

        while(true) {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact));
            if(nums.size() == 0) break;
            k %= fact;
            fact /= nums.size();
        }
        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 17
