/*
=========================================================
Problem: The Celebrity Problem
Platform: GeeksforGeeks
Difficulty: Medium

Approach:
1. Push all people into a stack.
2. Compare the top two people:
   - If A knows B, A cannot be the celebrity.
   - Otherwise, B cannot be the celebrity.
3. Continue until one candidate remains.
4. Verify the candidate:
   - Celebrity knows nobody.
   - Everyone knows the celebrity.
5. Return the celebrity index or -1.

Time Complexity: O(N)
Space Complexity: O(N)

Concepts Used:
- Stack
- Elimination Technique
=========================================================
*/

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1) {

            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (mat[a][b] == 0)
                st.push(a);
            else
                st.push(b);
        }

        int candidate = st.top();

        for (int i = 0; i < n; i++) {

            if (i != candidate &&
                (mat[i][candidate] == 0 || mat[candidate][i] == 1))
                return -1;
        }

        return candidate;
    }
};
