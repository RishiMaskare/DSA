/*
=========================================================
Problem: Longest Common Prefix
Platform: LeetCode 14

Approach:
1. Assume the first string is the answer.
2. Compare it with every other string.
3. Keep removing the last character until it becomes
   a prefix of the current string.
4. Return the remaining prefix.

Time Complexity: O(N × M)
where M is the prefix length.

Space Complexity: O(1)

Concepts Used:
- Strings
- Prefix Matching
=========================================================
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            while (strs[i].find(ans) != 0)
                ans.pop_back();

            if (ans.empty())
                return "";
        }

        return ans;
    }
};
