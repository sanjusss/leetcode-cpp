#include "228.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    auto expected = toStringArray(params[1]);

    Solution sln;
    auto actual = sln.summaryRanges(nums);
    AREEQUAL(expected, actual);
}