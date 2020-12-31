#include "435.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto intervals = toInt2DArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.eraseOverlapIntervals(intervals);

    AREEQUAL(expected, actual);
}