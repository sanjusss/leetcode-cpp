/*
 * @Author: sanjusss
 * @Date: 2023-09-12 22:44:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-12 22:53:43
 * @FilePath: \1000\1400\1460\1462.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> nexts(numCourses);
        vector<int> pres(numCourses);
        for (auto& pre : prerequisites) {
            nexts[pre[0]].push_back(pre[1]);
            pres[pre[1]] += 1; 
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (pres[i] == 0) {
                q.push(i);
            }
        }

        vector<vector<bool>> isPres(numCourses, vector<bool>(numCourses));
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : nexts[i]) {
                isPres[i][j] = true;
                for (int k = 0; k < numCourses; ++k) {
                    isPres[k][j] = isPres[k][j] || isPres[k][i];
                }

                if (--pres[j] == 0) {
                    q.push(j);
                }
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(isPres[q[0]][q[1]]);
        }

        return ans;
    }
};