/*
 * @Author: sanjusss
 * @Date: 2022-02-26 18:26:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 18:32:08
 * @FilePath: \0\200\210\210_20220226.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nexts(numCourses);
        vector<int> preCnt(numCourses);
        for (auto& p : prerequisites) {
            nexts[p[1]].push_back(p[0]);
            ++preCnt[p[0]];
        }

        int remain = numCourses;
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i) {
            if (preCnt[i] == 0) {
                --remain;
                q.push(i);
                ans.push_back(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : nexts[i]) {
                if (--preCnt[j] == 0) {
                    --remain;
                    q.push(j);
                    ans.push_back(j);
                }
            }
        }

        return remain == 0 ? ans : vector<int>();
    }
};