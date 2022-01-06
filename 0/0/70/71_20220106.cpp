/*
 * @Author: sanjusss
 * @Date: 2022-01-06 08:37:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-06 08:45:44
 * @FilePath: \0\0\70\71_20220106.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string tmp;
        int n = path.size();
        for (int i = 0; i <= n; ++i) {
            if (i < n && path[i] != '/') {
                tmp.push_back(path[i]);
                continue;
            }

            if (tmp.empty()) {
                continue;
            }

            if (tmp == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            }
            else if (tmp != ".") {
                s.push(tmp);
            }

            tmp.clear();
        }

        if (s.empty()) {
            return "/"s;
        }

        string ans;
        while (!s.empty()) {
            ans = "/"s + s.top() + ans;
            s.pop();
        }

        return ans;
    }
};

TEST(&Solution::simplifyPath)