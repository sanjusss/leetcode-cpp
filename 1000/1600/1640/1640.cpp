/*
 * @Author: sanjusss
 * @Date: 2022-09-22 08:25:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-22 08:31:55
 * @FilePath: \1000\1600\1640\1640.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        unordered_map<int, int> nexts;
        nexts[arr.back()] = 0;
        for (int i = 1; i < n; ++i) {
            nexts[arr[i - 1]] = arr[i];
        }

        for (auto& p : pieces) {
            if (!nexts.count(p.back())) {
                return false;
            }

            for (int i = p.size() - 1; i > 0; --i) {
                if (!nexts.count(p[i - 1]) || nexts[p[i - 1]] != p[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};