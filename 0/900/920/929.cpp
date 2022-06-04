/*
 * @Author: sanjusss
 * @Date: 2022-06-04 14:55:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-04 14:59:54
 * @FilePath: \0\900\920\929.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ue;
        for (auto &e : emails) {
            string local;
            bool hasAdd = false;
            string domain;
            for (char i : e) {
                if (i == '@' || domain.empty() == false) {
                    domain.push_back(i);
                }
                else if (i == '+') {
                    hasAdd = true;
                }
                else if (hasAdd == false && i != '.') {
                    local.push_back(i);
                }
            }

            ue.emplace(local + domain);
        }

        return ue.size();
    }
};