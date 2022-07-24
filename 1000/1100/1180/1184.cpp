/*
 * @Author: sanjusss
 * @Date: 2022-07-24 10:18:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-24 10:22:19
 * @FilePath: \1000\1100\1180\1184.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int dis = 0;
        int n = distance.size();
        for (int i = start; i % n != destination; ++i) {
            dis += distance[i % n];
        }

        int ans = dis;
        dis = 0;
        for (int i = start + n; i % n != destination; --i) {
            dis += distance[(i - 1) % n];
        }

        return min(ans, dis);
    }
};