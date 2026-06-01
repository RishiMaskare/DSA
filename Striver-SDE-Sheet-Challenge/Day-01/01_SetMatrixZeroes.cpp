/*
========================================================
Problem: Set Matrix Zeroes
========================================================

Intuition:
If a cell contains 0, its entire row and column must
be converted to 0.

Instead of modifying the matrix immediately (which may
affect future checks), we first store all row indices
and column indices containing a 0. Later, we use this
information to update the matrix.

--------------------------------------------------------
Approach:
1. Traverse the matrix and store:
   - Row indices having a 0 in 'row'
   - Column indices having a 0 in 'col'

2. Create a temporary row filled with zeros.

3. For every row index in 'row', replace the entire row
   with the temporary zero row.

4. For every column index in 'col', set all elements
   in that column to 0.

--------------------------------------------------------
Time Complexity:
O(m * n)

Space Complexity:
O(m + n)

--------------------------------------------------------
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> row, col, temp(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int idx : row) {
            matrix[idx] = temp;
        }

        for(int idx : col) {
            for(int k = 0; k < m; k++) {
                matrix[k][idx] = 0;
            }
        }
    }
};
