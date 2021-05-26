/*
 * @Author: sanjusss
 * @Date: 2021-05-26 08:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-26 09:10:22
 * @FilePath: \1000\1100\1190\1190.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string reverseParentheses(string s) {
//         string ans;
//         stack<string> st;
//         for (char i : s) {
//             if (i == '(') {
//                 st.push(move(ans));
//                 ans = string();
//             }
//             else if (i == ')') {
//                 reverse(ans.begin(), ans.end());
//                 ans = st.top() + ans;
//                 st.pop();
//             }
//             else {
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> next(n);
        stack<int> lefts;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                lefts.push(i);
            }
            else if (s[i] == ')') {
                int j = lefts.top();
                lefts.pop();
                next[i] = j;
                next[j] = i;
            }
        }

        int step = 1;
        string ans;
        for (int i = 0; i < n; i += step) {
            if (s[i] == '(' || s[i] == ')') {
                i = next[i];
                step = -step;
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

TEST(&Solution::reverseParentheses)