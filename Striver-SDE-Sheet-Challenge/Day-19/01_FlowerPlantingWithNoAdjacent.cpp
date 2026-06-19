/*
========================================================
Problem: Flower Planting With No Adjacent
========================================================

Intuition:
Each garden has at most 3 neighbours.

Since 4 flower types are available,
a valid flower can always be assigned.

--------------------------------------------------------
Approach:
1. Build adjacency list.
2. For each garden:
      Mark neighbour flower types.
3. Choose first available flower.
4. Assign and continue.

--------------------------------------------------------
Time Complexity:
O(N + P)

N = Gardens
P = Paths

--------------------------------------------------------
Space Complexity:
O(N + P)

--------------------------------------------------------
*/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);

        for (auto &path : paths) {
            int u = path[0] - 1;
            int v = path[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> flower(n, 0);

        for (int garden = 0; garden < n; garden++) {

            bool used[5] = {false};

            for (int neighbour : adj[garden]) {
                if (flower[neighbour] != 0)
                    used[flower[neighbour]] = true;
            }

            for (int type = 1; type <= 4; type++) {
                if (!used[type]) {
                    flower[garden] = type;
                    break;
                }
            }
        }

        return flower;
    }
};

// Striver SDE Sheet Challenge - Day 19
