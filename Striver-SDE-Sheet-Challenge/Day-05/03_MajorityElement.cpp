/*
========================================================
Problem: Majority Element
========================================================

Intuition:
A majority element appears more than n/2 times.

Using a Hash Map, we can count the frequency of every
element and identify the one whose count exceeds n/2.

--------------------------------------------------------
Approach:
1. Traverse the array.
2. Store frequencies using a hash map.
3. Traverse the map.
4. Return the element whose frequency is greater than
   n/2.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Hash map stores frequencies.

--------------------------------------------------------
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int val : nums)
            m[val]++;

        for(auto val : m) {
            if(val.second > nums.size() / 2)
                return val.first;
        }

        return -1;
    }
};

// Striver SDE Sheet Challenge - Day 5
