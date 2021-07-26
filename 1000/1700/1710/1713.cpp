/*
 * @Author: sanjusss
 * @Date: 2021-07-26 08:48:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-26 09:33:35
 * @FilePath: \1000\1700\1710\1713.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minOperations(vector<int>& target, vector<int>& arr) {
//         int n = target.size();
//         unordered_map<int, int> ti;
//         for (int i = 0; i < n; ++i) {
//             ti[target[i]] = i;
//         }

//         int ans = n;
//         map<int, int> len;
//         for (int i : arr) {
//             auto tip = ti.find(i);
//             if (tip == ti.end()) {
//                 continue;
//             }

//             auto p = len.lower_bound(tip->second);
//             if (p != len.end() && p->first == tip->second) {
//                 continue;
//             }

//             int l;
//             if (p == len.begin()) {
//                 l = n - 1;
//             }
//             else {
//                 l = prev(p)->second - 1;
//             }

//             while (p != len.end() && p->second >= l) {
//                 len.erase(p++);
//             }

//             ans = min(ans, l);
//             len.emplace(tip->second, l);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> ti;
        for (int i = 0; i < n; ++i) {
            ti[target[i]] = i;
        }

        vector<int> seq;
        for (int i : arr) {
            auto tip = ti.find(i);
            if (tip == ti.end()) {
                continue;
            }

            int j = tip->second;
            auto p = lower_bound(seq.begin(), seq.end(), j);
            if (p == seq.end()) {
                seq.push_back(j);
            }
            else {
                *p = j;
            }
        }

        return n - seq.size();
    }
};

TEST(&Solution::minOperations)