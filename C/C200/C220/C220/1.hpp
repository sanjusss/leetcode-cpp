/*
 * @Author: sanjusss
 * @Date: 2020-12-20 10:34:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-20 10:48:29
 * @FilePath: \C\C200\C220\C220\1.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    string reformatNumber(string number) {
        string nums;
        for (char i : number) {
            if (i >= '0' && i <= '9') {
                nums.push_back(i);
            }
        }

        int end;
        string suffix;
        switch (nums.size() % 3) {
            case 1:
                end = nums.size() - 4;
                suffix = nums.substr(end, 2) + "-" + nums.substr(end + 2);
                break;

            case 2:
                end = nums.size() - 2;
                suffix = nums.substr(end);
                break;

            default:
                end = nums.size();
                break;
        }

        string ans;
        for (int i = 0; i < end; ++i) {
            ans.push_back(nums[i]);
            if (i % 3 == 2) {
                ans.push_back('-');
            }
        }

        ans += suffix;
        if (ans.back() == '-') {
            ans.pop_back();
        }

        return ans;
    }
};