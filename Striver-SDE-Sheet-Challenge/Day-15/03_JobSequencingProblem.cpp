/*
========================================================
Problem: Job Sequencing Problem
========================================================

Intuition:
Perform highest profit jobs first.

--------------------------------------------------------
Approach:
1. Sort jobs by profit descending.
2. Find latest available slot before deadline.
3. Schedule job if slot exists.
4. Use Disjoint Set Union (DSU)
   for efficient slot management.

--------------------------------------------------------
Time Complexity:
O(N log N)

--------------------------------------------------------
Space Complexity:
O(MaxDeadline)

--------------------------------------------------------
*/
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int, int>> jobs;
        int n = deadline.size(), md = -1, totProfit = 0, cnt = 0;
        for(int i=0;i<n;i++) {
            jobs.push_back({profit[i], deadline[i]});
            md = max(md, deadline[i]);
        }
        sort(jobs.rbegin(), jobs.rend());
        vector<int> hash(md + 1, -1);
        for(int i=0;i<n;i++) {
            int p = jobs[i].first;
            int d = jobs[i].second;
            for(int j=d;j>0;j--) {
                if(hash[j] == -1) {
                    cnt++;
                    totProfit += p;
                    hash[j] = 1;
                    break;
                }
            }
        }
        return {cnt, totProfit};
    }
};


class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size(), md = 0;
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;i++) {
            jobs.push_back({profit[i], deadline[i]});
            md = max(md, deadline[i]);
        }
        sort(jobs.rbegin(), jobs.rend());
        
        parent.resize(md+1);
        for(int i=0;i<=md;i++) parent[i] = i;
        
        int cnt = 0, totProfit = 0;
        for(int i=0;i<n;i++) {
            int p = jobs[i].first;
            int d = jobs[i].second;
            int avail = find(d);
            if(avail > 0) {
                cnt++;
                totProfit += p;
                parent[avail] = avail - 1;
            }
        }
        return {cnt, totProfit};
    }
};

// Striver SDE Sheet Challenge - Day 15
