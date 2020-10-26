#include "1365.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    auto expected = toIntArray(params[1]);

    Solution sln;
    auto actual = sln.smallerNumbersThanCurrent(nums);

    AREEQUAL(expected, actual);
}