/*
 * @Author: sanjusss
 * @Date: 2022-05-30 08:52:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-03 10:57:58
 * @FilePath: \1000\1600\1680\1688.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxRepeating(string sequence, string word) {
//         int left = 0;
//         int right = sequence.size() / word.size();
//         while (left < right) {
//             int mid = (left + right + 1) / 2;
//             string t;
//             for (int i = 0; i < mid; ++i) {
//                 t += word;
//             }

//             if (sequence.find(t) != string::npos) {
//                 left = mid;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }

//         return left;
//     }
// };

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = sequence.size();
        int n = word.size();

        vector<int> cnt(m);
        vector<bool> hasPrev(n);
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                hasPrev[j] = sequence[i] == word[j] && (j > 0 ? hasPrev[j - 1] : true);
            }

            if (hasPrev[n - 1]) {
                if (i >= n) {
                    cnt[i] = cnt[i - n] + 1;
                }
                else {
                    cnt[i] = 1;
                }
            }
        }

        return *max_element(cnt.begin(), cnt.end());
    }
};

TEST(&Solution::maxRepeating)