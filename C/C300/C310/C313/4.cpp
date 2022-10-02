/*
 * @Author: sanjusss
 * @Date: 2022-10-02 10:26:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-02 11:13:24
 * @FilePath: \C\C300\C310\C313\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int deleteString(string s) {
//         auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
//             if (a.first == b.first) {
//                 return a.second < b.second;
//             }
//             else {
//                 return a.first > b.first;
//             }
//         };
//         set<pair<int, int>, decltype(cmp)> q(cmp);
//         int n = s.size();
//         int ans = 1;
//         q.emplace(1, n - 1);
//         for (int i = n - 2; i >= 0; --i) {
//             int maxCnt = 1;
//             for (auto [cnt, j] : q) {
//                 if (j - i > n - j) {
//                     continue;
//                 }

//                 bool found = true;
//                 for (int k = j - i - 1; k >= 0; --k) {
//                     if (s[i + k] != s[j + k]) {
//                         found = false;
//                         break;
//                     }
//                 }

//                 if (found) {
//                     maxCnt = cnt + 1;
//                     break;
//                 }
//             }

//             if (i == 0) {
//                 ans = maxCnt;
//             }
//             else {
//                 q.emplace(maxCnt, i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int deleteString(string s) {
        map<int, set<int>, greater<>> q;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            int maxCnt = 1;
            for (auto& [cnt, part] : q) {
                for (int j : part) {
                    bool found = true;
                    if (j - i > n - j) {
                        break;
                    }

                    for (int k = j - i - 1; k >= 0; --k) {
                        if (s[i + k] != s[j + k]) {
                            found = false;
                            break;
                        }
                    }

                    if (found) {
                        maxCnt = cnt + 1;
                        break;
                    }
                }

                if (maxCnt > 1) {
                    break;
                }
            }

            if (i == 0) {
                return maxCnt;
            }
            else {
                q[maxCnt].insert(i);
            }
        }

        return 0;
    }
};

TEST(&Solution::deleteString)