/*
 * @Author: sanjusss
 * @Date: 2022-04-23 19:46:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-23 20:14:34
 * @FilePath: \0\500\580\587.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }

        int leftMost = 0;
        for (int i = 1; i < n; ++i) {
            if (trees[i][0] < trees[leftMost][0]) {
                leftMost = i;
            }
        }

        vector<vector<int>> ans;
        vector<bool> passed(n);
        int prev = leftMost;
        do {
            int cur = (prev + 1) % n;
            for (int next = 0; next < n; ++next) {
                if (cross(trees[prev], trees[cur], trees[next]) < 0) {
                    cur = next;
                }
            }

            for (int next = 0; next < n; ++next) {
                if (passed[next] || next == prev || next == cur) {
                    continue;
                }

                if (cross(trees[prev], trees[cur], trees[next]) == 0) {
                    ans.push_back(trees[next]);
                    passed[next] = true;
                }
            }

            if (!passed[cur]) {
                ans.push_back(trees[cur]);
                passed[cur] = true;
            }

            prev = cur;
        } while (leftMost != prev);
        return ans;
    }

private:
    int cross(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }
};