/*
 * @Author: sanjusss
 * @Date: 2022-02-11 14:19:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-11 14:47:54
 * @FilePath: \0\200\250\254.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> getFactors(int n) {
//         function<vector<vector<int>>(int, int)> dfs = [&dfs] (int n, int minFactor) -> vector<vector<int>> {
//             vector<vector<int>> ans;
//             for (int i = minFactor; i < n; ++i) {
//                 if (n % i != 0 || n / i < i) {
//                     continue;
//                 }

//                 ans.push_back({ i, n / i });
//                 vector<vector<int>> next = dfs(n / i, i);
//                 for (auto& v : next) {
//                     v.push_back(i);
//                     ans.push_back(move(v));
//                 }
//             }

//             return ans;
//         };
//         return dfs(n, 2);
//     }
// };

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        function<vector<vector<int>>(int, int)> dfs = [&dfs] (int n, int minFactor) -> vector<vector<int>> {
            vector<vector<int>> ans;
            for (int i = minFactor; i * i <= n; ++i) {
                if (n % i != 0 || n / i < i) {
                    continue;
                }

                ans.push_back({ i, n / i });
                vector<vector<int>> next = dfs(n / i, i);
                for (auto& v : next) {
                    v.push_back(i);
                    ans.push_back(move(v));
                }
            }

            return ans;
        };
        return dfs(n, 2);
    }
};