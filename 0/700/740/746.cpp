#include "746.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto cost = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.minCostClimbingStairs(cost);

    AREEQUAL(expected, actual);
}