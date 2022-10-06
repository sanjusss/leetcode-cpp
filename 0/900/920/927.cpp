/*
 * @Author: sanjusss
 * @Date: 2022-10-06 08:22:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-06 08:52:09
 * @FilePath: \0\900\920\927.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int cnt = 0;
        for (int i : arr) {
            if (i == 1) {
                ++cnt;
            }
        }

        if (cnt % 3 != 0) {
            return { -1, -1 };
        }
        else if (cnt == 0) {
            return { 0, 2 };
        }

        auto equal = [&arr](int ab, int ae, int bb, int be) {
            while (ab < ae && arr[ab] == 0) {
                ++ab;
            }

            while (bb < be && arr[bb] == 0) {
                ++bb;
            }

            while (ab < ae && bb < be && arr[ab] == arr[bb]) {
                ++ab;
                ++bb;
            }

            return ab == ae && bb == be;
        };

        int part = cnt / 3;
        int n = arr.size();
        int tail = 0;
        int one = 0;
        int i = n - 1;
        while (one < part) {
            if (arr[i--] == 1) {
                ++one;
            }
            else if (one == 0) {
                ++tail;
            }
        }

        vector<int> ans(2, -1);
        ans[1] = i + 1;
        one = 0;
        int zero = 0;
        while (one < part) {
            if (arr[i--] == 1) {
                ++one;
            }
            else if (one == 0) {
                if (++zero > tail) {
                    --ans[1];
                }
            }
        }

        ans[0] = i;
        if (zero < tail || !equal(ans[0] + 1, ans[1], ans[1], n)) {
            return { -1, -1 };
        }

        zero = 0;
        while (true) {
            if (arr[i--] == 1) {
                break;
            }
            else {
                if (++zero > tail) {
                    --ans[0];
                }
            }
        }

        if (zero < tail || !equal(0, ans[0] + 1, ans[0] + 1, ans[1])) {
            return { -1, -1 };
        }

        return ans;
    }
};