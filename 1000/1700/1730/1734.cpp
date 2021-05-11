/*
 * @Author: sanjusss
 * @Date: 2021-05-11 08:29:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-11 08:44:55
 * @FilePath: \1000\1700\1730\1734.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total ^= i;
        }

        int sub = 0;
        for (int i = 1; i < n; i += 2) {
            sub ^= encoded[i];
        }

        vector<int> ans(n);
        ans[0] = total ^ sub;
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }

        return ans;
    }
};

TEST(&Solution::decode)