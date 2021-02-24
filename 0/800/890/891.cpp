#include "leetcode.h"

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        static const int64_t mod = 1e9 + 7;
        sort(A.begin(), A.end());
        int n = A.size();
        vector<int64_t> pow(n + 1);
        pow[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pow[i] = (pow[i - 1] * 2) % mod;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (pow[i] - pow[n - i - 1]) * A[i]) % mod;
        }

        return ans;
    }
};

TEST(&Solution::sumSubseqWidths)