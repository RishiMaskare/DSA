/*
========================================================
Problem: Coin Change
========================================================

Intuition:
For every coin:
- Take it
- Or skip it

Choose the minimum coins needed.

--------------------------------------------------------
Approach:
1. Use recursion + memoization.
2. Try taking current coin.
3. Try not taking current coin.
4. Store results in DP table.

--------------------------------------------------------
Time Complexity:
O(N × Amount)

--------------------------------------------------------
Space Complexity:
O(N × Amount)

--------------------------------------------------------
*/


class Solution {
public:
    int f(vector<int>& coins, int tar, int ind, vector<vector<int>>& dp) {
        if(ind == 0) {
            if(tar % coins[ind]) return 1e9;
            else return tar / coins[ind];
        }

        if(dp[ind][tar] != -1) return dp[ind][tar];

        int notTake = f(coins, tar, ind-1, dp);
        int take = 1e9;
        if(coins[ind] <= tar) {
            take = 1 + f(coins, tar - coins[ind], ind, dp);
        }
        return dp[ind][tar] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = f(coins, amount, n-1, dp);
        return ans == 1e9 ? -1 : ans;
    }
};


// Striver SDE Sheet Challenge - Day 16
