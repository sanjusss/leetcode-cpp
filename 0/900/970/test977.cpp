#include "977.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);
    auto expected = toIntArray(params[1]);

    Solution sln;
    auto actual = sln.sortedSquares(A);

    testCheckEqual(expected, actual);
}