/*
========================================================
Problem: Pascal's Triangle
========================================================

Intuition:
Each row of Pascal's Triangle starts and ends with 1.

For every other element, its value is obtained by
adding the two elements directly above it from the
previous row.

Example:

      1
     1 1
    1 2 1
   1 3 3 1

Here,
2 = 1 + 1
3 = 1 + 2
3 = 2 + 1

--------------------------------------------------------
Approach:
1. Create an answer vector of size numRows.
2. Initialize the first row as {1}.
3. For each row i:
   - Create a row of size (i + 1).
   - Set first and last elements to 1.
   - Fill the middle elements using:
     current[j] = previous[j-1] + previous[j]
4. Store the generated row in the answer vector.
5. Return the complete triangle.

--------------------------------------------------------
Time Complexity:
O(numRows²)

Reason:
Total elements generated are
1 + 2 + 3 + ... + numRows
= O(numRows²)

--------------------------------------------------------
Space Complexity:
O(numRows²)

Reason:
The entire Pascal's Triangle is stored in the answer
vector.

--------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        ans[0] = {1};

        for(int i = 1; i < numRows; i++) {
            vector<int> temp(i + 1);

            temp[0] = 1;
            temp[i] = 1;

            for(int j = 1; j < i; j++) {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans[i] = temp;
        }

        return ans;
    }
};
