/*
 * @Author: sanjusss
 * @Date: 2021-06-06 10:28:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-06 11:35:06
 * @FilePath: \C\C200\C240\C244\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<int> oneStart = minFlipsGroup(s, n, false);
        vector<int> zeroStart = minFlipsGroup(s, n, true);
        int ans = min(oneStart[n - 1], zeroStart[n - 1]);
        int one = 0;
        int zero = 0;
        for (int i = 0; i < n; ++i) {
            int curOne = oneStart[n - 1] - oneStart[i];
            int curZero = zeroStart[n - 1] - zeroStart[i];
            if ((n + i) % 2 == 0) {
                if (s[i] == '0') {
                    ++one;
                }
                else {
                    ++zero;
                }
            }
            else {
                if (s[i] == '1') {
                    ++one;
                }
                else {
                    ++zero;
                }
            }

            ans = min(ans, curOne + one);
            ans = min(ans, curZero + zero);
        }

        return ans;
    }

private:
    vector<int> minFlipsGroup(const string& s, int n, bool prevOne) {
        vector<int> res(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (prevOne) {
                if (s[i] != '0') {
                    ++cur;
                }
            }
            else {
                if (s[i] != '1') {
                    ++cur;
                }
            }

            prevOne = !prevOne;
            res[i] = cur;
        }

        return move(res);
    }
};

TEST(&Solution::minFlips)