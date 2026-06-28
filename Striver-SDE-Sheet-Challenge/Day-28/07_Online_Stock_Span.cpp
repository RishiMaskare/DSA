/*
=========================================================
Problem: Online Stock Span
Platform: LeetCode 901

Approach:
1. Maintain a monotonic decreasing stack of
   {stock price, span}.
2. While the current price is greater than or equal to
   the top price, merge their spans.
3. Push the current price along with its calculated span.
4. Return the span.

Time Complexity: O(1) Amortized
Space Complexity: O(N)

Concepts Used:
- Stack
- Monotonic Stack
=========================================================
*/

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {

    }

    int next(int price) {

        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};
