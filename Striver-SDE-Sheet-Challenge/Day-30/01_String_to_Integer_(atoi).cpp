/*
=========================================================
Problem: String to Integer (atoi)
Platform: LeetCode 8

Approach:
1. Ignore leading whitespaces.
2. Check for an optional '+' or '-' sign.
3. Convert consecutive digits into an integer.
4. Stop when a non-digit character is encountered.
5. Handle integer overflow using INT_MAX and INT_MIN.

Time Complexity: O(N)
Space Complexity: O(1)

Concepts Used:
- String Parsing
- Overflow Handling
=========================================================
*/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        bool neg = false;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                neg = true;
            i++;
        }

        long long ans = 0;

        for (int j = i; j < n; j++) {

            if (!isdigit(s[j]))
                break;

            ans = ans * 10 + (s[j] - '0');

            if (!neg && ans > INT_MAX)
                return INT_MAX;

            if (neg && -ans < INT_MIN)
                return INT_MIN;
        }

        return neg ? -ans : ans;
    }
};
