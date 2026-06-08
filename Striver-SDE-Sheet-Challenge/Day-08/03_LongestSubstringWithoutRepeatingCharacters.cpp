/*
========================================================
Problem: Longest Substring Without Repeating Characters
========================================================

Intuition:
A valid substring cannot contain duplicate characters.

Using Sliding Window:
- Expand the window using the right pointer.
- If a duplicate character appears,
  move the left pointer appropriately.
- Maintain the maximum window length.

--------------------------------------------------------
Approach:
1. Maintain two pointers:
      left and right.
2. Store the latest index of every character.
3. When a duplicate appears inside the current window:
      Move left pointer.
4. Update maximum length.
5. Continue until the string is processed.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Hash map stores character indices.

--------------------------------------------------------
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        int r = 0;

        int maxlen = 0;

        unordered_map<char, int> m;

        while(r < s.size()) {

            if(m.find(s[r]) != m.end()) {

                if(m[s[r]] >= l) {
                    l = m[s[r]] + 1;
                }
            }

            maxlen = max(maxlen, r - l + 1);

            m[s[r]] = r;

            r++;
        }

        return maxlen;
    }
};

// Striver SDE Sheet Challenge - Day 8
