#include "1584.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto points = toInt2DArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.minCostConnectPoints(points);

    AREEQUAL(expected, actual);
}