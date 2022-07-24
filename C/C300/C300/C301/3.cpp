/*
 * @Author: sanjusss
 * @Date: 2022-07-10 10:37:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-10 11:02:37
 * @FilePath: \C\C300\C300\C301\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        vector<pair<bool, int>> sp;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L') {
                sp.emplace_back(false, i);
            }
            else if (start[i] == 'R') {
                sp.emplace_back(true, i);
            }
        }

        vector<pair<bool, int>> tp;
        for (int i = 0; i < n; ++i) {
            if (target[i] == 'L') {
                tp.emplace_back(false, i);
            }
            else if (target[i] == 'R') {
                tp.emplace_back(true, i);
            }
        }

        if (tp.size() != sp.size()) {
            return false;
        }

        int m = tp.size();
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            if (sp[i].first != tp[i].first) {
                return false;
            }

            if (sp[i].first) { // 向右移动
                if (prev < tp[i].second && sp[i].second <= tp[i].second) {
                    prev = tp[i].second;
                }
                else {
                    return false;
                }
            }
            else { // 向左移动
                if (prev < sp[i].second && sp[i].second >= tp[i].second) {
                    prev = tp[i].second;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};