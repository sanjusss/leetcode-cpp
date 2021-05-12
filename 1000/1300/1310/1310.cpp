/*
 * @Author: sanjusss
 * @Date: 2021-05-12 08:48:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-12 08:53:56
 * @FilePath: \1000\1300\1310\1310.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors(1);
        for (int i : arr) {
            xors.push_back(xors.back() ^ i);
        }

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(xors[q[0]] ^ xors[q[1] + 1]);
        }

        return ans;
    }
};

TEST(&Solution::xorQueries)