/*
=========================================================
Problem: Rotting Oranges
Platform: LeetCode 994
Difficulty: Medium

Approach:
1. Push all initially rotten oranges into a queue.
2. Count the total number of fresh oranges.
3. Perform Multi-Source BFS:
   - In each minute, rot all adjacent fresh oranges.
   - Keep track of the time taken.
4. Count how many fresh oranges become rotten.
5. If some fresh oranges remain unreachable, return -1.
6. Otherwise, return the total time required.

Time Complexity: O(M × N)
Space Complexity: O(M × N)

Concepts Used:
- Graph
- Breadth First Search (BFS)
- Multi-Source BFS
- Queue
=========================================================
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int freshCount = 0;
        int rottenFresh = 0;
        int totalTime = 0;

        // Store all rotten oranges and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                else if (grid[i][j] == 0) {
                    vis[i][j] = 1;
                }
                else {
                    freshCount++;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            totalTime = max(totalTime, time);

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc] &&
                    grid[nr][nc] == 1) {

                    vis[nr][nc] = 1;
                    rottenFresh++;

                    q.push({{nr, nc}, time + 1});
                }
            }
        }

        if (rottenFresh != freshCount)
            return -1;

        return totalTime;
    }
};
