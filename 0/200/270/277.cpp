/*
 * @Author: sanjusss
 * @Date: 2022-06-25 11:18:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-25 11:58:30
 * @FilePath: \0\200\270\277.cpp
 */
#include "leetcode.h"

bool knows(int a, int b);

// class Solution {
// public:
//     int findCelebrity(int n) {
//         int t = find(0, n - 1);
//         for (int i = 0; i < n; ++i) {
//             if (i != t && (!knows(i, t) || knows(t, i))) {
//                 return -1;
//             }
//         }

//         return t;
//     }

// private:
//     int find(int left, int right) {
//         if (left == right) {
//             return left;
//         }
//         else if (left + 1 == right) {
//             if (knows(left, right)) {
//                 return right;
//             }
//             else {
//                 return left;
//             }
//         }

//         int mid = (left + right) / 2;
//         int a = find(left, mid);
//         int b = find(mid + 1, right);
//         if (knows(a, b)) {
//             return b;
//         }
//         else {
//             return a;
//         }
//     }
// };

class Solution {
public:
    int findCelebrity(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (!knows(i, ans)) {
                ans = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != ans && (!knows(i, ans) || knows(ans, i))) {
                return -1;
            }
        }

        return ans;
    }
};