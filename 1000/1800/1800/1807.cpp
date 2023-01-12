/*
 * @Author: sanjusss
 * @Date: 2023-01-12 08:26:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-12 08:33:09
 * @FilePath: \1000\1800\1800\1807.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kv;
        for (auto& kn : knowledge) {
            kv[kn[0]] = kn[1];
        }

        string ans;
        string key;
        bool hasLeft = false;
        for (char i : s) {
            if (i == ')') {
                hasLeft = false;
                if (kv.count(key)) {
                    ans += kv[key];
                }
                else {
                    ans.push_back('?');
                }

                key.clear();
            }
            else if (i == '(') {
                hasLeft = true;
            }
            else if (hasLeft) {
                key.push_back(i);
            }
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};