/*
 * @Author: sanjusss
 * @Date: 2022-07-13 08:04:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-13 08:10:13
 * @FilePath: \0\700\730\735.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         vector<int> ans;
//         vector<int> rights;
//         for (int i : asteroids) {
//             if (i > 0) {
//                 rights.push_back(i);
//                 continue;
//             }

//             bool boom = false;
//             while (!rights.empty()) {
//                 if (-i <= rights.back()) {
//                     boom = true;
//                     if (-i == rights.back()) {
//                         rights.pop_back();
//                     }

//                     break;
//                 }
//                 else {
//                     rights.pop_back();
//                 }
//             }

//             if (!boom) {
//                 ans.push_back(i);
//             }
//         }

//         copy(rights.begin(), rights.end(), back_inserter(ans));
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i : asteroids) {
            if (i > 0) {
                ans.push_back(i);
                continue;
            }

            bool boom = false;
            while (!ans.empty() && ans.back() > 0) {
                if (-i <= ans.back()) {
                    boom = true;
                    if (-i == ans.back()) {
                        ans.pop_back();
                    }

                    break;
                }
                else {
                    ans.pop_back();
                }
            }

            if (!boom) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};