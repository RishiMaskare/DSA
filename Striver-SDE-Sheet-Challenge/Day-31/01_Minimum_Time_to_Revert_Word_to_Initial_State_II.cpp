/*
=========================================================
Problem: Minimum Time to Revert Word to Initial State II
Platform: LeetCode 3031

Approach:
1. Compute the KMP Prefix Function (LPS array).
2. Traverse the border lengths using the prefix array.
3. For every valid border, check whether the removed
   characters are a multiple of k.
4. Return the minimum number of operations.
5. If no valid border exists, return ceil(n / k).

Time Complexity: O(N)
Space Complexity: O(N)

Concepts Used:
- Strings
- KMP (Prefix Function / LPS)
- String Matching
=========================================================
*/

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {

        int n = word.size();
        vector<int> pi(n, 0);

        for (int i = 1; i < n; i++) {

            int j = pi[i - 1];

            while (j > 0 && word[i] != word[j])
                j = pi[j - 1];

            if (word[i] == word[j])
                j++;

            pi[i] = j;
        }

        int len = pi[n - 1];

        while (len > 0) {

            int removed = n - len;

            if (removed % k == 0)
                return removed / k;

            len = pi[len - 1];
        }

        return (n + k - 1) / k;
    }
};
