/*
 * @Author: sanjusss
 * @Date: 2022-10-14 08:07:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-14 08:21:02
 * @FilePath: \0\700\760\769.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto target = arr;
        sort(target.begin(), target.end());
        int n = arr.size();
        int ans = 0;
        int maxI = 0;
        int minI = 0;
        int len = 0;
        for (int v : arr) {
            while (target[maxI] < v) {
                ++maxI;
            }

            if (maxI - minI == len) {
                ++ans;
                minI = ++maxI;
                len = 0;
            }
            else {
                ++len;
            }
        }

        return ans;
    }
};

TEST(&Solution::maxChunksToSorted)