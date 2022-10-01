/*
 * @Author: sanjusss
 * @Date: 2022-10-01 15:07:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-01 15:15:21
 * @FilePath: \1000\1600\1690\1694.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reformatNumber(string number) {
        string ans;
        int cnt = 0;
        for (char i : number) {
            if (i >= '0' && i <= '9') {
                ans.push_back(i);
                ++cnt;
                if (cnt % 3 == 0) {
                    ans.push_back('-');
                }
            }
        }

        if (cnt % 3 == 0) {
            ans.pop_back();
        }
        else if (cnt % 3 == 1) {
            swap(ans[ans.size() - 2], ans[ans.size() - 3]);
        }

        return ans;
    }
};