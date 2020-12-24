#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         if (n < 2) {
//             return n;
//         }

//         vector<int> c(n);
//         for (int i = 1; i < n - 1; ++i) {
//             if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1]) {
//                 c[i] = 1;
//             }
//         }

//         if (ratings[0] <= ratings[1]) {
//             c[0] = 1;
//         }

//         if (ratings[n - 1] <= ratings[n - 2]) {
//             c[n - 1] = 1;
//         }

//         for (int i = 0; i < n; ++i) {
//             if (c[i] != 1) {
//                 continue;
//             }

//             for (int j = i - 1; j >= 0 && ratings[j] > ratings[j + 1]; --j) {
//                 c[j] = max(c[j], c[j + 1] + 1);
//             }

//             for (int j = i + 1; j < n && ratings[j] > ratings[j - 1]; ++j) {
//                 c[j] = max(c[j], c[j - 1] + 1);
//             }
//         }

//         return accumulate(c.begin(), c.end(), 0);
//     }
// };

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> left(n);
//         for (int i = 0; i < n; ++i) {
//             if (i > 0 && ratings[i] > ratings[i - 1]) {
//                 left[i] = left[i - 1] + 1;
//             }
//             else {
//                 left [i] = 1;
//             }
//         }

//         int ans = 0;
//         int right = 0;
//         for (int i = n - 1; i >= 0; --i) {
//             if (i < n - 1 && ratings[i] > ratings[i + 1]) {
//                 ++right;
//             }
//             else {
//                 right = 1;
//             }

//             ans += max(right, left[i]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) {
            return n;
        }

        int ans = 1;
        int inc = 1;
        int dec = 0;
        int pre = 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ans += pre;
                inc = pre;
            }
            else {
                ++dec;
                if (dec == inc) {
                    ++dec;
                }

                ans += dec;
                pre = 1;
            }
        }

        return ans;
    }
};