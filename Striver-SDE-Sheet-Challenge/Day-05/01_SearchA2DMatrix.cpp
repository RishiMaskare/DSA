/*
========================================================
Problem: Search a 2D Matrix
========================================================

Intuition:
Since:
1. Each row is sorted.
2. First element of a row is greater than the last
   element of the previous row.

We can first identify the row that may contain the
target using Binary Search.

Then perform another Binary Search within that row.

--------------------------------------------------------
Approach:
1. Binary search on rows.
2. Find the row whose range contains target.
3. Perform binary search on that row.
4. Return true if target is found.

--------------------------------------------------------
Time Complexity:
O(log M + log N)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------
*/

class Solution {
public:
    bool searchRow(vector<int>& row, int target) {
        int st = 0, end = row.size() - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(row[mid] == target)
                return true;
            else if(row[mid] > target)
                end = mid - 1;
            else
                st = mid + 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, end = m - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(matrix[mid][0] <= target &&
               target <= matrix[mid][n - 1]) {

                return searchRow(matrix[mid], target);
            }
            else if(matrix[mid][0] >= target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return false;
    }
};

// Striver SDE Sheet Challenge - Day 5
