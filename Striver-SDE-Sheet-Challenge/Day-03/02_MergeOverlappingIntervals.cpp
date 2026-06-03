/*
========================================================
Problem: Merge Overlapping Intervals
========================================================

Intuition:
After sorting intervals according to their start time,
all overlapping intervals become adjacent.

If the current interval overlaps with the previous one,
merge them by extending the ending point.

--------------------------------------------------------
Approach:
1. Sort intervals based on starting time.
2. Initialize a temporary interval using the first
   interval.
3. Traverse the remaining intervals:
   - If overlap exists:
       Update ending point.
   - Otherwise:
       Store the current merged interval and start a
       new one.
4. Push the final interval into the answer.
5. Return the merged intervals.

--------------------------------------------------------
Time Complexity:
O(N log N)

Reason:
Sorting dominates the complexity.

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Answer vector stores merged intervals.

--------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 0)
            return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;
        vector<int> tempInterval = intervals[0];

        for(int i = 1; i < n; i++) {
            if(tempInterval[1] >= intervals[i][0]) {
                tempInterval[1] =
                    max(tempInterval[1], intervals[i][1]);
            }
            else {
                mergedIntervals.push_back(tempInterval);
                tempInterval = intervals[i];
            }
        }

        mergedIntervals.push_back(tempInterval);

        return mergedIntervals;
    }
};

// Striver SDE Sheet Challenge - Day 3
