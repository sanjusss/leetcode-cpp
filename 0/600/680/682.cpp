/*
 * @Author: sanjusss
 * @Date: 2022-03-26 14:11:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-26 14:19:56
 * @FilePath: \0\600\680\682.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> s;
        for (string& op : ops) {
            if (op == "+"sv) {
               s.push_back(s.back() + s[s.size() - 2]); 
            }
            else if (op == "C"sv) {
                s.pop_back();
            }
            else if (op == "D"sv) {
                s.push_back(s.back() * 2);
            }
            else {
                s.push_back(stoi(op));
            }
        }

        return accumulate(s.begin(), s.end(), 0);
    }
};