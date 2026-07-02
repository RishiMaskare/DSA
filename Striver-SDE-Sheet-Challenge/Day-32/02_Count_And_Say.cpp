class Solution {
public:
    string helper(const string& prev) {
        string res = "";
        int start = 0;
        int i;
        // Process each group of consecutive characters
        for (i = 1; i < prev.size(); i++) {
            if (prev[i] != prev[i - 1]) {
                // Append count followed by the character
                res += to_string(i - start);
                res += prev[i - 1];
                start = i;
            }
        }

        // Process the last remaining group
        res += to_string(i - start);
        res += prev[i - 1];
        return res;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = "11";
        for (int i = 3; i <= n; i++) {
            prev = helper(prev);
        }
        return (n == 2) ? "11" : prev;
    }
};
