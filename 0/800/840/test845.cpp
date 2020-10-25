#include "845.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.longestMountain(A);

    AREEQUAL(expected, actual);
}