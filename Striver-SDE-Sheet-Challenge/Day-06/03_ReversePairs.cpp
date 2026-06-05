/*
========================================================
Problem: Reverse Pairs
========================================================

Intuition:
A reverse pair is defined as:

i < j
arr[i] > 2 * arr[j]

Brute force checks every pair and takes O(N²).

Using Merge Sort, both halves become sorted.
This allows efficient counting of reverse pairs
before merging.

--------------------------------------------------------
Approach:
1. Divide the array using Merge Sort.
2. Recursively process left and right halves.
3. Before merging:
   Count reverse pairs using two pointers.
4. Merge the two sorted halves.
5. Return total reverse pairs.

--------------------------------------------------------
Time Complexity:
O(N log N)

Reason:
Merge Sort divides the array log N times
and processes N elements per level.

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Temporary array is used during merge.

--------------------------------------------------------
*/

class Solution {
public:

    int pairs = 0;

    void countReversePairs(vector<int>& arr,
                           int left,
                           int mid,
                           int right) {

        int j = mid + 1;

        for(int i = left; i <= mid; i++) {

            while(j <= right &&
                  (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }

            pairs += j - (mid + 1);
        }
    }

    void merge(vector<int>& arr,
               int left,
               int mid,
               int right) {

        vector<int> temp;

        int i = left;
        int j = mid;

        while(i <= mid - 1 && j <= right) {

            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
            }
        }

        while(i <= mid - 1)
            temp.push_back(arr[i++]);

        while(j <= right)
            temp.push_back(arr[j++]);

        for(int k = left; k <= right; k++)
            arr[k] = temp[k - left];
    }

    void mergeSort(vector<int>& arr,
                   int left,
                   int right) {

        if(left < right) {

            int mid = (left + right) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            countReversePairs(arr, left, mid, right);

            merge(arr, left, mid + 1, right);
        }
    }

    int reversePairs(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);

        return pairs;
    }
};

// Striver SDE Sheet Challenge - Day 6
