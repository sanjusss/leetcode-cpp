/*
 * @Author: sanjusss
 * @Date: 2023-05-27 15:40:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-27 15:51:56
 * @FilePath: \1000\1000\1090\1093.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(5);
        int n = 0;
        double sum = 0;
        int minV = INT_MAX;
        int maxV = INT_MIN;
        int freq = 0;
        int v = -1;
        for (int i = 0; i <= 255; ++i) {
            if (count[i] == 0) {
                continue;
            }

            if (count[i] > freq) {
                freq = count[i];
                v = i;
            }

            minV = min(minV, i);
            maxV = max(maxV, i);
            n += count[i];
            sum += double(i) * count[i];
        }

        ans[0] = minV;
        ans[1] = maxV;
        ans[2] = sum / n;
        ans[4] = v;

        int mid = -1;
        int cur = 0;
        int target = (n + 1) / 2;
        for (int i = 0; i <= 255; ++i) {
            if (count[i] == 0) {
                continue;
            }

            cur += count[i];
            if (cur < target) {
                continue;
            }

            if (mid < 0) {
                mid = i;
            }
            else {
                mid += i;
                break;
            }

            if (n % 2 == 1) {
                break;
            }

            if (cur > target) {
                mid += i;
                break;
            }
        }

        if (n % 2 == 0) {
            ans[3] = mid / 2.0;
        }
        else {
            ans[3] = mid;
        }

        return ans;
    }
};