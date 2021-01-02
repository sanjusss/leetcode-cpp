#include "605.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto flowerbed = toIntArray(params[0]);
    int n = stoi(params[1]);
    bool expected = stob(params[2]);

    Solution sln;
    bool actual = sln.canPlaceFlowers(flowerbed, n);

    AREEQUAL(expected, actual);
}