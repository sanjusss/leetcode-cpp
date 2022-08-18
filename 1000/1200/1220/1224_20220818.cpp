/*
 * @Author: sanjusss
 * @Date: 2022-08-18 08:24:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-18 09:22:12
 * @FilePath: \1000\1200\1220\1224_20220818.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxEqualFreq(vector<int>& nums) {
//         int ans = 0;
//         unordered_map<int, int> cnt;
//         unordered_map<int, int> cnts2;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             int c = ++cnt[nums[i]];
//             if (c > 1) {
//                 if (--cnts2[c - 1] == 0) {
//                     cnts2.erase(c - 1);
//                 }
//             }

//             ++cnts2[c];
//             if (cnt.size() == 1) {
//                 ans = i + 1;
//             }
//             else if (cnts2.size() == 2) {
//                 auto [c1, cc1] = *cnts2.begin();
//                 auto [c2, cc2] = *next(cnts2.begin());
//                 if ((cc1 == 1 && (c1 - 1 == c2 || c1 == 1)) || (cc2 == 1 && (c2 - 1 == c1 || c2 == 1))) {
//                     ans = i + 1;
//                 }
//             }
//             else if (cnts2.size() == 1) {
//                 if (cnts2.begin()->first == 1) {
//                     ans = i + 1;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> cnt(1e5 + 1);
        vector<int> freq(n + 1);
        int maxFreq = 0;
        for (int i = 0; i < n; ++i) {
            int c = ++cnt[nums[i]];
            ++freq[c];
            maxFreq = max(maxFreq, c);
            if (maxFreq == 1) {
                ans = i + 1;
            }
            else if (freq[maxFreq] == 1 && freq[maxFreq - 1] * (maxFreq - 1) == i) {
                ans = i + 1;
            }
            else if (freq[1] == freq[maxFreq] + 1 && freq[maxFreq] * maxFreq == i) {
                ans = i + 1;
            }
        }

        return ans;
    }
};

TEST(&Solution::maxEqualFreq)