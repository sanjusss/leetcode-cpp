#include "283_20201119.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    auto expected = toIntArray(params[1]);

    Solution sln;
    sln.moveZeroes(nums);
    
    AREEQUAL(expected, nums);
}