#include "941.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);
    bool expected = stob(params[1]);

    Solution sln;
    bool actual = sln.validMountainArray(A);

    AREEQUAL(expected, actual);
}