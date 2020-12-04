#include "659.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    bool expected = stob(params[1]);

    Solution sln;
    bool actual = sln.isPossible(nums);

    AREEQUAL(expected, actual);
}