/*
 * @Author: sanjusss
 * @Date: 2021-10-29 08:46:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-29 11:24:07
 * @FilePath: \0\300\330\335.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool isSelfCrossing(vector<int>& distance) {
//         int n = distance.size();
//         map<int, map<int, int>> xlines;  // 与x轴平行的线，key是y坐标
//         map<int, map<int, int>> ylines;  // 与y轴平行的线，key是x坐标
//         int x = 0;
//         int y = 0;
//         for (int i = 0; i < n; ++i) {
//             int start;
//             int end;
//             if (i % 2 == 0) {
//                 if (i % 4 == 0) {
//                     start = y;
//                     y += distance[i];
//                     end = y;
//                 }
//                 else {
//                     end = y;
//                     y -= distance[i];
//                     start = y;
//                 }

//                 auto& yl = ylines[x];
//                 auto p = yl.upper_bound(start);
//                 if ((p != yl.end() && p->first <= end) || (p != yl.begin() && prev(p)->second >= start)) {
//                     return true;
//                 }

//                 int cnt = 0;
//                 for (auto xlp = xlines.lower_bound(start); xlp != xlines.end() && xlp->first <= end; ++xlp) {
//                     auto& xl = xlp->second;
//                     auto p = xl.upper_bound(x);
//                     if (p != xl.begin() && prev(p)->second >= x) {
//                         if (++cnt == 2) {
//                             return true;
//                         }
//                     }
//                 }

//                 yl[start] = end;
//             }
//             else {
//                 if (i % 4 == 3) {
//                     start = x;
//                     x += distance[i];
//                     end = x;
//                 }
//                 else {
//                     end = x;
//                     x -= distance[i];
//                     start = x;
//                 }

//                 auto& xl = xlines[y];
//                 auto p = xl.upper_bound(start);
//                 if ((p != xl.end() && p->first <= end) || (p != xl.begin() && prev(p)->second >= start)) {
//                     return true;
//                 }

//                 int cnt = 0;
//                 for (auto ylp = ylines.lower_bound(start); ylp != ylines.end() && ylp->first <= end; ++ylp) {
//                     auto& yl = ylp->second;
//                     auto p = yl.upper_bound(y);
//                     if (p != yl.begin() && prev(p)->second >= y) {
//                         if (++cnt == 2) {
//                             return true;
//                         }
//                     }
//                 }

//                 xl[start] = end;
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        for (int i = 3; i < n; ++i) {
            if (distance[i - 1] <= distance[i - 3] && distance[i] >= distance[i - 2]) {
                return true;
            }

            if (i == 4 && distance[1] == distance[3] && distance[4] + distance[0] >= distance[2]) {
                return true;
            }

            if (i >= 5 && distance[i - 2] > distance[i - 4] && distance[i] + distance[i - 4] >= distance[i - 2] &&
                distance[i - 1] <= distance[i - 3] && distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
                return true;
            }
        }

        return false;
    }
};

TEST(&Solution::isSelfCrossing)