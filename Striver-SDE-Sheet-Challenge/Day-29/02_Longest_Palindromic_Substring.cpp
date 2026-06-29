/*
=========================================================
Problem: Longest Palindromic Substring
Platform: LeetCode 5

Approach:
1. Treat every index as the center of a palindrome.
2. Expand around the center for:
   - Odd length palindrome
   - Even length palindrome
3. Keep track of the longest palindrome found.
4. Return the longest substring.

Time Complexity: O(N²)
Space Complexity: O(1)

Concepts Used:
- Strings
- Two Pointers
- Expand Around Center
=========================================================
*/

class Solution {
public:
    int start = 0;
    int maxLen = 0;

    void expand(string &s, int left, int right) {

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        int len = right - left - 1;

        if (len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    }

    string longestPalindrome(string s) {

        for (int i = 0; i < s.size(); i++) {

            expand(s, i, i);       // Odd length
            expand(s, i, i + 1);   // Even length
        }

        return s.substr(start, maxLen);
    }
};
