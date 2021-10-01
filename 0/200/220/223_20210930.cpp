/*
 * @Author: sanjusss
 * @Date: 2021-09-30 08:39:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-30 09:00:47
 * @FilePath: \0\200\220\223_20210930.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
//         if (ax1 > bx1) {  // 确保a在b的左边
//             return computeArea(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2);
//         }

//         int sum = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
//         if (ax2 <= bx1 || ay1 >= by2 || by1 >= ay2) {  //排除不重叠的情况
//             return sum;
//         }

//         return sum - (min(ax2, bx2) - bx1) * (min(ay2, by2) - max(ay1, by1));
//     }
// };

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int sum = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        int reuse = max(0, min(ax2, bx2) - max(ax1, bx1)) * max(0, min(ay2, by2) - max(ay1, by1));
        return sum - reuse;
    }
};

TEST(&Solution::computeArea)