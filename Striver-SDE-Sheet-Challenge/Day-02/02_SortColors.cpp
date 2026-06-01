/*
========================================================
Problem: Sort Colors
========================================================

Intuition:
Since the array contains only 0s, 1s, and 2s,
comparison-based sorting is unnecessary.

We maintain three regions:
- 0s at the beginning
- 1s in the middle
- 2s at the end

Using three pointers, we place each element in its
correct region in a single traversal.

This algorithm is known as the Dutch National Flag
Algorithm.

--------------------------------------------------------
Approach:
1. Initialize:
   - low = 0
   - mid = 0
   - high = n - 1

2. Traverse while mid <= high:
   - If nums[mid] == 0:
       Swap nums[mid] and nums[low]
       Increment low and mid

   - If nums[mid] == 1:
       Increment mid

   - If nums[mid] == 2:
       Swap nums[mid] and nums[high]
       Decrement high

3. The array becomes sorted in one pass.

--------------------------------------------------------
Time Complexity:
O(N)

Reason:
Each element is processed at most once.

--------------------------------------------------------
Space Complexity:
O(1)

Reason:
Only three pointers are used.

--------------------------------------------------------
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Striver SDE Sheet Challenge - Day 2
