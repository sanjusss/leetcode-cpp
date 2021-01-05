#include "830.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    auto expected = toInt2DArray(params[1]);

    Solution sln;
    auto actual = sln.largeGroupPositions(s);

    AREEQUAL(expected, actual);
}