/*
 * @Author: sanjusss
 * @Date: 2022-01-21 08:16:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-21 08:23:59
 * @FilePath: \1000\1300\1340\1345.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i) {
            pos[arr[i]].push_back(i);
        }

        int target = n - 1;
        vector<bool> passed(n);
        passed[0] = true;
        queue<int> q;
        q.push(0);
        for (int ans = 0; !q.empty(); ++ans) {
            for (int qi = q.size(); qi > 0; --qi) {
                int i = q.front();
                q.pop();
                if (i == target) {
                    return ans;
                }

                if (i - 1 >= 0 && !passed[i - 1]) {
                    q.push(i - 1);
                    passed[i - 1] = true;
                }

                if (i + 1 < n && !passed[i + 1]) {
                    q.push(i + 1);
                    passed[i + 1] = true;
                }

                for (int j : pos[arr[i]]) {
                    if (!passed[j]) {
                        q.push(j);
                        passed[j] = true;
                    }
                }

                pos[arr[i]].clear();
            }
        }

        return -1;
    }
};