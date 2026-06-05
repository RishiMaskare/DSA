/*
========================================================
Problem: Majority Element II
========================================================

Intuition:
A majority element in this problem appears more than
⌊n/3⌋ times.

Using a hash map, we can count the frequency of every
element and collect those whose frequency exceeds n/3.

--------------------------------------------------------
Approach:
1. Traverse the array and store frequencies in a
   hash map.
2. Traverse the map.
3. If frequency > n/3, add the element to answer.
4. Return the answer vector.

--------------------------------------------------------
Time Complexity:
O(N)

Reason:
- One traversal for counting.
- One traversal of hash map.

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Hash map stores frequencies.

--------------------------------------------------------
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int val : nums)
            m[val]++;

        for(auto val : m) {
            if(val.second > nums.size() / 3)
                ans.push_back(val.first);
        }

        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 6
