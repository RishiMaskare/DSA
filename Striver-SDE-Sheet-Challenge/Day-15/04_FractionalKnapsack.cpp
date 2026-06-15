/*
========================================================
Problem: Fractional Knapsack
========================================================

Intuition:
Take items with highest value/weight ratio first.

--------------------------------------------------------
Approach:
1. Compute value/weight ratio.
2. Sort ratios descending.
3. Take complete items whenever possible.
4. Take fraction of last item if needed.

--------------------------------------------------------
Time Complexity:
O(N log N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double totalVal = 0.0; int w = capacity;
        vector<pair<double, int>> ratio; // p/w, index
        for(int i=0;i<val.size();i++) {
            double r = (double)val[i] / wt[i];
            ratio.push_back({r, i});
        }
        sort(ratio.rbegin(), ratio.rend()); // reverse order - Descending
        for(int i=0;i<ratio.size();i++) {
            int idx = ratio[i].second;
            if(w >= wt[idx]) {
                totalVal += val[idx];
                w -= wt[idx];
            } else {
                totalVal += ratio[i].first * w;
                break;
            }
        }
        return totalVal;
    }
};


// Striver SDE Sheet Challenge - Day 15
