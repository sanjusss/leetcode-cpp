/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-30 11:51:22
 * @FilePath: \C\C300\C350\C356\4.cpp
 */
#include "leetcode.h"

static constexpr int mod = 1e9 + 7;
static vector<vector<int>> bit2cnt;
static vector<vector<int>> sums;
static int init = []() {
    bit2cnt = vector<vector<int>>(100, vector<int>(10));
    sums = vector<vector<int>>(100, vector<int>(10));
    for (int j = 0; j < 10; ++j) {
        bit2cnt[0][j] = 1;
        sums[0][j] = j;
    }

    for (int i = 1; i < 100; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j > 0) {
                bit2cnt[i][j] += bit2cnt[i - 1][j - 1];
                bit2cnt[i][j] %= mod;
            }

            if (j < 9) {
                bit2cnt[i][j] += bit2cnt[i - 1][j + 1];
                bit2cnt[i][j] %= mod;
            }

            if (j == 0) {
                sums[i][j] = sums[i - 1][9];
                continue;
            }

            sums[i][j] = bit2cnt[i][j];
            sums[i][j] += sums[i][j - 1];
            sums[i][j] %= mod;
        }
    }

    return 0;
}();

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        int ans = countLE(high);
        ans += mod - countLE(low) + countIsSteppingNumber(low);
        ans %= mod;
        return ans;
    }

private:
    int countLE(string_view s) {
        int n = s.size();
        int ans = sums[n - 1][s[0] - '0' - 1];
        for (int i = 1; i <= n; ++i) {
            if (i == n) {
                ans += 1;
                ans %= mod;
                break;
            }

            int pre = s[i - 1] - '0';
            int cur = s[i] - '0';
            if (cur < pre - 1) {
                break;
            }
            else if (cur == pre - 1) {
                continue;
            }

            if (pre > 0) {
                ans += bit2cnt[n - i - 1][pre - 1];
                ans %= mod;
            }

            if (cur == pre + 1) {
                continue;
            }

            if (cur > pre + 1) {
                ans += bit2cnt[n - i - 1][pre + 1];
                ans %= mod;
            }

            break;
        }

        return ans;
    }

    int countIsSteppingNumber(string_view s) {
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] + 1 != s[i - 1] && s[i] - 1 != s[i - 1]) {
                return 0;
            }
        }

        return 1;
    }
};

TEST(&Solution::countSteppingNumbers)