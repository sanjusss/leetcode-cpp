/*
 * @Author: sanjusss
 * @Date: 2021-09-05 09:48:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 09:59:21
 * @FilePath: \0\400\470\470.cpp
 */
#include "leetcode.h"

int rand7() {
    return rand() % 7 + 1;
}

// class Solution {
// public:
//     int rand10() {
//         int ans = 0;
//         for (int i = 0; i < 10; ++i) {
//             ans += rand7();
//         }

//         return ans % 10 + 1;
//     }
// };

class Solution {
public:
    int rand10() {
        int i;
        do {
            i = (rand7() - 1) * 7 + rand7();
        } while (i > 40);
        return i % 10 + 1;
    }
};