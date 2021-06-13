/*
 * @Author: sanjusss
 * @Date: 2021-06-13 10:26:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-13 16:49:40
 * @FilePath: \C\C200\C240\C245\4.cpp
 */
#include "leetcode.h"

class Solution {
    struct Calc {
        Calc(int n)
            : early(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1))),
              late(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1))) {
        }

        pair<int, int> find(int n, int f, int s) {  //限定f < s
            if (early[n][f][s] > 0) {
                return { early[n][f][s], late[n][f][s] };
            }
            else if (f + s == n + 1) {
                return { 1, 1 };
            }
            else if (f + s > n + 1) {
                tie(early[n][f][s], late[n][f][s]) = find(n, n + 1 - s, n + 1 - f);
                return { early[n][f][s], late[n][f][s] };
            }

            // f已被处理到左侧。
            int halfN = (n + 1) / 2;
            int e = INT_MAX;
            int l = INT_MIN;
            if (s <= halfN) {                               // s在左侧或中间
                for (int i = 0; i < f; ++i) {               // i：f左侧剩余人数
                    for (int j = s - f - 1; j >= 0; --j) {  // j：s、f之间的剩余人数
                        auto [ne, nl] = find(halfN, i + 1, i + j + 2);
                        e = min(e, ne);
                        l = max(l, nl);
                    }
                }
            }
            else {                                           // s在右侧，且s比f更靠近中间
                int so = n + 1 - s;                          // s本轮的对手
                int sOffset = (s - so) / 2;
                for (int i = 0; i < f; ++i) {                // i：f左侧剩余人数
                    for (int j = so - f - 1; j >= 0; --j) {  // j：so、f之间的剩余人数                        
                        auto [ne, nl] = find(halfN, i + 1, i + j + sOffset + 2);
                        e = min(e, ne);
                        l = max(l, nl);
                    }
                }
            }

            early[n][f][s] = e + 1;
            late[n][f][s] = l + 1;
            return { early[n][f][s], late[n][f][s] };
        }

        vector<vector<vector<int>>> early;
        vector<vector<vector<int>>> late;
    };

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        Calc calc(n);
        auto [e, l] = calc.find(n, firstPlayer, secondPlayer);
        return { e, l };
    }
};

TEST(&Solution::earliestAndLatest)