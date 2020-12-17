#include "714.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto prices = toIntArray(params[0]);
    int fee = stoi(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.maxProfit(prices, fee);

    AREEQUAL(expected, actual);
}