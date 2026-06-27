/*
=========================================================
Problem: Sliding Window Maximum
Platform: LeetCode 239
Difficulty: Hard

Approach:
1. Use a deque to store indices of useful elements.
2. Maintain the deque in decreasing order of values.
3. Remove indices that are outside the current window.
4. The front of the deque always contains the maximum element.
5. Store the maximum for every window.

Time Complexity: O(N)
Space Complexity: O(K)

Concepts Used:
- Sliding Window
- Monotonic Deque
=========================================================
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;

        // Process first window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Process remaining windows
        for (int i = k; i < nums.size(); i++) {

            // Maximum of previous window
            ans.push_back(nums[dq.front()]);

            // Remove indices outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Maximum of last window
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};
