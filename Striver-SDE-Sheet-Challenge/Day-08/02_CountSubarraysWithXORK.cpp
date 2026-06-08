/*
========================================================
Problem: Count Subarrays With Given XOR K
========================================================

Intuition:
For Prefix XOR:

prefixXor[i] ^ prefixXor[j] = K

Therefore:

prefixXor[j] = prefixXor[i] ^ K

A hash map stores frequencies of prefix XOR values,
allowing us to count valid subarrays efficiently.

--------------------------------------------------------
Approach:
1. Maintain running XOR.
2. If current XOR equals K:
      Increment count.
3. Check if
      currentXOR ^ K
   exists in the map.
4. Add its frequency to answer.
5. Store current XOR frequency.
6. Return total count.

--------------------------------------------------------
Time Complexity:
O(N)

--------------------------------------------------------
Space Complexity:
O(N)

--------------------------------------------------------
*/

class Solution {
public:
    long subarrayXor(vector<int>& arr, int k) {

        unordered_map<int, int> m;

        int Xor = 0;

        long count = 0;

        for(int i = 0; i < arr.size(); i++) {

            Xor ^= arr[i];

            if(Xor == k)
                count++;

            if(m.find(Xor ^ k) != m.end()) {
                count += m[Xor ^ k];
            }

            m[Xor]++;
        }

        return count;
    }
};

// Striver SDE Sheet Challenge - Day 8
