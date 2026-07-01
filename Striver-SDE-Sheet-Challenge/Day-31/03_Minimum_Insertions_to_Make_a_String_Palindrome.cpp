/*
=========================================================
Problem: Minimum Insertions to Make a String Palindrome
Platform: LeetCode 1312

Approach:
1. Reverse the string.
2. Find the Longest Common Subsequence (LCS) between
   the original and reversed string.
3. LCS gives the Longest Palindromic Subsequence (LPS).
4. Minimum insertions = Length - LPS.

Time Complexity: O(N²)
Space Complexity: O(N)

Concepts Used:
- Dynamic Programming
- Longest Common Subsequence (LCS)
- Longest Palindromic Subsequence (LPS)
=========================================================
*/

class Solution {
public:
    int lcs(string &s, string &t) {

        int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        return prev[m];
    }

    int longestPalindromeSubseq(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        return lcs(s, rev);
    }

    int minInsertions(string s) {

        int lps = longestPalindromeSubseq(s);

        return s.size() - lps;
    }
};
