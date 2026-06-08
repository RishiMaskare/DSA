/*
========================================================
Problem: Longest Subarray With Sum K
========================================================

Intuition:
Using Prefix Sum, we can efficiently determine whether
a subarray with sum K exists.

If:

prefixSum[i] - prefixSum[j] = K

Then:

prefixSum[j] = prefixSum[i] - K

A hash map stores the first occurrence of every
prefix sum, allowing us to maximize the subarray length.

--------------------------------------------------------
Approach:
1. Maintain a running prefix sum.
2. If prefixSum equals K:
      Update maximum length.
3. Check whether
      prefixSum - K
   exists in the hash map.
4. If found, update answer.
5. Store the first occurrence of every prefix sum.
6. Return maximum length.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        int n = arr.size();

        int prefixSum = 0;
        int maxLen = 0;

        unordered_map<int, int> m;

        for(int i = 0; i < n; i++) {

            prefixSum += arr[i];

            if(prefixSum == k)
                maxLen = i + 1;

            if(m.find(prefixSum - k) != m.end()) {
                maxLen = max(
                    maxLen,
                    i - m[prefixSum - k]
                );
            }

            if(m.find(prefixSum) == m.end())
                m[prefixSum] = i;
        }

        return maxLen;
    }
};

// Striver SDE Sheet Challenge - Day 8
