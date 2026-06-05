/*
========================================================
Problem: Pow(x, n)
========================================================

Intuition:
Multiplying x repeatedly takes O(N) time.

Using Binary Exponentiation:
- If n is even:
    xⁿ = (x²)ⁿ⁄²
- If n is odd:
    xⁿ = x × xⁿ⁻¹

This reduces complexity significantly.

--------------------------------------------------------
Approach:
1. Handle negative powers.
2. Use Binary Exponentiation.
3. If exponent is odd:
      Multiply answer by x.
4. If exponent is even:
      Square x and halve exponent.
5. Continue until exponent becomes 0.

--------------------------------------------------------
Time Complexity:
O(log N)

--------------------------------------------------------
Space Complexity:
O(1)

--------------------------------------------------------
*/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long m = n;

        if(n < 0) {
            m = -m;
            x = 1.0 / x;
        }

        while(m > 0) {
            if(m % 2 == 1) {
                ans *= x;
                m--;
            }
            else {
                x *= x;
                m /= 2;
            }
        }

        return ans;
    }
};

// Striver SDE Sheet Challenge - Day 5
