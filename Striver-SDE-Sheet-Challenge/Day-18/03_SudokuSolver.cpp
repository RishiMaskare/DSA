/*
========================================================
Problem: Sudoku Solver
========================================================

Intuition:
Fill empty cells while maintaining
Sudoku constraints.

--------------------------------------------------------
Approach:
1. Find an empty cell.
2. Try digits 1 to 9.
3. Validate row, column and grid.
4. Recurse further.
5. Backtrack if needed.

--------------------------------------------------------
Time Complexity:
Exponential

--------------------------------------------------------
Space Complexity:
O(81)

--------------------------------------------------------
*/

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        //horizontal
        for(int j=0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }
        //vertical
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }
        //grid
        int sr = (row/3)*3, sc = (col/3)*3;
        for(int i=sr;i<=sr+2;i++){
            for(int j=sc;j<=sc+2;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        if(row==9){
            return true;
        }
        int nextrow = row, nextcol = col+1;
        if(col==8){
            nextrow = row+1;
            nextcol = 0;
        }
        if(board[row][col]!='.'){
            return helper(board, nextrow, nextcol);
        }
        for(char dig='1';dig<='9';dig++){
            if(isSafe(board, row, col, dig)){
                board[row][col]=dig;
                if(helper(board, nextrow, nextcol)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

// Striver SDE Sheet Challenge - Day 18
