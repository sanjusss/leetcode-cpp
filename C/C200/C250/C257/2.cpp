/*
 * @Author: sanjusss
 * @Date: 2021-09-05 10:36:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 10:50:45
 * @FilePath: \C\C200\C250\C257\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        vector<int> isort0(n);
        iota(isort0.begin(), isort0.end(), 0);
        sort(isort0.begin(), isort0.end(), [&properties](int a, int b) {
            if (properties[a][0] == properties[b][0]) {
                return properties[a][1] > properties[b][1];
            }
            else {
                return properties[a][0] < properties[b][0];
            }
        });
        int ans = 0;
        stack<int> p1;
        for (int i : isort0) {
            int def = properties[i][1];
            while (!p1.empty() && p1.top() < def) {
                ++ans;
                p1.pop();
            }

            p1.push(def);
        }

        return ans;
    }
};