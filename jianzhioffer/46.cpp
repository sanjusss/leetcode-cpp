/*
 * @Author: sanjusss
 * @Date: 2021-08-15 16:02:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 16:24:03
 * @FilePath: \jianzhioffer\46.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int translateNum(int num) {
//         stack<int> s;
//         s.push(num);
//         int ans = 0;
//         while (!s.empty()) {
//             int n = s.top();
//             s.pop();
//             if (n == 0) {
//                 ++ans;
//                 continue;
//             }

//             s.push(n / 10);
//             if (n % 100 >= 10 && n % 100 < 26) {
//                 s.push(n / 100);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int translateNum(int num) {
        int prev = 0;
        int cur = 1;
        int last = num % 10;
        num /= 10;
        while (num > 0) {
            int next;
            int test = num % 10 * 10 + last;
            if (test < 26 && test >= 10) {
                next = cur + prev;
            }
            else {
                next = cur;
            }

            prev = cur;
            cur = next;
            last = num % 10;
            num /= 10;
        }

        return cur;
    }
};