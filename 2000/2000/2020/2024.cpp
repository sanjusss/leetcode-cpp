/*
 * @Author: sanjusss
 * @Date: 2022-03-29 08:49:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-29 09:55:24
 * @FilePath: \2000\2000\2020\2024.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxConsecutiveAnswers(string answerKey, int k) {
//         k = min<int>(answerKey.size(), k);
//         vector<int> tdp(k + 1);
//         vector<int> fdp(k + 1);
//         int ans = 0;
//         for (char i : answerKey) {
//             for (int j = k; j >= 0; --j) {
//                 if (i == 'T') {
//                     ++tdp[j];
//                     fdp[j] = j > 0 ? fdp[j - 1] + 1 : 0;
//                 }
//                 else {
//                     ++fdp[j];
//                     tdp[j] = j > 0 ? tdp[j - 1] + 1 : 0;
//                 }

//                 ans = max({ ans, fdp[j], tdp[j] });
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        queue<int> tmod;
        int tbegin = 0;
        queue<int> fmod;
        int fbegin = 0;
        int n = answerKey.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (answerKey[i] == 'T') {
                ans = max(ans, i - tbegin + 1);
                if (fmod.size() < k) {
                    fmod.push(i);
                    ans = max(ans, i - fbegin + 1);
                }
                else if (fmod.empty()) {
                    fbegin = i + 1;
                }
                else {
                    fbegin = fmod.front() + 1;
                    fmod.pop();
                    fmod.push(i);
                    ans = max(ans, i - fbegin + 1);
                }
            }
            else {
                ans = max(ans, i - fbegin + 1);
                if (tmod.size() < k) {
                    tmod.push(i);
                    ans = max(ans, i - tbegin + 1);
                }
                else if (tmod.empty()) {
                    tbegin = i + 1;
                }
                else {
                    tbegin = tmod.front() + 1;
                    tmod.pop();
                    tmod.push(i);
                    ans = max(ans, i - tbegin + 1);
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::maxConsecutiveAnswers)