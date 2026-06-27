/*
=========================================================
Problem: Min Stack
Platform: LeetCode 155
Difficulty: Medium

Approach:
1. Store a pair in the stack:
      {value, minimum_so_far}
2. While pushing:
      - If stack is empty, current value is the minimum.
      - Otherwise, minimum = min(current value, previous minimum).
3. Top element stores both the value and the minimum up to that point.
4. getMin() becomes an O(1) operation.

Time Complexity:
- push()   : O(1)
- pop()    : O(1)
- top()    : O(1)
- getMin() : O(1)

Space Complexity: O(N)

Concepts Used:
- Stack
- Pair
- Constant Time Minimum Retrieval
=========================================================
*/

class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {

    }

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
