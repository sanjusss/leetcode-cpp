/*
 * @Author: sanjusss
 * @Date: 2022-02-06 10:28:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-06 13:37:46
 * @FilePath: \C\C200\C270\C279\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minimumTime(string s) {
//         unordered_map<string_view, int> dp;
//         dp[""sv] = 0;
//         function<int(string_view)> dfs = [&](string_view sv) -> int {
//             if (dp.count(sv)) {
//                 return dp[sv];
//             }

//             int res = INT_MAX;

//             // 从左边开始。
//             int temp = 0;
//             string_view ts = sv;
//             while (!ts.empty() && ts.front() == '0') {
//                 ++temp;
//                 ts.remove_prefix(1);
//             }

//             while (!ts.empty() && ts.front() == '1') {
//                 ++temp;
//                 ts.remove_prefix(1);
//             }

//             res = min(res, temp + dfs(ts));

//             // 从右边开始。
//             temp = 0;
//             ts = sv;
//             while (!ts.empty() && ts.back() == '0') {
//                 ++temp;
//                 ts.remove_suffix(1);
//             }

//             while (!ts.empty() && ts.back() == '1') {
//                 ++temp;
//                 ts.remove_suffix(1);
//             }

//             res = min(res, temp + dfs(ts));

//             // 直接跳过
//             temp = 0;
//             for (char i : sv) {
//                 if (i == '1') {
//                     temp += 2;
//                 }
//             }
            
//             res = min(res, temp);

//             // 综合
//             dp[sv] = res;
//             return res;
//         };
        
//         string_view sv = s;
//         int base = 0;
//         while (!sv.empty() && sv.front() == '1') {
//             ++base;
//             sv.remove_prefix(1);
//         }
//         while (!sv.empty() && sv.back() == '1') {
//             ++base;
//             sv.remove_suffix(1);
//         }

//         return base + dfs(sv);
//     }
// };

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + s[i] - '0';
        }

        vector<int> lefts(n + 1);
        int diff = 0;
        for (int i = 1; i <= n; ++i) {
            diff = min(diff, i - 2 * sums[i]);
            lefts[i] = 2 * sums[i] + diff;
        }

        vector<int> rights(n + 2);
        diff = 0;
        for (int i = n; i > 0; --i) {
            diff = min(diff, (n - i + 1) - 2 * (sums[n] - sums[i - 1]));
            rights[i] = 2 * (sums[n] - sums[i - 1]) + diff;
        }

        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, lefts[i] + rights[i + 1]);
        }
        
        return ans;
    }
};