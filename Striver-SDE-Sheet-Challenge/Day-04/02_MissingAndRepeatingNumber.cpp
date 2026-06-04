/*
========================================================
Problem: Missing and Repeating Number
========================================================

Intuition:
If one number repeats and another is missing,
the actual array sum differs from the expected sum
of numbers from 1 to N.

Using a hash set, we can identify the repeating
number directly.

Once the repeating number is known:

Missing Number =
Expected Sum + Repeating Number - Actual Sum

--------------------------------------------------------
Approach:
1. Traverse the array.
2. Use a hash set to find the repeating number.
3. Compute actual sum of array elements.
4. Compute expected sum from 1 to N.
5. Calculate the missing number.
6. Return {repeating, missing}.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Hash set stores up to N elements.

--------------------------------------------------------
*/

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2);

        unordered_set<int> s;

        int repeating = 0;
        int missing = 0;

        long long actualsum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            actualsum += arr[i];

            if(s.find(arr[i]) != s.end()) {
                repeating = arr[i];
            }

            s.insert(arr[i]);
        }

        long long expsum = (long long)n * (n + 1) / 2;

        missing = expsum + repeating - actualsum;

        ans[0] = repeating;
        ans[1] = missing;

        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 4
