#include "57.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto intervals = toInt2DArray(params[0]);
    auto newInterval = toIntArray(params[1]);
    auto expected = toInt2DArray(params[2]);

    Solution sln;
    auto actual = sln.insert(intervals, newInterval);

    AREEQUAL(expected, actual);
}