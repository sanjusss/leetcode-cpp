#include "135.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto ratings = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.candy(ratings);

    AREEQUAL(expected, actual);
}