/*
========================================================
Problem: Merge Sorted Array
========================================================

Intuition:
Since nums1 has extra space at the end, we can fill the
array from the back.

At each step:
- Compare the largest remaining elements of nums1 and
  nums2.
- Place the larger element at the last available
  position.

This prevents overwriting useful elements in nums1.

--------------------------------------------------------
Approach:
1. Initialize:
   - i = m - 1
   - j = n - 1
   - ind = m + n - 1

2. Compare nums1[i] and nums2[j]:
   - Place the larger value at nums1[ind].
   - Move corresponding pointer.

3. If elements remain in nums2,
   copy them into nums1.

4. nums1 now contains the merged sorted array.

--------------------------------------------------------
Time Complexity:
O(m + n)

Reason:
Each element is processed once.

--------------------------------------------------------
Space Complexity:
O(1)

Reason:
Merging is performed in-place.

--------------------------------------------------------
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        int ind = m + n - 1;
        int i = m - 1;
        int j = n - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[ind] = nums1[i];
                i--;
            }
            else {
                nums1[ind] = nums2[j];
                j--;
            }
            ind--;
        }

        while(j >= 0) {
            nums1[ind] = nums2[j];
            j--;
            ind--;
        }
    }
};

// Striver SDE Sheet Challenge - Day 3
