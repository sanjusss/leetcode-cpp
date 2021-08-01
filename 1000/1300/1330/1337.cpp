/*
 * @Author: sanjusss
 * @Date: 2021-08-01 10:18:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-01 10:26:37
 * @FilePath: \1000\1300\1330\1337.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> q;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int left = 0;
            int right = n;
            while (left < right) {
                int mid = (left + right) / 2;
                if (mat[i][mid] == 1) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }

            q.emplace(left, i);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};