/*
========================================================
Problem: Assign Cookies
========================================================

Intuition:
Satisfy children with the smallest possible
cookie that can fulfill their greed factor.

--------------------------------------------------------
Approach:
1. Sort greed factors.
2. Sort cookie sizes.
3. Use two pointers.
4. Assign cookie if it satisfies child.
5. Count satisfied children.

--------------------------------------------------------
Time Complexity:
O(N log N + M log M)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int children = 0, i = 0,  j = 0;
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                children++;
                i++; j++;
            } else {
                j++;
            }
        }
        return children;
    }
};

// Striver SDE Sheet Challenge - Day 16
