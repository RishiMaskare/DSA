// Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                else if(ch == ')' && st.top() == '('
                || ch == ']' && st.top() == '['
                || ch == '}' && st.top() == '{') {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};


// Next Greater Element
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        unordered_map<int, int> m; // {nums2[i], nextGreater}

        for(int i=nums2.size()-1;i>=0;i--) {
            while(!st.empty() && st.top() < nums2[i]) st.pop();

            if(st.empty()) m[nums2[i]] = -1;
            else m[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        for(int val: nums1) ans.push_back(m[val]);

        return ans;
    }
};


// Sort a Stack
class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        vector<int> temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.begin(), temp.end());
        for(int val : temp) st.push(val);
    }
};
