#include "134.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto gas = toIntArray(params[0]);
    auto cost = toIntArray(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.canCompleteCircuit(gas, cost);

    AREEQUAL(expected, actual);
}