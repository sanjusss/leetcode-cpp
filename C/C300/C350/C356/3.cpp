/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-30 11:06:21
 * @FilePath: \C\C300\C350\C356\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string minimumString(string a, string b, string c) {
        auto minset = [] (const string &a, const string &b) {
            if (a.size() == b.size()) {
                return (a < b) ? a : b;
            }
            else {
                return (a.size() < b.size()) ? a : b;
            }
        };
        string ans = cat(a, b, c);
        ans = minset(ans, cat(a, c, b));
        ans = minset(ans, cat(b, a, c));
        ans = minset(ans, cat(b, c, a));
        ans = minset(ans, cat(c, a, b));
        ans = minset(ans, cat(c, b, a));
        return ans;
    }

private:
    string cat(const string &a, const string &b, const string &c) {
        string res = a;
        cat(res, b);
        cat(res, c);
        return res;
    }

    void cat(string &a, const string &b) {
        if (a.find(b) != string::npos) {
            return;
        }

        int m = a.size();
        int n = min(a.size(), b.size());
        for (int i = n; i > 0; --i) {
            bool success = true;
            for (int j = 0; j < i; ++j) {
                if (a[m - i + j] != b[j]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                a += b.substr(i);
                return;
            }
        }

        a += b;
    }
};

TEST(&Solution::minimumString)