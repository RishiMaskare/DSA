/*
========================================================
Problem: Best Time to Buy and Sell Stock
========================================================

Intuition:
To maximize profit, we should buy at the lowest price
seen so far and sell at the current price.

For every day:
- Treat the current price as a possible selling price.
- Use the minimum price encountered before it as the
  buying price.

Keep track of the maximum profit obtained.

--------------------------------------------------------
Approach:
1. Initialize bestBuy as the first day's price.
2. Traverse the array:
   - If current price is smaller than bestBuy,
     update bestBuy.
   - Otherwise, calculate profit:
       current price - bestBuy
   - Update maximum profit if needed.
3. Return the maximum profit.

--------------------------------------------------------
Time Complexity:
O(N)

Reason:
Single traversal of the array.

--------------------------------------------------------
Space Complexity:
O(1)

Reason:
Only constant extra space is used.

--------------------------------------------------------
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < bestBuy) {
                bestBuy = prices[i];
            }
            else {
                maxProfit = max(maxProfit,
                                prices[i] - bestBuy);
            }
        }

        return maxProfit;
    }
};

// Striver SDE Sheet Challenge - Day 2
