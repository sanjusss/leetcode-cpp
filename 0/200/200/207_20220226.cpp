/*
 * @Author: sanjusss
 * @Date: 2022-02-26 18:12:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 18:24:36
 * @FilePath: \0\200\200\207_20220226.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nexts(numCourses);
        vector<int> preCnt(numCourses);
        for (auto& p : prerequisites) {
            nexts[p[1]].push_back(p[0]);
            ++preCnt[p[0]];
        }

        int remain = numCourses;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (preCnt[i] == 0) {
                --remain;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : nexts[i]) {
                if (--preCnt[j] == 0) {
                    q.push(j);
                    --remain;
                }
            }
        }

        return remain == 0;
    }
};