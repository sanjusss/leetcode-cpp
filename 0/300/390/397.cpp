/*
 * @Author: sanjusss
 * @Date: 2021-11-19 13:29:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-19 13:37:30
 * @FilePath: \0\300\390\397.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int integerReplacement(int n) {
        unordered_set<int64_t> passed;
        passed.insert(n);
        queue<int64_t> q;
        q.push(n);
        int ans = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int64_t j = q.front();
                q.pop();
                if (j == 1) {
                    return ans;
                }

                if (j & 1) {
                    if (passed.insert(j + 1).second) {
                        q.push(j + 1);
                    }

                    if (passed.insert(j - 1).second) {
                        q.push(j - 1);
                    }
                }
                else {
                    if (passed.insert(j / 2).second) {
                        q.push(j / 2);
                    }
                }
            }

            ++ans;
        }

        return ans;
    }
};