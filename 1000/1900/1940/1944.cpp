/*
 * @Author: sanjusss
 * @Date: 2024-01-05 11:25:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-05 11:32:33
 * @FilePath: \1000\1900\1940\1944.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            int h = heights[i];
            while (!s.empty() && s.top() < h) {
                ++ans[i];
                s.pop();
            }

            if (!s.empty()) {
                if (s.top() == h) {
                    s.pop();
                } 

                ++ans[i];
            }

            s.push(h);
        }

        return ans;
    }
};

TEST(&Solution::canSeePersonsCount)