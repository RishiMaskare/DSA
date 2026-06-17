/*
========================================================
Problem: Palindrome Partitioning II
========================================================

Intuition:
Try every possible palindrome partition
and choose the minimum cuts.

--------------------------------------------------------
Approach:
1. Check palindrome substrings.
2. Recursively partition remaining string.
3. Use memoization to avoid recomputation.
4. Return minimum cuts needed.

--------------------------------------------------------
Time Complexity:
O(N^3)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

// Striver SDE Sheet Challenge - Day 17
