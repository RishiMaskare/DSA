/*
========================================================
Problem: Two Sum
========================================================

Intuition:
For every element, we need another element such that:

nums[i] + nums[j] = target

Instead of searching the entire array every time,
store previously seen elements in a hash map.

For the current element:
required = target - current element

If required already exists in the map,
we have found the answer.

--------------------------------------------------------
Approach:
1. Traverse the array.
2. Compute required = target - nums[i].
3. Check if required exists in the hash map.
4. If found, return the indices.
5. Otherwise store the current element and its index.
6. Continue until the answer is found.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Hash map stores elements and their indices.

--------------------------------------------------------
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {

            int currVal = nums[i];
            int required = target - currVal;

            if(m.find(required) != m.end()) {
                return {i, m[required]};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};

// Striver SDE Sheet Challenge - Day 7
