/*
========================================================
Problem: N-Queens
========================================================

Intuition:
Place queens row by row while ensuring
no queen attacks another.

--------------------------------------------------------
Approach:
1. Try placing queen in every column.
2. Check row, column and diagonals.
3. Recurse for next row.
4. Remove queen while backtracking.

--------------------------------------------------------
Time Complexity:
O(N!)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left diagonal
        for(int i=row, j=col;i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //right diagonal
        for(int i=row, j=col; i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<string>& board, int row, int n,
                 vector<vector<string>>& ans) {
        if (n == row) {
            ans.push_back({board});
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);
        return ans;
    }
};


// Striver SDE Sheet Challenge - Day 18
