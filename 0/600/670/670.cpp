/*
 * @Author: sanjusss
 * @Date: 2022-09-13 07:39:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-13 08:00:46
 * @FilePath: \0\600\670\670.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maximumSwap(int num) {
//         if (num == 0) {
//             return 0;
//         }

//         vector<int> vs;
//         while (num > 0) {
//             vs.push_back(num % 10);
//             num /= 10;
//         }

//         vector<int> maxv = vs;
//         sort(maxv.begin(), maxv.end());
//         int n = vs.size();
//         for (int i = n - 1; i >= 0; --i) {
//             if (vs[i] == maxv[i]) {
//                 continue;
//             }

//             for (int j = 0; j < i; ++j) {
//                 if (vs[j] == maxv[i]) {
//                     swap(vs[i], vs[j]);
//                     break;
//                 }
//             }

//             break;
//         }

//         int ans = 0;
//         for (int i = n - 1; i >= 0; --i) {
//             ans = ans * 10 + vs[i];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maximumSwap(int num) {
        if (num == 0) {
            return 0;
        }

        vector<int> vs;
        while (num > 0) {
            vs.push_back(num % 10);
            num /= 10;
        }

        int n = vs.size();
        int maxIndex = 0;
        int smallerIndex = -1;
        int biggerIndex = -1;
        for (int i = 1; i < n; ++i) {
            if (vs[i] > vs[maxIndex]) {
                maxIndex = i;
            }
            else if (vs[i] < vs[maxIndex]) {
                smallerIndex = i;
                biggerIndex = maxIndex;
            }
        }

        if (smallerIndex >= 0) {
            swap(vs[smallerIndex], vs[biggerIndex]);
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans = ans * 10 + vs[i];
        }

        return ans;
    }
};

TEST(&Solution::maximumSwap)