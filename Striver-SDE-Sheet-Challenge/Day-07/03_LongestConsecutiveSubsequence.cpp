/*
========================================================
Problem: Longest Consecutive Subsequence
========================================================

Intuition:
Using sorting gives O(N log N).

A better approach is to use a hash set.

For every number:
- If (number - 1) is not present,
  then this number starts a sequence.
- Continue counting consecutive elements.

This ensures every sequence is processed only once.

--------------------------------------------------------
Approach:
1. Insert all elements into a hash set.
2. Traverse the array.
3. If (val - 1) does not exist:
   - Start a new sequence.
   - Count consecutive elements.
4. Update the maximum length.
5. Return the answer.

--------------------------------------------------------
Time Complexity:
O(N)

Reason:
Each element is visited at most once.

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Hash set stores all elements.

--------------------------------------------------------
*/

class Solution {
public:

    int longestConsecutive(vector<int>& arr) {

        int ans = 0;

        unordered_set<int> st(arr.begin(), arr.end());

        for(int val : arr) {

            if(st.find(val - 1) == st.end()) {

                int curr = val;
                int count = 0;

                while(st.find(curr) != st.end()) {
                    count++;
                    curr++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 7
