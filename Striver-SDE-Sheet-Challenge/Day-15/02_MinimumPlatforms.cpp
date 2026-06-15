/*
========================================================
Problem: Minimum Platforms
========================================================

Intuition:
Treat arrivals and departures as events.

--------------------------------------------------------
Approach:
1. Sort arrival and departure arrays.
2. Use two pointers.
3. Arrival before departure:
      Increase platform count.
4. Departure before arrival:
      Decrease platform count.
5. Track maximum count.

--------------------------------------------------------
Time Complexity:
O(N log N)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------
*/

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int cnt = 0, maxCnt = 0;
        int i = 0, j = 0;
        
        // i -> arr, j -> dep
        
        while(i < n) {
            if(arr[i] <= dep[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};


// Striver SDE Sheet Challenge - Day 15
