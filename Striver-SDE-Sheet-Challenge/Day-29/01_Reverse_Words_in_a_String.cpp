/*
=========================================================
Problem: Reverse Words in a String
Platform: LeetCode 151

Approach:
1. Reverse the entire string.
2. Traverse the reversed string and extract each word.
3. Reverse every extracted word individually.
4. Append non-empty words to the answer with a single space.
5. Remove the leading space before returning.

Time Complexity: O(N)
Space Complexity: O(N)

Concepts Used:
- Strings
- Two Pointers
- Reversal
=========================================================
*/

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {

            string word = "";

            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (!word.empty())
                ans += " " + word;
        }

        return ans.substr(1);
    }
};
