/*
 * @Author: sanjusss
 * @Date: 2021-08-19 09:28:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-19 09:48:08
 * @FilePath: \jianzhioffer\13.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int movingCount(int m, int n, int k) {
//         vector<vector<bool>> arr(m, vector<bool>(n));
//         auto canMove = [&](int i, int j) -> bool {
//             if (i < 0 || i >= m || j < 0 || j >= n || arr[i][j]) {
//                 return false;
//             }

//             int sum = 0;
//             while (i > 0) {
//                 sum += i % 10;
//                 i /= 10;
//             }

//             while (j > 0) {
//                 sum += j % 10;
//                 j /= 10;
//             }

//             return sum <= k;
//         };

//         static const vector<pair<int, int>> dirs = {
//             { 1, 0 },
//             { -1, 0 },
//             { 0, -1 },
//             { 0, 1 }
//         };

//         int ans = 0;
//         function<void(int, int)> dfs = [&](int i, int j) {
//             ++ans;
//             arr[i][j] = true;
//             for (auto [dx, dy] : dirs) {
//                 int x = i + dx;
//                 int y = j + dy;
//                 if (canMove(x, y)) {
//                     dfs(x, y);
//                 }
//             }
//         };

//         dfs(0, 0);
//         return ans;
//     }
// };

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> arr(m + 1, vector<bool>(n + 1));
        arr[0][1] = true;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!arr[i][j + 1] && !arr[i + 1][j]) {
                    continue;
                }

                int sum = 0;
                int x = i;
                int y = j;
                while (x > 0) {
                    sum += x % 10;
                    x /= 10;
                }

                while (y > 0) {
                    sum += y % 10;
                    y /= 10;
                }

                arr[i + 1][j + 1] = sum <= k;
                if (arr[i + 1][j + 1]) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};