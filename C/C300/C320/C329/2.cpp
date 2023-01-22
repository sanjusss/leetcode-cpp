/*
 * @Author: sanjusss
 * @Date: 2023-01-22 10:35:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-22 10:36:27
 * @FilePath: \C\C300\C320\C329\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](const vector<int>& a, const vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};