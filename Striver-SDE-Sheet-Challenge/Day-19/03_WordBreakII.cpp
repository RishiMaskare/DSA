/*
========================================================
Problem: Word Break II
========================================================

Intuition:
Try every dictionary word as a prefix.

Memoization avoids recomputing
results for the same substring.

--------------------------------------------------------
Approach:
1. Store dictionary in hash set.
2. Generate valid prefixes.
3. Recursively solve remaining string.
4. Memoize substring results.
5. Construct all possible sentences.

--------------------------------------------------------
Time Complexity:
Exponential (optimized using DP)

--------------------------------------------------------
Space Complexity:
O(N + Output Size)

--------------------------------------------------------
*

class Solution {
public:
    unordered_set<string> dictSet;
    unordered_map<string, vector<string>> dp;

    vector<string> solve(string s) {
        if (dp.count(s))
            return dp[s];

        vector<string> ans;

        if (s.empty()) {
            ans.push_back("");
            return ans;
        }

        for (int i = 1; i <= s.length(); i++) {
            string word = s.substr(0, i);

            if (dictSet.count(word)) {
                string remaining = s.substr(i);

                vector<string> temp = solve(remaining);

                for (string sentence : temp) {
                    if (sentence.empty())
                        ans.push_back(word);
                    else
                        ans.push_back(word + " " + sentence);
                }
            }
        }

        return dp[s] = ans;
    }

    vector<string> wordBreak(vector<string>& dict, string s) {
        for (string word : dict)
            dictSet.insert(word);

        return solve(s);
    }
};

// Striver SDE Sheet Challenge - Day 19
