/*
=========================================================
Problem: Maximum of Minimums for Every Window Size


Approach:
1. Find the Previous Smaller Element (PSE).
2. Find the Next Smaller Element (NSE).
3. For every element, determine the window length in
   which it is the minimum.
4. Update the answer for that window length.
5. Fill unanswered window sizes from right to left.

Time Complexity: O(N)
Space Complexity: O(N)

Concepts Used:
- Monotonic Stack
- Previous Smaller Element
- Next Smaller Element
=========================================================
*/

class Solution {
public:
    vector<int> maxOfMin(vector<int>& arr) {

        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> ans(n + 1, INT_MIN);

        for (int i = 0; i < n; i++) {

            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }

        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        vector<int> res;

        for (int i = 1; i <= n; i++)
            res.push_back(ans[i]);

        return res;
    }
};
