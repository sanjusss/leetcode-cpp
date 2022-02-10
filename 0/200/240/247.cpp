/*
 * @Author: sanjusss
 * @Date: 2022-02-10 16:13:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-10 16:35:36
 * @FilePath: \0\200\240\247.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        static const vector<char> sc_centers = {
            '0',
            '1',
            '8',
        };
        static const vector<pair<char, char>> sc_pairs = {
            { '0', '0' },
            { '1', '1' },
            { '6', '9' },
            { '8', '8' },
            { '9', '6' },
        };
        string s(n, ' ');
        vector<string> ans;
        function<void(int)> dfs = [&](int i) {
            if (i == n / 2) {
                ans.push_back(s);
                return;
            }
            
            for (auto [f, b] : sc_pairs) {
                if (i == 0 && f == '0') {
                    continue;
                }

                s[i] = f;
                s[n - 1 - i] = b;
                dfs(i + 1);
            }
        };
        if (n & 1) {
            for (char c : sc_centers) {
                s[n / 2] = c;
                dfs(0);
            }
        }
        else {
            dfs(0);
        }

        return ans;
    }
};