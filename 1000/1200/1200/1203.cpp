#include "1203.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int n = stoi(params[0]);
    int m = stoi(params[1]);
    auto group = toIntArray(params[2]);
    auto beforeItems = toInt2DArray(params[3]);
    auto expected = toIntArray(params[4]);

    Solution sln;
    auto actual = sln.sortItems(n, m, group, beforeItems);

    AREEQUAL(expected, actual);
}