/*
 * @Author: sanjusss
 * @Date: 2023-03-19 09:09:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-19 10:09:45
 * @FilePath: \1000\1600\1620\1625.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        vector<int> minAdd(10, -1);
        for (int i = 0; i < 10; ++i) {
            for (int j = i; minAdd[j] == -1; j = (j + a) % 10) {
                minAdd[j] = (i + 10 - j) % 10;
            }
        }

        int n = s.size();
        vector<bool> used(n);
        string ans = s;
        for (int i = 0; !used[i]; i = (i + b) % n) {
            used[i] = true;
            string src = s.substr(i) + s.substr(0, i);
            if (b % 2 == 1) {
                int add0 = minAdd[src[0] - '0'];
                for (int i = 0; i < n; i += 2) {
                    src[i] = (src[i] - '0' + add0) % 10 + '0';
                }
            }

            int add1 = minAdd[src[1] - '0'];
            for (int i = 1; i < n; i += 2) {
                src[i] = (src[i] - '0' + add1) % 10 + '0';
            }

            ans = min(ans, src);
        }

        return ans;
    }
};

TEST(&Solution::findLexSmallestString)