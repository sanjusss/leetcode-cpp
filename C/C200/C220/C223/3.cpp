#include "3.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto sources = toIntArray(params[0]);
    auto target = toIntArray(params[1]);
    auto allowedSwaps = toInt2DArray(params[2]);
    int expected = stoi(params[3]);

    Solution sln;
    int actual = sln.minimumHammingDistance(sources, target, allowedSwaps);

    AREEQUAL(expected, actual);
}