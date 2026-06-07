/*
========================================================
Problem: Four Sum
========================================================

Intuition:
A brute force solution checks all possible quadruplets,
resulting in O(N⁴) complexity.

After sorting:
- Fix the first two elements.
- Use Two Pointers for the remaining two elements.

This significantly reduces complexity.

--------------------------------------------------------
Approach:
1. Sort the array.
2. Fix first element using index i.
3. Fix second element using index j.
4. Use two pointers:
   - left = j + 1
   - right = n - 1
5. Compare current sum with target.
6. Skip duplicate values to avoid repeated answers.
7. Store valid quadruplets.

--------------------------------------------------------
Time Complexity:
O(N³)

Reason:
Two nested loops + Two Pointer traversal.

--------------------------------------------------------
Space Complexity:
O(1)

Ignoring answer storage.

--------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j < n; j++) {

                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long reqSum =
                    1LL * target - nums[i] - nums[j];

                int left = j + 1;
                int right = n - 1;

                while(left < right) {

                    long long pairSum =
                        1LL * nums[left] + nums[right];

                    if(pairSum == reqSum) {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        left++;
                        right--;

                        while(left < right &&
                              nums[left] == nums[left - 1])
                            left++;

                        while(left < right &&
                              nums[right] == nums[right + 1])
                            right--;
                    }
                    else if(pairSum > reqSum) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
        }

        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 7
