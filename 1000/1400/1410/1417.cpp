/*
 * @Author: sanjusss
 * @Date: 2022-08-11 08:48:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-11 08:53:37
 * @FilePath: \1000\1400\1410\1417.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reformat(string s) {
        string a;
        string n;
        for (char i : s) {
            if (i >= 'a' && i <= 'z') {
                a.push_back(i);
            }
            else {
                n.push_back(i);
            }
        }

        if (a.size() == n.size() || a.size() == n.size() + 1) {
            swap(a, n);
        }
        else if (a.size() + 1 != n.size()) {
            return ""s;
        }

        string ans;
        while (!n.empty()) {
            ans.push_back(n.back());
            n.pop_back();
            if (!a.empty()) {
                ans.push_back(a.back());
                a.pop_back();
            }
        }

        return ans;
    }
};