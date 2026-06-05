/*
========================================================
Problem: Unique Paths
========================================================

Intuition:
To reach a cell (i, j), we can come from:

1. Top cell (i-1, j)
2. Left cell (i, j-1)

Therefore:

paths(i, j) =
paths(i-1, j) + paths(i, j-1)

This is a classic Dynamic Programming problem.

This implementation uses Space Optimization,
reducing space from O(m*n) to O(n).

--------------------------------------------------------
Approach:
1. Maintain only the previous row.
2. Build the current row using:
   curr[j] = up + left
3. After processing a row,
   assign curr to prev.
4. Return the last cell.

--------------------------------------------------------
Time Complexity:
O(M × N)

Reason:
Every cell is processed once.

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Only two rows are stored at any time.

--------------------------------------------------------
*/

// Recursive Approach
class Solution {
public:
    int f(int i, int j) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        int left = f(i, j-1);
        int top = f(i-1, j);

        return top + left;
    }
    int uniquePaths(int m, int n) {
        return f(m-1, n-1);
    }
};

// Memoization
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp) {
        dp[0][0] = 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int left = f(i, j-1, dp);
        int top = f(i-1, j, dp);

        return dp[i][j] = top + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m-1, n-1, dp);
    }
};

// Tabulation 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 && j == 0) dp[0][0] = 1;
                else {
                    int up = 0, left = 0;
                    if(i-1 >= 0) up = dp[i-1][j];
                    if(j-1 >= 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// Space optimised version
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i=0;i<m;i++) {
            vector<int> curr(n, 0);
            for(int j=0;j<n;j++) {
                if(i == 0 && j == 0) curr[0] = 1;
                else {
                    int up = 0, left = 0;
                    if(i-1 >= 0) up = prev[j];
                    if(j-1 >= 0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
