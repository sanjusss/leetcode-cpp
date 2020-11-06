#include "1356.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto arr = toIntArray(params[0]);
    auto expected = toIntArray(params[1]);

    Solution sln;
    auto actual = sln.sortByBits(arr);

    AREEQUAL(expected, actual);
}