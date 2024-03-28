/*
 * @Author: sanjusss
 * @Date: 2024-03-28 08:55:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-28 10:38:49
 * @FilePath: \1000\1900\1990\1997.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int firstDayBeenInAllRooms(vector<int>& nextVisit) {
//         static const int64_t mod = 1e9 + 7;
//         int n = nextVisit.size();
//         vector<int64_t> cnt(n);
//         int64_t ans = -1;
//         int remain = n;
//         for (int i = 0; remain > 0; ) {
//             ++ans;
//             if (cnt[i] == 0) {
//                 --remain;
//             }

//             if (++cnt[i] % 2 == 1) {
//                 i = nextVisit[i];
//             }
//             else {
//                 i = (i + 1) % n;
//             }
//         }

//         return ans % mod;
//     }
// };

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        static const int mod = 1e9 + 7;
        int n = nextVisit.size();
        vector<int> dp(n); // 第一次到达i的步数
        for (int i = 0; i < n - 1; ++i) {
            int j = nextVisit[i];
            dp[i + 1] = dp[i] + 1;
            dp[i + 1] %= mod;
            dp[i + 1] += dp[i];
            dp[i + 1] %= mod;
            dp[i + 1] += mod - dp[j] + 1;
            dp[i + 1] %= mod;
        }

        return dp[n - 1];
    }
};

TEST(&Solution::firstDayBeenInAllRooms)