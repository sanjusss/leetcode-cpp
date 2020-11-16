#include "406.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto people = toInt2DArray(params[0]);
    auto expected = toInt2DArray(params[1]);

    Solution sln;
    auto actual = sln.reconstructQueue(people);

    AREEQUAL(expected, actual);
}