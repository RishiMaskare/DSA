/*
=========================================================
Problem: Repeated String Match
Platform: LeetCode 686

Approach:
1. Keep appending string 'a'.
2. After every append, check if 'b' is a substring.
3. At most (|b| / |a| + 2) repetitions are required.
4. Return the number of repetitions if found,
   otherwise return -1.

Time Complexity: O((N + M) × K)
Space Complexity: O(N + M)

Concepts Used:
- Strings
- Substring Search
=========================================================
*/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string temp = a;

        int limit = b.size() / a.size() + 2;
        int count = 1;

        while (count <= limit) {

            if (temp.find(b) != string::npos)
                return count;

            temp += a;
            count++;
        }

        return -1;
    }
};
