/*
 * @Author: sanjusss
 * @Date: 2023-08-21 08:23:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-21 09:23:29
 * @FilePath: \2000\2300\2330\2337.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool canChange(string start, string target) {
//         int n = start.size();
//         int maxR = -1;
//         int j = 0;
//         for (int i = 0; i < n; ++i) {
//             if (start[i] == 'L' && i <= maxR) {
//                 return false;
//             }

//             if (start[i] != 'R') {
//                 continue;
//             }

//             while (j < n && target[j] != 'R') {
//                 if (target[j] == 'L' && j >= i) {
//                     return false;
//                 }

//                 ++j;
//             }

//             if (j == n || j < i) {
//                 return false;
//             }

//             maxR = j++;
//         }

//         while (j < n) {
//             if (target[j++] == 'R') {
//                 return false;
//             }
//         }

//         j = n - 1;
//         int minL = n;
//         for (int i = n - 1; i >= 0; --i) {
//             if (start[i] == 'R' && i >= minL) {
//                 return false;
//             }

//             if (start[i] != 'L') {
//                 continue;
//             }

//             while (j >= 0 && target[j] != 'L') {
//                 if (target[j] == 'R' && j <= i) {
//                     return false;
//                 }

//                 --j;
//             }

//             if (j < 0 || j > i) {
//                 return false;
//             }

//             minL = j--;
//         }

//         while (j >= 0) {
//             if (target[j--] == 'L') {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0;
        int j = 0;
        while (true) {
            while (i < n && start[i] == '_') {
                ++i;
            }

            while (j < n && target[j] == '_') {
                ++j;
            }

            if (i == n && j == n) {
                return true;
            }
            else if (i == n || j == n) {
                return false;
            }
            else if (start[i] != target[j]) {
                return false;
            }
            else if (start[i] == 'L') {
                if (i < j) {
                    return false;
                }
            }
            else {
                if (i > j) {
                    return false;
                }
            }

            ++i;
            ++j;
        }

        return true;
    }
};

TEST(&Solution::canChange)