/*
=========================================================
Problem: Find the Index of the First Occurrence in a String
Platform: LeetCode 28

Approach:
1. Use the built-in find() function.
2. It returns the first occurrence of the pattern.
3. If not found, it returns string::npos (-1).

Time Complexity: O(N × M) (implementation dependent)
Space Complexity: O(1)

Concepts Used:
- Strings
- Pattern Matching
=========================================================
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
