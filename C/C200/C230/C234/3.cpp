/*
 * @Author: sanjusss
 * @Date: 2021-03-28 10:44:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-28 10:50:06
 * @FilePath: \C\C200\C230\C234\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kv;
        for (auto& i : knowledge) {
            kv[i[0]] = i[1];
        }

        string ans;
        string key;
        bool hasLeft = false;
        for (char i : s) {
            if (hasLeft) {
                if (i == ')') {
                    hasLeft = false;
                    auto p = kv.find(key);
                    key.clear();
                    if (p == kv.end()) {
                        ans.push_back('?');
                    }
                    else {
                        for (char j : p->second) {
                            ans.push_back(j);
                        }
                    }
                }
                else {
                    key.push_back(i);
                }
            }
            else {
                if (i == '(')
                {
                    hasLeft = true;
                }
                else {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};