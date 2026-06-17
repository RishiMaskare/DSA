/*
========================================================
Problem: Palindrome Partitioning II
========================================================

Intuition:
Try every possible palindrome partition
and choose the minimum cuts.

--------------------------------------------------------
Approach:
1. Check palindrome substrings.
2. Recursively partition remaining string.
3. Use memoization to avoid recomputation.
4. Return minimum cuts needed.

--------------------------------------------------------
Time Complexity:
O(N^3)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

// User function Template for C++

class Solution {
  public:
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, string &s, vector<int> &dp) {
        int n = s.size();

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = 1e9;

        for(int j=i;j<n;j++) {
            if(isPalindrome(s, i, j)) {
                int cost = 1 + f(j + 1, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    int palPartition(string &s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, s, dp) - 1;
    }
};

// Striver SDE Sheet Challenge - Day 17
