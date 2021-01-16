#include "1018.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);
    auto expected = toArray<bool>(params[1]);

    Solution sln;
    auto actual = sln.prefixesDivBy5(A);

    AREEQUAL(expected, actual);
}