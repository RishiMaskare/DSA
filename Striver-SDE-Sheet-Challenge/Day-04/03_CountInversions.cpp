/*
========================================================
Problem: Count Inversions
========================================================

Intuition:
An inversion is a pair (i, j) such that:

i < j
arr[i] > arr[j]

Brute force checks all pairs and takes O(N²).

During Merge Sort, whenever an element from the
right half is placed before an element from the
left half, all remaining elements in the left half
form inversions.

This allows counting inversions efficiently.

--------------------------------------------------------
Approach:
1. Divide the array using Merge Sort.
2. Recursively count inversions in:
   - Left half
   - Right half
3. During merge:
   - If arr[i] > arr[j]
     then all elements from i to mid-1 form
     inversions.
4. Add all inversion counts and return.

--------------------------------------------------------
Time Complexity:
O(N log N)

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Temporary array used during merging.

--------------------------------------------------------
*/

class Solution {
public:

    long long merge(vector<int>& arr,
                    int left,
                    int mid,
                    int right) {

        vector<int> temp;

        int i = left;
        int j = mid;

        long long inv = 0;

        while(i <= mid - 1 && j <= right) {

            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
                inv += (mid - i);
            }
        }

        while(i <= mid - 1)
            temp.push_back(arr[i++]);

        while(j <= right)
            temp.push_back(arr[j++]);

        for(int k = left; k <= right; k++)
            arr[k] = temp[k - left];

        return inv;
    }

    long long mergeSort(vector<int>& arr,
                        int left,
                        int right) {

        long long inv = 0;

        if(left < right) {

            int mid = (left + right) / 2;

            inv += mergeSort(arr, left, mid);
            inv += mergeSort(arr, mid + 1, right);
            inv += merge(arr, left, mid + 1, right);
        }

        return inv;
    }

    long long inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

// Striver SDE Sheet Challenge - Day 4
