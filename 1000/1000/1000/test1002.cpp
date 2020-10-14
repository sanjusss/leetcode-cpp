#include "1002.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toStringArray(params[0]);
    auto expected = toStringArray(params[1]);

    Solution sln;
    auto actual = sln.commonChars(A);

    testCheckEquivalent(expected, actual);
}