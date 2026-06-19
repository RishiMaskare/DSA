/*
========================================================
Problem: Rat In A Maze
========================================================

Intuition:
Explore all valid paths from source
to destination using backtracking.

--------------------------------------------------------
Approach:
1. Mark current cell as visited.
2. Explore:
      Down, Up, Left, Right.
3. Store path upon reaching destination.
4. Backtrack and unmark cell.

--------------------------------------------------------
Time Complexity:
O(4^(N*N))

--------------------------------------------------------
Space Complexity:
O(N*N)

--------------------------------------------------------
*/

class Solution {
  public:
    void helper(vector<vector<int>> &mat, int row, int col, string path, vector<string> &ans){
        int n = mat.size();
        if(row<0 || col<0 || row>=n || col>=n || mat[row][col] == 0 || mat[row][col] == -1){
            return;
        }
        if(row==n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
        mat[row][col] = -1;
        helper(mat, row+1, col, path+"D", ans);
        helper(mat, row-1, col, path+"U", ans);
        helper(mat, row, col-1, path+"L", ans);
        helper(mat, row, col+1, path+"R", ans);
        mat[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        
        int n = mat.size();
        vector<string> ans;
        string path = "";
        helper(mat, 0, 0, path, ans);
        return ans;
        
    }
};



// Striver SDE Sheet Challenge - Day 19
