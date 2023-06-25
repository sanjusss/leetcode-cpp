#include "leetcode.h"

// class Solution {
// public:
//     bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
//         int left = max(xCenter - radius, x1);
//         int right = min(xCenter + radius, x2);
//         int down = max(yCenter - radius, y1);
//         int up = min(yCenter + radius, y2);
//         for (int i = left; i <= right; ++i) {
//             for (int j = down; j <= up; ++j) {
//                 if ((i - xCenter) * (i - xCenter) + (j - yCenter) * (j - yCenter) <= radius * radius) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a = clamp(xCenter, x1, x2) - xCenter;
        int b = clamp(yCenter, y1, y2) - yCenter;
        return a * a + b * b <= radius * radius;
    }
};