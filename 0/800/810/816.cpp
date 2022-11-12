/*
 * @Author: sanjusss
 * @Date: 2022-11-07 08:52:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-07 09:49:43
 * @FilePath: \0\800\810\816.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        string_view sv = s;
        sv = sv.substr(1, sv.size() - 2);
        int n = sv.size();
        vector<string> ans;
        for (int i = 1; i < n; ++i) {
            auto fs = coords(sv.substr(0, i));
            auto bs = coords(sv.substr(i));
            for (auto& f : fs) {
                for (auto& b : bs) {
                    ans.push_back("("s + f + ", "s + b + ")"s);
                }
            }
        }

        return ans;
    }

private:
    static vector<string> coords(string_view sv) {
        vector<string> res;
        if (sv.size() == 1) {
            res.emplace_back(sv);
        }
        else if (sv.front() == '0') {
            if (sv.back() != '0') {
                res.push_back(string(sv.substr(0, 1)) + "."s + string(sv.substr(1)));
            }
        }
        else {
            res.emplace_back(sv);
            if (sv.back() != '0') {
                int n = sv.size();
                for (int i = 1; i < n; ++i) {
                    res.push_back(string(sv.substr(0, i)) + "."s + string(sv.substr(i)));
                }
            }
        }

        return res;
    }
};