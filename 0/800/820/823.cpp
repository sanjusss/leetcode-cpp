#include "leetcode.h"

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        static constexpr int64_t mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, int64_t> dp;
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int64_t& cur = dp[arr[i]];
            cur = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j])) {
                    cur += dp[arr[j]] * dp[arr[i] / arr[j]];
                    cur %= mod;
                }
            }

            ans += cur;
            ans %= mod;
        }

        return ans;
    }
};

TEST(&Solution::numFactoredBinaryTrees)