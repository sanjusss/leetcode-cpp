/*
 * @Author: sanjusss
 * @Date: 2022-12-28 09:08:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-28 09:31:40
 * @FilePath: \2000\2100\2100\2106.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int n = fruits.size();

        for (int left = 0, right = 0, sum = 0, begin = -1; right < n; ++right) {
            sum += fruits[right][1];
            if (fruits[right][0] < startPos) {
                continue;
            }
            else if (begin == -1) {
                begin = right;
            }

            int step = k - (fruits[right][0] - startPos);
            if (step < 0) {
                break;
            }

            while (left < begin && fruits[right][0] - fruits[left][0] > step) {
                sum -= fruits[left++][1];
            }

            ans = max(ans, sum);
        }
        
        for (int left = n - 1, right = n - 1, sum = 0, begin = -1; left >= 0; --left) {
            sum += fruits[left][1];
            if (fruits[left][0] > startPos) {
                continue;
            }
            else if (begin == -1) {
                begin = left;
            }

            int step = k - (startPos - fruits[left][0]);
            if (step < 0) {
                break;
            }

            while (begin < right && fruits[right][0] - fruits[left][0] > step) {
                sum -= fruits[right--][1];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};

TEST(&Solution::maxTotalFruits)