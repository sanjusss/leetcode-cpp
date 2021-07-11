/*
 * @Author: sanjusss
 * @Date: 2021-07-11 09:00:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-11 09:29:30
 * @FilePath: \0\200\270\274.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         int n = citations.size();
//         int left = 0;
//         int right = n;
//         sort(citations.begin(), citations.end());
//         while (left < right) {
//             int mid = (left + right) / 2;
//             if ((upper_bound(citations.begin(), citations.end(), mid) - citations.begin()) >= n - mid) {
//                 right = mid;
//             }
//             else {
//                 left = mid + 1;
//             }
//         }
        
//         return left;
//     }
// };

// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         sort(citations.begin(), citations.end());
//         int h = 0;
//         int i = citations.size() - 1;
//         while (i >= 0 && citations[i] > h) {
//             ++h;
//             --i;
//         }

//         return h;
//     }
// };

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int i : citations) {
            if (i > n) {
                ++cnt[n];
            }
            else {
                ++cnt[i];
            }
        }

        int cur = 0;
        for (int i = n; i > 0; --i) {
            cur += cnt[i];
            if (cur >= i) {
                return i;
            }
        }

        return 0;
    }
};

TEST(&Solution::hIndex)