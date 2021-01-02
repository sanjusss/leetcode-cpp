#include "239_20210102.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int k = stoi(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.maxSlidingWindow(nums, k);

    AREEQUAL(expected, actual);
}