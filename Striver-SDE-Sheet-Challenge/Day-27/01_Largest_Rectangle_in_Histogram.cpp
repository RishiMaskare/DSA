/*
=========================================
Problem: Largest Rectangle in Histogram

Approach:
1. Find the Next Smaller Element (NSE) for every index.
2. Find the Previous Smaller Element (PSE) for every index.
3. The width of rectangle using current bar as minimum height:
       width = NSE - PSE - 1
4. Area = height * width
5. Return the maximum area.

Time Complexity: O(N)
Space Complexity: O(N)

Concepts Used:
- Monotonic Stack
- Previous Smaller Element
- Next Smaller Element
=========================================
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
