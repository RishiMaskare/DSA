/*
=========================================================
Problem: Roman to Integer
Platform: LeetCode 13

Approach:
1. Store Roman numeral values in a hash map.
2. Traverse the string from left to right.
3. If the next numeral is larger than the current,
   subtract the current value.
4. Otherwise, add the current value.
5. Return the final integer.

Time Complexity: O(N)
Space Complexity: O(1)

Concepts Used:
- Hash Map
- Strings
=========================================================
*/

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.size(); i++) {

            if (i + 1 < s.size() &&
                roman[s[i + 1]] > roman[s[i]]) {

                result -= roman[s[i]];
            }
            else {
                result += roman[s[i]];
            }
        }

        return result;
    }
};
