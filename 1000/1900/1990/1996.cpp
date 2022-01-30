/*
 * @Author: sanjusss
 * @Date: 2022-01-28 09:03:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-29 09:21:59
 * @FilePath: \1000\1900\1990\1996.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
//         int n = properties.size();
//         vector<int> is(n);
//         iota(is.begin(), is.end(), 0);
//         sort(is.begin(), is.end(), [&properties](int a, int b) {
//             if (properties[a][0] == properties[b][0]) {
//                 return properties[a][1] > properties[b][1];
//             }
//             else {
//                 return properties[a][0] < properties[b][0];
//             }
//         });

//         int ans = 0;
//         stack<int> s;
//         for (int i : is) {
//             int b = properties[i][1];
//             while (!s.empty() && s.top() < b) {
//                 s.pop();
//                 ++ans;
//             }

//             s.push(b);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&properties](int a, int b) {
            if (properties[a][0] == properties[b][0]) {
                return properties[a][1] < properties[b][1];
            }
            else {
                return properties[a][0] > properties[b][0];
            }
        });

        int ans = 0;
        int maxDef = 0;
        for (int i : is) {
            if (properties[i][1] < maxDef) {
                ++ans;
            }
            else {
                maxDef = properties[i][1];
            }
        }

        return ans;
    }
};


TEST(&Solution::numberOfWeakCharacters)