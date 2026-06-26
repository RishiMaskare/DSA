class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--) {
            while(!st.empty() && st.top() >= arr[i]) st.pop();
            
            if(!st.empty()) {
                ans[i] = st.top();
            } else ans[i] = -1;
            
            st.push(arr[i]);
        }
        return ans;
    }
};
