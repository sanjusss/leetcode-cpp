/*
 * @Author: sanjusss
 * @Date: 2022-12-28 13:40:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-28 14:06:06
 * @FilePath: \0\300\380\385.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string rearrangeString(string s, int k) {
//         vector<int> cnt(26);
//         for (char i : s) {
//             ++cnt[i - 'a'];
//         }

//         vector<int> nexts(26);
//         string ans;
//         int n = s.size();
//         for (int i = 0; i < n; ++i) {
//             int j = -1;
//             int c = 0;
//             for (int p = 0; p < 26; ++p) {
//                 if (nexts[p] <= i && cnt[p] > c) {
//                     c = cnt[p];
//                     j = p;
//                 }
//             }

//             if (j < 0) {
//                 return {};
//             }

//             --cnt[j];
//             nexts[j] = i + k;
//             ans.push_back('a' + j);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<int> cnt(26);
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        vector<int> nexts(26);
        auto cmpNexts = [&nexts](int a, int b) {
            return nexts[a] > nexts[b];
        };
        priority_queue<int, vector<int>, decltype(cmpNexts)> qNexts(cmpNexts);
        auto cmpCnt = [&cnt](int a, int b) {
            return cnt[a] < cnt[b];
        };
        priority_queue<int, vector<int>, decltype(cmpCnt)> qCnt(cmpCnt);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                qCnt.push(i);
            }
        }

        string ans;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            while (!qNexts.empty()) {
                int j = qNexts.top();
                if (nexts[j] <= i) {
                    qNexts.pop();
                    qCnt.push(j);
                }
                else {
                    break;
                }
            }

            if (qCnt.empty()) {
                return {};
            }

            auto j = qCnt.top();
            qCnt.pop();
            ans.push_back(j + 'a');
            if (--cnt[j] > 0) {
                nexts[j] = i + k;
                qNexts.push(j);
            }
        }

        return ans;
    }
};