#include "34_20201201.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int target = stoi(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.searchRange(nums, target);

    AREEQUAL(expected, actual);
}