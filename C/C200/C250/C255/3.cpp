/*
 * @Author: sanjusss
 * @Date: 2021-08-22 10:29:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 11:25:46
 * @FilePath: \C\C200\C250\C255\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        unordered_set<int> cur;
        cur.insert(0);
        for (auto& row : mat) {
            int bigger = INT_MAX;
            unordered_set<int> next;
            for (int i : cur) {
                for (int j : row) {
                    int sum = i + j;
                    if (sum >= target) {
                        bigger = min(bigger, sum);
                    }
                    else {
                        next.insert(sum);
                    }
                }
            }

            if (bigger != INT_MAX) {
                next.insert(bigger);
            }

            cur = move(next);
        }

        int ans = INT_MAX;
        for (int i : cur) {
            ans = min(ans, abs(i - target));
        }

        return ans;
    }
};