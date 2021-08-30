/*
 * @Author: sanjusss
 * @Date: 2021-08-30 09:07:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-30 09:19:24
 * @FilePath: \jianzhioffer\31.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         int ipush = 0;
//         int ipop = 0;
//         stack<int> s;
//         while (ipush <= pushed.size()) {
//             while (!s.empty() && s.top() == popped[ipop]) {
//                 s.pop();
//                 ++ipop;
//             }

//             if (ipush < pushed.size()) {
//                 s.push(pushed[ipush]);
//             }

//             ++ipush;
//         }

//         return ipop == popped.size();
//     }
// };

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (int j : pushed) {
            s.push(j);
            while (!s.empty() && s.top() == popped[i]) {
                s.pop();
                ++i;
            }
        }

        return s.empty();
    }
};