#include "189_20210108.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int k = stoi(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    sln.rotate(nums, k);

    AREEQUAL(expected, nums);
}