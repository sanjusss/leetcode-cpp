/*
 * @Author: sanjusss
 * @Date: 2021-01-24 11:28:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-24 12:01:33
 * @FilePath: \C\C200\C220\C225\4.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int minimumBoxes(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (canPut(mid, n)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canPut(int bottom, int n) {
        if (bottom >= n) {
            return true;
        }

        if (bottom <= 0) {
            return false;
        }

        static map<int, int> b2l = map<int, int>({ 0, 0 });
        while (bottom > b2l.rbegin()->first) {
            b2l.emplace(b2l.rbegin()->second + 1 + b2l.rbegin()->first, b2l.rbegin()->second + 1);
        }

        auto pos = b2l.lower_bound(bottom);
        return canPut(bottom - pos->second, n - bottom);
    }
};