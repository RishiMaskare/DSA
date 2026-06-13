class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> triplets;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int target = -nums[i];
            int st = i+1, end = n-1;
            while(st < end) {
                int ps = nums[st] + nums[end];
                if(ps == target) {
                    triplets.insert({nums[i], nums[st], nums[end]});
                    st++; end--;
                } else if(ps > target) {
                    end--;
                } else {
                    st++;
                }
            }
        }
        vector<vector<int>> ans(triplets.begin(), triplets.end());
        return ans;
    }
};
