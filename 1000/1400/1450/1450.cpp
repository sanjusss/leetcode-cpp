/*
 * @Author: sanjusss
 * @Date: 2022-02-07 10:43:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-07 10:59:16
 * @FilePath: \1000\1400\1450\1450.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> q;
        if (a > 0) {
            q.emplace(a, 'a');
        }

        if (b > 0) {
            q.emplace(b, 'b');
        }

        if (c > 0) {
            q.emplace(c, 'c');
        }

        string ans;
        while (!q.empty()) {
            auto [cnt, i] = q.top();
            q.pop();
            ans.push_back(i);
            if (--cnt == 0) {
                continue;
            }

            if (q.empty()) {
                ans.push_back(i);
            }
            else if (q.top().first < cnt) {
                ans.push_back(i);
                auto [cj, j] = q.top();
                q.pop();
                ans.push_back(j);
                if (--cj > 0) {
                    q.emplace(cj, j);
                }

                if (--cnt > 0) {
                    q.emplace(cnt, i);
                }
            }
            else {
                q.emplace(cnt, i);
            }
        }

        return ans;
    }
};