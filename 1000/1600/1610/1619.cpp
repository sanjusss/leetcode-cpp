/*
 * @Author: sanjusss
 * @Date: 2022-09-14 08:33:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-14 08:37:44
 * @FilePath: \1000\1600\1610\1619.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int trimSize = n / 20;
        priority_queue<int> qMax;
        priority_queue<int, vector<int>, greater<int>> qMin;
        int sum = 0;
        for (int i : arr) {
            sum += i;
            qMax.push(i);
            if (qMax.size() > trimSize) {
                qMax.pop();
            }

            qMin.push(i);
            if (qMin.size() > trimSize) {
                qMin.pop();
            }
        }

        while (!qMax.empty()) {
            sum -= qMax.top();
            qMax.pop();
        }


        while (!qMin.empty()) {
            sum -= qMin.top();
            qMin.pop();
        }

        return (double)sum / (double)(n - trimSize * 2);
    }
};