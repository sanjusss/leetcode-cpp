#include "399.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto equations = toString2DArray(params[0]);
    auto values = toArray<double>(params[1]);
    auto queries = toString2DArray(params[2]);
    auto expected = toArray<double>(params[3]);

    Solution sln;
    auto actual = sln.calcEquation(equations, values, queries);

    testCheckEqual(expected, actual, 1e-5);
}