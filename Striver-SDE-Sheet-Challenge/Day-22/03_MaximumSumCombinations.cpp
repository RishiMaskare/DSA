/*
========================================================
Problem: Maximum Sum Combinations
========================================================

Intuition:
Largest sums are formed using the
largest elements of both arrays.

--------------------------------------------------------
Approach:
1. Sort both arrays descending.
2. Start with largest possible sum.
3. Use Max Heap to explore candidates.
4. Track visited pairs.
5. Extract top K sums.

--------------------------------------------------------
Time Complexity:
O(K log K)

--------------------------------------------------------
Space Complexity:
O(K)

--------------------------------------------------------
*/


class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        vis.insert({0, 0});

        vector<int> ans;
        while (k-- && !pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int sum = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            ans.push_back(sum);
            if (i + 1 < n && !vis.count({i + 1, j})) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }
            if (j + 1 < n && !vis.count({i, j + 1})) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }
        return ans;
  }
};


// Striver SDE Sheet Challenge - Day 20
