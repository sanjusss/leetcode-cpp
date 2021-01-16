#include "1202.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    auto pairs = toInt2DArray(params[1]);
    string expected = params[2];

    Solution sln;
    string actual = sln.smallestStringWithSwaps(s, pairs);

    AREEQUAL(expected, actual);
}