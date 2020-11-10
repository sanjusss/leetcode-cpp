#include "31_20201110.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    auto expected = toIntArray(params[1]);

    Solution sln;
    sln.nextPermutation(nums);

    AREEQUAL(expected, nums);
}