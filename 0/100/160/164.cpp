#include "164.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.maximumGap(nums);

    AREEQUAL(expected, actual);
}