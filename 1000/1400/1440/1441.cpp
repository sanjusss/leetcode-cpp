/*
 * @Author: sanjusss
 * @Date: 2022-10-15 13:26:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-15 13:29:51
 * @FilePath: \1000\1400\1440\1441.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j = 1;
        for (int i : target) {
            ans.push_back("Push"s);
            while (j++ < i) {
                ans.push_back("Pop"s);
                ans.push_back("Push"s);
            }
        }

        return ans;
    }
};