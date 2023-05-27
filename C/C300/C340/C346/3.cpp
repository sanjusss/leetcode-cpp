#include "leetcode.h"

static vector<int> sums(1001);
static int init = []() {
    for (int i = 1; i <= 1000; ++i) {
        sums[i] = sums[i - 1];
        int t = i * i;
        vector<int> arr;
        for (int j = t; j > 0; j /= 10) {
            arr.push_back(j % 10);
        }

        reverse(arr.begin(), arr.end());
        int n = arr.size();
        vector<unordered_set<int>> dp(n + 1);
        dp[0].insert(0);
        for (int e = 1; e <= n; ++e) {
            int v = 0;
            int mul = 1;
            for (int b = e - 1; b >= 0; --b) {
                v += + arr[b] * mul;
                mul *= 10;
                for (int j : dp[b]) {
                    dp[e].insert(j + v);
                }
            }
        }

        if (dp[n].count(i)) {
            sums[i] += t;
        }
    }

    return 0;
} ();

class Solution {
public:
    int punishmentNumber(int n) {
        return sums[n];
    }
};

TEST(&Solution::punishmentNumber)