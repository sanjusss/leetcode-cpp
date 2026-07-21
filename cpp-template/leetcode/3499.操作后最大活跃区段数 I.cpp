/*
 * @lc app=leetcode.cn id=3499 lang=cpp
 * @lcpr version=30404
 *
 * [3499] 操作后最大活跃区段数 I
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// class Solution {
// public:
//     int maxActiveSectionsAfterTrade(string s) {
//         int n = s.size();
//         const char first = s[0];
//         int cnt = 1;
//         char last = first;
//         vector<int> arr;
//         for (int i = 1; i < n; ++i) {
//             if (s[i] == last) {
//                 ++cnt;
//             } else {
//                 arr.push_back(cnt);
//                 last = s[i];
//                 cnt = 1;
//             }
//         }

//         arr.push_back(cnt);

//         int ans = 0;
//         bool isOne = first == '1';
//         const int m = arr.size();
//         int ones = 0;
//         for (int i = 0; i < m; ++i) {
//             if (isOne) {
//                 ones += arr[i];
//                 if (i > 0 && i + 1 < m) {
//                     ans = max(ans, arr[i - 1] + arr[i + 1]);
//                 }
//             }

//             isOne = !isOne;
//         }

//         return ans + ones;
//     }
// };

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int maxTwoZeros = 0;
        int curZeros = 0;
        int preZeros = 0;
        int ones = 0;
        for (char i : s) {
            if (i == '1') {
                ++ones;
                if (curZeros) {
                    preZeros = curZeros;
                    curZeros = 0;
                }
            } else {
                ++curZeros;
                if (preZeros) {
                    maxTwoZeros = max(maxTwoZeros, preZeros + curZeros);
                }
            }
        }

        return ones + maxTwoZeros;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "101"\n
// @lcpr case=end

// @lcpr case=start
// "01"\n
// @lcpr case=end

// @lcpr case=start
// "0100"\n
// @lcpr case=end

// @lcpr case=start
// "1000100"\n
// @lcpr case=end

// @lcpr case=start
// "01010"\n
// @lcpr case=end

 */

