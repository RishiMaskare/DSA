/*
========================================================
Problem: Rotate Matrix by 90 Degrees
========================================================

Intuition:
A 90-degree clockwise rotation can be achieved in two
steps:

1. Transpose the matrix
   - Convert rows into columns.
2. Reverse every row
   - This produces the required clockwise rotation.

Example:

1 2 3        1 4 7        7 4 1
4 5 6  --->  2 5 8  --->  8 5 2
7 8 9        3 6 9        9 6 3

--------------------------------------------------------
Approach:
1. Traverse the upper triangular part of the matrix.
2. Swap matrix[i][j] with matrix[j][i] to transpose.
3. Reverse every row.
4. The matrix is now rotated by 90 degrees clockwise.

--------------------------------------------------------
Time Complexity:
O(N²)

Reason:
- Transpose: O(N²)
- Reverse each row: O(N²)

--------------------------------------------------------
Space Complexity:
O(1)

Reason:
Rotation is performed in-place.

--------------------------------------------------------
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(vector<int>& arr : matrix) {
            reverse(arr.begin(), arr.end());
        }
    }
};

// Striver SDE Sheet Challenge - Day 3
