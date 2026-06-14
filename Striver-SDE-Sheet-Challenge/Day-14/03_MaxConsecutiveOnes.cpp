/*
========================================================
Problem: Max Consecutive Ones
========================================================

Intuition:
Track current streak of 1s.

--------------------------------------------------------
Approach:
1. Maintain count of consecutive 1s.
2. Reset when 0 appears.
3. Track maximum streak.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ans = 0, cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }

        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 14
