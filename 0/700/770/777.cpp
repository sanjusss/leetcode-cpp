/*
 * @Author: sanjusss
 * @Date: 2022-10-02 10:09:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-02 10:24:57
 * @FilePath: \0\700\770\777.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool canTransform(string start, string end) {
//         string src;
//         for (char i : start) {
//             if (i != 'X') {
//                 src.push_back(i);
//             }
//         }

//         string des;
//         for (char i : end) {
//             if (i != 'X') {
//                 des.push_back(i);
//             }
//         }

//         if (src != des) {
//             return false;
//         }

//         int n = start.size();
//         vector<int> desLefts;
//         vector<int> desRights;
//         for (int i = 0; i < n; ++i) {
//             if (end[i] == 'L') {
//                 desLefts.push_back(i);
//             }
//             else if (end[i] == 'R') {
//                 desRights.push_back(i);
//             }
//         }

//         int left = 0;
//         int right = 0;
//         for (int i = 0; i < n; ++i) {
//             if (start[i] == 'L') {
//                 if (desLefts[left++] > i) {
//                     return false;
//                 }
//             }
//             else if (start[i] == 'R') {
//                 if (desRights[right++] < i) {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0;
        int j = 0;
        while (true) {
            while (i < n && start[i] == 'X') {
                ++i;
            }

            while (j < n && end[j] == 'X') {
                ++j;
            }

            if (i == n && j == n) {
                return true;
            }
            else if (i == n || j == n || start[i] != end[j]) {
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

TEST(&Solution::canTransform)