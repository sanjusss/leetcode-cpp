/*
 * @Author: sanjusss
 * @Date: 2022-08-06 10:28:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-06 10:31:06
 * @FilePath: \1000\1400\1400\1408.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};