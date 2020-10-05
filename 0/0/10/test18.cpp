/*
 * @Author: sanjusss
 * @Date: 2020-10-05 08:30:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-05 09:10:20
 * @FilePath: \0\0\10\test18.cpp
 */

#include "18.hpp"
#include "unittest.h"

void test_function(const vector<string>& params, int index) {
    auto nums = toIntArray(params[0]);
    int target = stoi(params[1]);
    auto expected = toInt2DArray(params[2]);

    Solution sln;
    auto actual = sln.fourSum(nums, target);

    auto sort2D = [](vector<vector<int>>& arr) {
        for (auto& i : arr) {
            sort(i.begin(), i.end());
        }

        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return to_string(a) < to_string(b);
        });
    };
    sort2D(expected);
    sort2D(actual);
    testCheckEqual(expected, actual);
}

DEFINE_TESTS_SUITE