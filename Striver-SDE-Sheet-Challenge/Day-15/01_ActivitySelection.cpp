/*
========================================================
Problem: Activity Selection
========================================================

Intuition:
Choose activities that finish earliest
to maximize the total number selected.

--------------------------------------------------------
Approach:
1. Store activities as (start, end).
2. Sort by ending time.
3. Select first activity.
4. Pick next activity only if it starts
   after the previously selected one ends.

--------------------------------------------------------
Time Complexity:
O(N log N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Arr {
    public: 
    int st, end;
    Arr(int s, int e) {
        st = s;
        end = e;
    }
};

bool comparator(Arr val1, Arr val2) {
    return val1.end < val2.end;
}

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<Arr> span;
        for(int i=0;i<n;i++) {
            span.push_back(Arr(start[i], finish[i]));
        }
        sort(span.begin(), span.end(), comparator);
        int tasks = 1, endTime = span[0].end;
        for(int i=1;i<n;i++) {
            if(span[i].st > endTime) {
                tasks++;
                endTime = span[i].end;
            }
        }
        return tasks;
    }
};

// Striver SDE Sheet Challenge - Day 15
