#include "1207.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto arr = toIntArray(params[0]);
    bool expected = stob(params[1]);

    Solution sln;
    bool actual = sln.uniqueOccurrences(arr);

    AREEQUAL(expected, actual);
}